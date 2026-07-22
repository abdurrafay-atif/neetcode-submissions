class Solution 
{
    public:
        int findMin(vector<int> &nums) 
        {
            int left = 0;
            int right = nums.size() - 1;
            int minimum = INT_MAX;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                minimum = min({nums[left], nums[mid], nums[right]});
                // if leftmost is smaller than mid and rightmost bigger than mid
                // this could only be possible if leftmost is minimum
                // this is due to sorted nature of rotated array
                if(nums[left] <= nums[mid] && nums[mid] <= nums[right])
                {
                    return nums[left];
                }
                // if both are smaller, eliminate left half
                // cannot be within any of those elements
                else if(nums[left] <= nums[mid] && nums[right] <= nums[mid])
                {
                    left = mid + 1;
                }
                // if both are bigger (only other case), eliminate right half
                else
                {
                    right = mid;
                }
            }
            return minimum;
        }
};
