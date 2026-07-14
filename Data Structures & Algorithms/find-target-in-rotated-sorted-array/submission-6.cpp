class Solution 
{ 
    public:
        // time complexity: O(log n)
        // space complexity: O(1)
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
                // if the target matches the middle element
                // the element has been found, return its index
                if(target == nums[mid])
                {
                    return mid;
                }
                // integer for three quantities necessary for determining placement
                // bit 1: nums[left] > nums[mid]
                // bit 2: target > nums[left]
                // bit 3: target > nums[mid]
                int move_check = 0;
                move_check |= (nums[left] >= nums[mid]);
                move_check |= ((target >= nums[left]) << 1);
                move_check |= ((target >= nums[mid]) << 2);
                cout << move_check << "\n";
                // use a switch statement to determine movements
                switch(move_check)
                {
                    case 0: 
                        left = mid + 1;
                        break;
                    case 1: 
                        right = mid - 1;
                        break;
                    case 2: 
                        right = mid - 1;
                        break;
                    case 3: 
                        left = mid + 1;
                        break;
                    case 4: 
                        right = mid - 1;
                        break;
                    case 5: 
                        left = mid + 1;
                        break;
                    case 6: 
                        left = mid + 1;
                        break;
                    case 7: 
                        right = mid - 1;
                        break;
                }
            }
            // if target was not found indicate so with index -1 (not an index)
            return -1;
        }
};
