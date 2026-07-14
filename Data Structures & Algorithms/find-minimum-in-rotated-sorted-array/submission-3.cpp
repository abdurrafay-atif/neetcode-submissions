class Solution 
{
    public:
        int findMin(vector<int> &nums) 
        {
            // edge case: rotated array is same as original
            if(nums[0] <= nums[nums.size() - 1])
            {
                return nums[0];
            }
            int left = 0;                   // left pointer for binary search
            int right = nums.size();        // right pointer for binary search
            int minimum = INT_MAX;          // tracking minimum element
            // loop until pointers meet
            while(left < right)
            {
                int mid = left + (right - left) / 2;
                // if first element is subsection is smaller than last element
                // this is the minimum (based on problem description)
                if(right < nums.size() && nums[left] < nums[right])
                {
                    return nums[left];
                }
                // if the left element is smaller than middle element
                // minimum must be on right side of array 
                else if(nums[left] < nums[mid])
                {
                    left = mid;
                }
                // if left element larger (or equal) than middle element
                // minimum is on left side of array
                else
                {
                    right = mid;
                }
                // re-calculate minimum after current iteration
                minimum = min(nums[mid], minimum);
            }
            // return whatever minimum was found if loop above breaks
            return minimum;
        }
};
