class Solution 
{
    public:
        vector<int> productExceptSelf(vector<int>& nums) 
        {
            // form prefix products (except self)
            vector<int> prefix(nums.size());
            prefix[0] = 1;
            for(int i = 1; i < nums.size(); i++)
            {
                prefix[i] = nums[i - 1] * prefix[i - 1];
            }
            // form suffix products
            vector<int> suffix(nums.size());
            suffix[nums.size() - 1] = 1;
            for(int i = nums.size() - 2; i >= 0; i--)
            {
                suffix[i] = nums[i + 1] * suffix[i + 1];
            }
            // obtain product except self
            // this is the product of the prefix & suffix
            // this will lead to product of all except self
            // due to the commutative nature of the product operation
            vector<int> res(nums.size());
            for(int i = 0; i < nums.size(); i++)
            {
                res[i] = prefix[i] * suffix[i];
            }
            return res;
        }
};
