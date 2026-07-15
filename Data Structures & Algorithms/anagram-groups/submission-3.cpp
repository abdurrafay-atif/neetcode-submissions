class Solution 
{
    public:
        // sorting solution
        // time complexity: O(m * nlogn), m = # of strings, n = length of longest string
        // space complexity: O(m), m = # of strings
        vector<vector<string>> groupAnagrams(vector<string>& strs) 
        {
            // grouping map between all unique strings and all anagrams of that string
            unordered_map<string, vector<string>> groups;
            for(auto s : strs)
            {
                // sort string 
                string sorted(s);
                sort(sorted.begin(), sorted.end());
                // place into map if it doesn't exist
                if(groups.find(s) == groups.end())
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
