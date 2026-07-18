class Solution {
public:
    // sorting solution
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> m;
        for(auto s : strs)
        {
            string key(s);
            sort(key.begin(), key.end());
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
