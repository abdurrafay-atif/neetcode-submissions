class Solution 
{
    public:
        vector<int> countBits(int n) 
        {
            vector<int> count;
            for(int i = 0; i <= n; i++)
            {
                count.push_back(0);
                for(int b = 0; b < 31; b++)
                {
                    count[count.size() - 1] += (1 & (i >> b));
                }
            }
            return count;
        }
};
