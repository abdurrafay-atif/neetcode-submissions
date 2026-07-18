class Solution {
public:
    // O(m * n) sorting solution
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> m;
        for(auto s : strs)
        {
            unordered_map<char, int> freqs;
            for(auto c : s)
            {
                freqs[c] = freqs.find(c) == freqs.end() ? 1 : freqs[c] + 1;
            }
            string key;
            for(char c = 'a'; c <= 'z'; c++)
            {
                if(freqs.find(c) != freqs.end())
                {
                    key.append(string(freqs[c], c));
                }
            }
            if(m.find(key) == m.end())
            {
                m.insert({key, vector<string>{}});
            }
            m[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto i : m)
        {
            res.push_back(i.second);
        }
        return res;
    }
};
