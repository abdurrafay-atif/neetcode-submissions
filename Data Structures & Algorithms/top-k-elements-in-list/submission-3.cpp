class Solution 
{
    public:
        // this function uses min-heap technique
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
            // obtain all freq-val pairs, place into priority queue
            // need to use a min-heap (C++ requires special syntax for this)
            // the min-heap means smallest element always popped with .pop()
            // so this allows only the greatest values to remain...
            // as long as things are popped when reaching max length
            // the order doesn't matter, just need top k in any order
            priority_queue<pair<int, int>, 
                vector<pair<int, int>>, 
                greater<pair<int, int>>> freqs;
            for(auto i : mappings)
            {
                freqs.push({i.second, i.first});
                if(freqs.size() > k)
                {
                    freqs.pop();
                }
            }   
            // obtain k most frequent elements
            vector<int> res;
            for(int i = 0; i < k; i++)
            {
                res.push_back(freqs.top().second);
                freqs.pop();
            }
            return res;
        }     
};
