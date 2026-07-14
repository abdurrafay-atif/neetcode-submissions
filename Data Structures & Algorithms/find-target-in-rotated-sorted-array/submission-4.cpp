class Solution 
{ 
    public:
        int search(vector<int>& nums, int target) 
        {
            // edge case, 1 element in array
            if(nums.size() == 1)
            {
                return nums[0] == target ? 0 : -1;
            }
            // two pointers for binary search
            int left = 0;
            int right = nums.size() - 1;
            // loop until pointers meet
            while(left <= right)
            {
                // check if left / right elements are the target
                // if so return them 
                if(nums[left] == target)
                {
                    return left;
                }
                if(nums[right] == target)
                {
                    return right;
                }
                // calculate middle element
                int mid = left + (right - left) / 2;
                cout << left << " : " << right << " : " << mid << " ";
                // if the target matches the middle element
                // the element has been found, return its index
                if(target == nums[mid])
                {
                    return mid;
                }
                // case where target is greater than left element
                else if(target < nums[mid])
                {
                    if(target < nums[left])
                    {
                        if(nums[left] < nums[mid])
                        {
                            cout << "HELLO1\n";
                            left = mid + 1;
                        }
                        else
                        {
                            cout << "HELLO2\n";
                            right = mid - 1;
                        }
                    }
                    else
                    {
                        if(nums[left] < nums[mid])
                        {
                            cout << "HELLO3\n";
                            right = mid - 1;
                        }
                        else
                        {
                            cout << "HELLO4\n";
                            left = mid + 1;
                        }
                    }
                }
                else
                {
                    if(target < nums[left])
                    {
                        if(nums[left] < nums[mid])
                        {
                            cout << "HELLO5\n";
                            right = mid - 1;
                        }
                        else
                        {
                            cout << "HELLO6\n";
                            left = mid + 1;
                        }
                    }
                    else
                    {
                        if(nums[left] < nums[mid])
                        {
                            cout << "HELLO7\n";
                            left = mid + 1;
                        }
                        else
                        {
                            cout << "HELLO8\n";
                            right = mid - 1;
                        }
                    }
                }
            }
            // if target was not found indicate so with index -1 (not an index)
            return -1;
        }
};
