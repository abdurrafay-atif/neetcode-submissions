class Solution 
{
    public:
        string minWindow(string s, string t) 
        {
            // build frequency map of t
            unordered_map<char, int> tmap;
            for(auto c : t)
            {
                tmap[c]++;
            }
            int left = 0;                       // left pointer
            unordered_map<char, int> smap;      // frequency map of s
            int num_match = 0;                  // keep track of # of frequency matches
            bool sub_exists = false;            // indicates that t character map is in s
            int left_res = -1;                  // result left index of substring
            int right_res = -1;                 // result right index of substring
            int shortest = INT_MAX;             // length of shortest substring seen so far
            for(int right = 0; right < s.length(); right++)
            {
                char c = s[right];
                // update smap if character is in tmap
                if(tmap.find(c) != tmap.end())
                {
                    smap[c]++;
                }
                else    // ignore any other character
                {
                    continue;
                }
                // check if frequencies match in both maps
                // if so increment num_matches 
                // this only increments when finding substring
                if(smap[c] == tmap[c])
                {
                    num_match++;
                }
                // check if all character frequencies have matched
                // this indicates that substring has been found
                if(num_match == tmap.size())
                {
                    sub_exists = true;
                }
                // shrink window size until substring no longer exists
                // then keep left at position where substring can exist
                // only runs if the substring has been proven to eixst
                while(sub_exists)
                {
                    char cl = s[left]; // character at left end
                    // if character not in tmap automatically increment
                    if(!tmap[cl])
                    {
                        left++;
                    }
                    // if character in tmap & frequency in smap exceeds tmap
                    // we can decrement the count here and move left
                    else if(smap[cl] > tmap[cl])
                    {
                        smap[cl]--;
                        left++;
                    }
                    else    // else we cannot decrement, left pointer stays here
                    {
                        break;
                    }
                }
                // update shortest if substring was found
                if(sub_exists && (right - left + 1) < shortest)
                {
                    left_res = left;
                    right_res = right;
                    shortest = right - left + 1;
                }
                cout << s.substr(left, right - left + 1) << "\n";
            }
            // if the substring doesn't exist (based on bool) return ""
            // otherwise return substring based on pointers we kept track of
            return sub_exists ? s.substr(left_res, right_res - left_res + 1) : "";
        }
};
