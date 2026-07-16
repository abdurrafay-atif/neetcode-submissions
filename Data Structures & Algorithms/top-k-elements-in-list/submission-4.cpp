class Solution 
{
    public:
        // time complexity: O(n)
        // space complexity: O(n)
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            // obtain frequency mapping & upper bound to bucket array
            unordered_map<int, int> freqs;
            int max_freq = 0;
            for(auto i : nums)
            {
                freqs[i] = freqs.find(i) == freqs.end() ? 1 : freqs[i] + 1;
                max_freq = max(freqs[i], max_freq);
            }
            // form bucket array consisting of values & frequencies
            vector<vector<int>> buckets(max_freq + 1);
            for(auto i : freqs)
            {
                buckets[i.second].push_back(i.first);
            }
            // loop backwards in buckets array until obtained top K frequencies
            vector<int> res;
            int num_taken = 0;
            while(1)
            {
                for(int i = buckets.size() - 1; i >= 0; i--)
                {
                    for(int j = 0; j < buckets[i].size(); j++)
                    {
                        res.push_back(buckets[i][j]);
                        // check that enough elements have been placed in array
                        if(++num_taken >= k)
                        {
                            return res;
                        }
                    }
                }
            }
            return res;
        }
};
