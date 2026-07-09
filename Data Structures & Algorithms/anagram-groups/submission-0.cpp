class Solution 
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            vector<vector<string>> res;
            for(auto s : strs)
            {
                bool anagram_exists = false;
                for(int i = 0; i < res.size(); i++)
                {
                    if(isAnagram(res[i][0], s))
                    {
                        res[i].push_back(s);
                        anagram_exists = true;
                    }
                }
                if(!anagram_exists)
                {
                    vector<string> new_anagram;
                    new_anagram.push_back(s);
                    res.push_back(new_anagram);
                }
            }
            return res;
        }

        // takeaways:
        // use Map abstract data type for counting items
        bool isAnagram(string s, string t) 
        {
            // if the two strings have unequal length they cannot be anagrams
            if(s.length() != t.length())
            {
                return false;
            }
            // use a HashMap for determining letter counts in both strings
            // this requires O(n) space
            unordered_map<char, int> s_map;
            unordered_map<char, int> t_map;
            // form the s_map
            for(auto c : s)
            {
                if(s_map.find(c) == s_map.end()) // O(1)
                {
                    s_map[c] = 1;
                }
                else
                {
                    s_map[c] = s_map[c] + 1; // O(1)
                }
            }
            // form the t_map... O(n) operation
            for(auto c : t)
            {
                if(t_map.find(c) == t_map.end()) // O(1)
                {
                    t_map[c] = 1;
                }
                else
                {
                    t_map[c] = t_map[c] + 1; // O(1)
                }
            }
            // check that they are equivalent... O(n) operation
            return s_map == t_map;
        }
};
