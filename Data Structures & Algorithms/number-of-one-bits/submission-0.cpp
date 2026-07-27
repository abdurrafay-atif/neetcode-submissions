class Solution 
{
    public:
        int hammingWeight(uint32_t n) 
        {
            int count = 0;
            for(int b = 0; b < 31; b++)
            {
                count += (1 & (n >> b));
            }
            return count;
        }
};
