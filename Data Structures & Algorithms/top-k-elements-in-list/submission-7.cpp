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
            vector<pair<int, int>> sorted;
            for(auto i : freqs)
            {
                sorted.push_back({i.second, i.first});
            }
            sort(sorted.begin(), sorted.end(), greater<>());
            vector<int> res;
            for(int i = 0; i < k; i++)
            {
                res.push_back(sorted[i].second);
            }
            return res;
        }
};
