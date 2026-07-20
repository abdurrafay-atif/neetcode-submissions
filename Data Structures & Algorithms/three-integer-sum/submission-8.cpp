class Solution 
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) 
        {
            // result vector
            vector<vector<int>> res;
            // sort in order to use two pointers
            sort(nums.begin(), nums.end());
            // loop through i-index
            // use same 2P loop as in 2Sum Sorted
            for(int i = 0; i < nums.size(); i++)
            {
                // make nums[i] always unique by incrementing whenever duplicates appear
                if(i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int j = i + 1;              // left pointer, never intersects with i
                int k = nums.size() - 1;    // right pointer, never intersects with i
                while(j < k)                // loop prevents k & j from meeting
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(0 == sum)
                    {
                        res.push_back({nums[i], nums[j], nums[k]});
                        // prevent duplicate nums[j]
                        // loop prevents j == k
                        do
                        {
                            j++;
                        }
                        while(j < k && nums[j] == nums[j - 1]);
                    }
                    else if(0 < sum)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
            }
            return res;
        }
};
