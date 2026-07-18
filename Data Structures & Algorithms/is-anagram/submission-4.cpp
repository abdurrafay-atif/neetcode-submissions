class Solution 
{
    public:
        bool isAnagram(string s, string t) 
        {
            // obtain frequency map of s
            unordered_map<char, int> smap;
            for(auto c : s)
            {
                smap[c] = smap.find(c) == smap.end() ? 1 : smap[c] + 1;
            }
            // obtain frequency map of t
            unordered_map<char, int> tmap;
            for(auto c : t)
            {
                tmap[c] = tmap.find(c) == tmap.end() ? 1 : tmap[c] + 1;
            }
            // check if frequency maps are equal
            // if so this means their character frequencies nare equal
            // even if the order is different, they have same # of characters
            // which is definition of anagram
            return smap == tmap;
        }
};
