class Solution 
{
    public:
        int longestConsecutive(vector<int>& nums) 
        {
            unordered_set<int> s;
            for(auto i : nums)
            {
                s.insert(i);
            }
            int longest = 0;
            while(!s.empty())
            {
                int start = *s.begin();
                int inc = start;
                int dec = start;
                int length = 1;
                while(s.find(inc + 1) != s.end())
                {   
                    inc++;
                    s.erase(inc);
                    length++;
                }
                while(s.find(dec - 1) != s.end())
                {
                    dec--;
                    s.erase(dec);
                    length++;
                }
                s.erase(start);
                longest = max(length, longest);
            }
            return longest;
        }
};
