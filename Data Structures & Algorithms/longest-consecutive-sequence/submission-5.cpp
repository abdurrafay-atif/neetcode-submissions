class Solution 
{
    public:
        int longestConsecutive(vector<int>& nums) 
        {
            unordered_set<int> s(nums.begin(), nums.end());
            int longest = 0;
            for(auto i : nums)
            {
                if(s.find(i - 1) == s.end())
                {
                    int count = 1;
                    while(s.find(i + 1) != s.end())
                    {
                        i++;
                        count++;
                    }
                    longest = max(count, longest);
                }
            }
            return longest;
        }
};
