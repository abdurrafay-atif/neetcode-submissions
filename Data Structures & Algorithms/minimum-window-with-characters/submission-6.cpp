class Solution 
{
    public:
        // brute force solution
        // time complexity: O(n^2), n = # of characters in s
        // space complexity: O(m), m = # of unique characters in t
        string minWindow(string s, string t) 
        {
            // build frequency map for string t
            unordered_map<char, int> tmap;
            for(auto c : t)
            {
                tmap[c] = tmap.find(c) == tmap.end() ? 1 : tmap[c] + 1;
            }
            int left = 0;                   // left pointer
            // loop until first character in t appears in s
            // first character in minWindow must be in s
            for(auto c : s)
            {
                if(tmap.find(c) != tmap.end())
                {
                    break;
                }
                left++;
            } 
            unordered_map<char, int> smap;  // string s frequency map
            int num_matches = 0;            // # of character freqs which matched so far
            bool valid_match = false;       // variable determining if maps were equivalent once
            int res_left = -1;              // resulting left index
            int res_right = -1;             // resulting right index
            int shortest = INT_MAX;         // window size 
            // loop through s string (right pointer)
            for(int right = left; right < s.length(); right++)
            {
                // extract current character at right end of window
                char c = s[right];
                // check if character in tmap (since we are only considering those characters)
                // if not, skip over it and move on to next iteration of loop
                if(tmap.find(c) == tmap.end())
                {
                    continue;
                }
                // update smap frequency count to account for s[right]
                smap[c] = smap.find(c) == smap.end() ? 1 : smap[c] + 1;
                // if smap freq matches tmap freq, increment corresponding variable
                if(smap[c] == tmap[c])
                {
                    num_matches++;
                }
                // if all character freqs match, there is a window with substring
                // thus, update valid_match to be true (this means result won't be "")
                // valid_match = true means left pointer can start moving forward
                if(num_matches == tmap.size())
                {
                    valid_match = true;
                }
                // move left pointer to minimize window substring if all characters in t found
                // more details are discussed within the conditional statement
                if(valid_match)
                {
                    // loop which runs until meets right (window cannot exceed right)
                    while(left < right)
                    {
                        // extract character at left end of window
                        char cleft = s[left];
                        // conditions for incrementing pointer:
                        // 1. item is not in tmap
                        // 2. item freq in smap exceeds tmap
                        // if item has equivalent freq as tmap, break out of loop
                        // this is where beginning of window will now begin
                        // this is because removing that item will cause...
                        // window to no longer contain all characters in substring
                        if(tmap.find(cleft) == tmap.end())
                        {
                            left++;
                        }
                        else if(smap[cleft] > tmap[cleft])
                        {
                            smap[cleft]--;
                            left++;
                        }
                        else if(smap[cleft] == tmap[cleft])
                        {
                            break;
                        }
                    }
                    // check that substring length is shorter than previous shortest length
                    // if so update result variables to reflect this
                    if((right - left) < shortest)
                    {
                        res_left = left;
                        res_right = right;
                        shortest = res_right - res_left;
                    }
                }
            }
            // if no valid substrings were found, return ""
            // otherwise, return substring between indices left & right
            // note: C++ substr() function works differently from Java function
            // C++ function: s.substr(start, # of characters to print from start)
            return valid_match ? s.substr(res_left, res_right - res_left + 1) : "";
        }
};
