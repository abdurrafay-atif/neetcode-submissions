class Solution 
{
    public:
        // priority queue solution
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            unordered_map<int, int> freqs;
            for(auto i : nums)
            {
                freqs[i] = freqs.find(i) == freqs.end() ? 1 : freqs[i] + 1;
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
            for(auto i : freqs)
            {
                p.push({i.second, i.first});
                if(p.size() > k)
                {
                    p.pop();
                }
            }
            vector<int> res;
            while(!p.empty())
            {
                res.push_back(p.top().second);
                p.pop();
            }
            return res;
        }
};
