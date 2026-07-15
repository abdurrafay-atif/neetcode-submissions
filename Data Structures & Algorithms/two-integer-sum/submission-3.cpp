class Solution 
{
    public:
        // time complexity: O(n)
        // space complexity: O(n) due to HashMap usage
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> res;            // result vector
            unordered_map<int, int> m;  // hashmap for val-index pairs
            // loop to go through each element of nums for verification
            for(int i = 0; i < nums.size(); i++)
            {
                // if a value that sums current with itself equals target
                // two sum has been found, return it
                if(m.find(target - nums[i]) != m.end())
                {
                    res.push_back(m[target - nums[i]]);
                    res.push_back(i);
                    break;
                }
                // add to the set so it can be checked in the future
                // add index as the problem requires indices
                m[nums[i]] = i;
            }
            return res;
        }
};
