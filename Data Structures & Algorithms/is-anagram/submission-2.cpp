class Solution 
{
    public:
        // time complexity: O(n), n = max(len(s), len(t))
        // space complexity: O(m), m = max(uniques in s, uniques in t)
        bool isAnagram(string s, string t) 
        {
            // if strings are not the same length they cannot be anagrams
            if(s.length() != t.length())
            {
                return false;
            }
            // obtain balanced frequency map between s & t strings
            unordered_map<char, int> m;           
            for(int i = 0; i < s.length(); i++)
            {
                // extract current character from both s & t
                char sc = s[i];
                char tc = t[i];
                // add 1 to frequency map if in s
                // subtract 1 to frequency map if in t
                // ensure character is in frequency map prior to updating
                m[sc] = m.find(sc) == m.end() ? 1 : m[sc] + 1;
                m[tc] = m.find(tc) == m.end() ? -1 : m[tc] - 1;
            }
            // loop through map and check that all frequency counts are 0
            // meaning s & t character frequencies balance out
            // if one is not 0 that means one does not balance, thus not being anagram
            for(auto i : m)
            {
                if(i.second != 0)
                {
                    return false;
                }
            }
            // all frequencies checked, thus the two strings are anagrams
            return true;
        }
};
