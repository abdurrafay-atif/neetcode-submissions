class Solution 
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) 
        {
            // sorting array is fine because time complexity...
            // already O(n^2)
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            for(int i = 0; i < nums.size(); i++)
            {
                // no need to continue if all upcoming values are positive
                if(nums[i] > 0)
                {
                    break;
                }
                // prevent duplicate nums[i]
                if(i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int j = i + 1;              // prevents j = i
                int k = nums.size() - 1;
                while(j < k)                // prevents j = k
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0)
                    {
                        res.push_back(vector<int> {nums[i], nums[j], nums[k]});
                        // prevents duplicate nums[j]
                        // also prevents j = k
                        do
                        {
                            j++;
                        }
                        while(j < k && nums[j] == nums[j - 1]); 
                    }
                    else if(sum < 0)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
            return res;
        }
};
