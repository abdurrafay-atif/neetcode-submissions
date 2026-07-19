class Solution 
{
    public:
        // sorting solution
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            unordered_map<int, int> freqs;
            for(auto i : nums)
            {
                freqs[i] = freqs.find(i) == freqs.end() ? 1 : freqs[i] + 1;
            }
            vector<vector<int>> buckets(nums.size() + 1);
            for(auto i : freqs)
            {
                buckets[i.second].push_back(i.first);
            }
            vector<int> res;
            for(int i = buckets.size() - 1; i >= 0; i--)
            {
                for(int j = 0; j < buckets[i].size(); j++)
                {
                    res.push_back(buckets[i][j]);
                    if(res.size() >= k)
                    {
                        return res;
                    }
                }
            }
            return res;
        }
};
