class Solution 
{
    public:
        // this function uses sorting technique
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {   
            // hashmap for integer frequency counts
            // usual procedure:
            // 1. If not in map, insert with freq 1
            // 2. If in map, insert with freq increased by 1
            // O(m) space, where m = # of distinct elements
            unordered_map<int, int> mappings;
            // O(n) loop, n = # of elements in nums, HashSet functions O(1)
            for(auto i : nums)
            {
                if(mappings.find(i) == mappings.end())
                {
                    mappings.insert({i, 1});
                }
                else
                {
                    mappings[i]++;
                }
            }
            // obtain all freq-val pairs
            vector<pair<int, int>> freqs;
            for(auto i : mappings)
            {
                freqs.push_back({i.second, i.first});
            }   
            // sort the frequencies in descending order
            sort(freqs.begin(), freqs.end(), greater<>());
            // obtain k most frequent elements
            vector<int> res;
            for(int i = 0; i < k; i++)
            {
                res.push_back(freqs[i].second);
            }
            return res;
        }     
};
