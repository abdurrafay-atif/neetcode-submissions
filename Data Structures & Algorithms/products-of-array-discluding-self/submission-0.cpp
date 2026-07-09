class Solution 
{
public:
    // brute force solution
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res;
        // loop through all indices of result array
        // calculate product of all numbers except self
        for(int i = 0; i < nums.size(); i++)
        {
            // add new element to array for this run
            res.push_back(1);
            // calculate product of all numbers except current
            // this is handled by if condition
            for(int j = 0; j < nums.size(); j++)
            {
                if(i != j)
                {
                    res[i] *= nums[j];
                }
            }
        }
        return res;
    }
};
