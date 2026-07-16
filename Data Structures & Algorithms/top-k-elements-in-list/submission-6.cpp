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
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> topk;
            for(auto i : freqs)
            {
                topk.push({i.second, i.first});
                if(topk.size() > k)
                {
                    topk.pop();
                }
            }
            vector<int> res;
            while(!topk.empty())
            {
                res.push_back(topk.top().second);
                topk.pop();
            }   
            return res;
        }
};
