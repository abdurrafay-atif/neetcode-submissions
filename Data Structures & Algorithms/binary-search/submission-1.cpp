class Solution 
{
    public:
        int search(vector<int>& nums, int target) 
        {
            // pointers for left and right ends of array
            // these will shrink the bounds at every iteration
            int left = 0;
            int right = nums.size();
            // loop until pointers meet
            while(left <= right)
            {
                // calculate middle index of array
                int middle = left + ((right - left) / 2);
                // if element at this index search is done
                if(nums[middle] == target)
                {
                    return middle;
                }
                // if element small compared to target eliminate left half of array
                // this is done by moving left index to index after mid
                else if(nums[middle] < target)
                {
                    left = middle + 1;
                }
                // if element big compared to target eliminate right half of array
                // this is done by moving right index to index before mid
                else
                {
                    right = middle - 1;
                }
            }
            // if element not found return -1 to indicate such
            return -1;
        }
};
