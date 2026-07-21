class Solution 
{
    public:
        bool checkInclusion(string s1, string s2) 
        {
            // frequency map for s1
            unordered_map<char, int> map1;
            for(auto c : s1)
            {
                map1[c]++;
            }
            int left = 0;                    // left pointer of window
            unordered_map<char, int> map2;   // frequency map for s2
            for(int right = 0; right < s2.length(); right++)
            {
                char c = s2[right];
                // skip characters not in map1
                if(map1.find(c) == map1.end())
                {
                    left = right + 1;
                    map2.clear();
                    continue;
                }
                // update frequency
                map2[c]++;
                // if frequency exceeds, loop until no longer exceeds
                while(map2[c] > map1[c])
                {
                    map2[s2[left]]--;
                    left++;
                }
                // check equality
                if(map1 == map2)
                {
                    return true;
                }
            }
            return false;
        }
};
