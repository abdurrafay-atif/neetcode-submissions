class Solution 
{
    public:
        int lengthOfLongestSubstring(string s) 
        {
            int left = 0;
            int longest = 0;
            unordered_set<char> cset;
            for(int right = 0; right < s.length(); right++)
            {
                char c = s[right];
                while(cset.find(c) != cset.end())
                {
                    cset.erase(s[left]);
                    left++;
                }
                cset.insert(c);
                longest = max(right - left + 1, longest);
            }
            return longest;
        }
};
