class Solution 
{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            // hashmap for integer frequency counts
            // usual procedure:
            // 1. If not in map, insert with freq 1
            // 2. If in map, insert with freq increased by 1
            // O(m) space, where m = # of distinct elements
            unordered_map<int, int> int_freqs;
            int max_freq = 0; // used to obtain max frequency for forming buckets
            // O(n) loop, n = # of elements in nums, HashSet functions O(1)
            for(auto i : nums)
            {
                if(int_freqs.find(i) == int_freqs.end())
                {
                    int_freqs.insert({i, 1});
                }
                else
                {
                    int_freqs[i]++;
                }
                if(max_freq < int_freqs[i])
                {
                    max_freq = int_freqs[i];
                }
            }
            // form buckets
            vector<vector<int>> buckets(max_freq + 1);
            for(auto i : int_freqs)
            {
                buckets[i.second].push_back(i.first);
            }
            // pick top k elements by looping through buckets in backward order
            vector<int> res;
            int count = 0;
            while(1)
            {
                for(int i = buckets.size() - 1; i >= 0; i--)
                {
                    for(int j = buckets[i].size() - 1; j >= 0; j--)
                    {
                        res.push_back(buckets[i][j]);
                        count++;
                        if(count >= k)
                        {
                            return res;
                        }
                    }
                }
            }
            return res;
        }
};
