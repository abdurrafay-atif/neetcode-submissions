class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // to be returned
        vector<int> res;
        // map consisting of value-index pairs
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            // check that map consists of correct sum to target
            if(map.find(target - nums[i]) != map.end())
            {
                res.push_back(map[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};
