class Solution 
{
    public:
        // brute force solution
        // time complexity: O(n * k), n = # of elements in nums
        // space complexity: O(1), not including result vector
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            vector<int> maximums;
            for(int left = 0; left <= nums.size() - k; left++)
            {
                int maximum = INT_MIN;
                for(int right = left; right < left + k; right++)
                {
                    maximum = max(nums[right], maximum);
                }
                maximums.push_back(maximum);
            }
            return maximums;
        }
};
