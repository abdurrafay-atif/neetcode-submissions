class Solution 
{
public:
    // solution using prefix / suffix array
    // prefix consists of product of all elements < index
    // suffix consists of product of all elements > index
    // prefix * suffix --> product of array except self
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // calculate prefix sum
        vector<int> prefix(nums.size());
        prefix[0] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        // calculate postfix sum
        vector<int> postfix(nums.size());
        postfix[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }
        // combine the results
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++)
        {
            res[i] = prefix[i] * postfix[i];
        }
        return res;
    }
};
