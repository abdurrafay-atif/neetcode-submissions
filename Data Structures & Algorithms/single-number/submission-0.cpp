class Solution 
{
    public:
        int singleNumber(vector<int>& nums) 
        {
            int i = 0;
            for(auto n : nums)
            {
                i ^= n;
            }
            return i;
        }
};
