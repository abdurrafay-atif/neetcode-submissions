class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            unordered_map<int, int> s;
            for(int i = 0; i < nums.size(); i++)
            {
                if(s.find(target - nums[i]) != s.end())
                {
                    return vector<int> {s[target - nums[i]], i};
                }
                s[nums[i]] = i;
            }
            return vector<int>{};
        }
};
