class Solution 
{
    public:
        // 
        // time complexity: O(m * n), m = # of strings, n = length of longest string
        // space complexity: O(m), m = # of strings
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            // grouping map between all unique strings and all anagrams of that string
            unordered_map<string, vector<string>> groups;
            for(auto s : strs)
            {
                // obtain frequency map of this string
                unordered_map<char, int> freqs;
                for(auto c : s)
                {
                    freqs[c] = freqs.find(c) == freqs.end() ? 1 : freqs[c] + 1;
                }
                // place characters in frequency map in sorted order
                string sorted;
                for(char c = 'a'; c <= 'z'; c++)
                {
                    int freq = freqs.find(c) == freqs.end() ? 0 : freqs[c];
                    for(int i = 0; i < freq; i++)
                    {
                        sorted.push_back(c);
                    }
                }
                // place into map if it doesn't exist
                if(groups.find(sorted) == groups.end())
                {
                    vector<string> new_group;
                    groups.insert({sorted, new_group});
                }
                // add current string into associated group
                groups[sorted].push_back(s);
            }
            // form vector out of groupings
            vector<vector<string>> res;
            for(auto i : groups)
            {
                res.push_back(i.second);
            }
            return res;
        }
};
