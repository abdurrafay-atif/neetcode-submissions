class Solution 
{
    public:
        // prefix / suffix products solution
        vector<int> productExceptSelf(vector<int>& nums) 
        {
            // precompute partial products
            int n = nums.size();
            vector<int> prefix(n);
            vector<int> suffix(n);
            prefix[0] = 1;
            suffix[n - 1] = 1;
            for(int i = 1; i < nums.size(); i++)
            {
                prefix[i] = nums[i - 1] * prefix[i - 1];
                suffix[n - i - 1] = nums[n - i] * suffix[n - i];
            }
            // multiply partial products for each index
            vector<int> res(n);
            for(int i = 0; i < nums.size(); i++)
            {
                res[i] = prefix[i] * suffix[i];
            }
            return res;
        }
};
