class Solution 
{
    public:
        // brute force solution
        string minWindow(string s, string t) 
        {
            // build frequency map for string t
            unordered_map<char, int> tmap;
            for(auto c : t)
            {
                tmap[c] = tmap.find(c) == tmap.end() ? 1 : tmap[c] + 1;
            }
            int res_left = -1;
            int res_right = -1;
            int shortest = INT_MAX;
            // nested loop for all possible substrings
            for(int left = 0; left < s.length(); left++)
            {
                // build frequency mapping for string s
                // frequency mapping only contains characters in t
                unordered_map<char, int> smap;
                for(int right = left; right < s.length(); right++)
                {
                    // current character
                    char c = s[right];
                    // update smap if t contains this character
                    if(tmap.find(c) != tmap.end())
                    {
                        // if smap didn't track this character yet, add it to the map
                        if(smap.find(c) == smap.end())
                        {
                            smap[c] = 0;
                        }
                        // if smap freq is less than tmap freq, increment the count
                        // otherwise stays same to prevent over-counting
                        if(smap[c] < tmap[c])
                        {
                            smap[c]++;
                        }
                    }
                    // check if map is equivalent to tmap
                    // this means this substring contains all characters in t
                    // thus this substring satisfies the problem statatement
                    // update variables to indicate positions & length if needed
                    // check length satisfies first before checking map
                    // this is due to former check being faster to rule out
                    if((right - left) < shortest && smap == tmap)
                    {
                        res_left = left;
                        res_right = right;
                        cout << s.substr(res_left, res_right - res_left + 1) << "\n";
                        shortest = res_right - res_left;
                    }
                }
            }
            // if no valid substrings were found, return ""
            // otherwise, return substring between indices left & right
            // note: C++ substr() function works differently from Java function
            // C++ function: s.substr(start, # of characters to print from start)
            return res_left == -1 ? "" : s.substr(res_left, res_right - res_left + 1);
        }
};
