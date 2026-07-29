class Solution 
{
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
        {
            // find points
            priority_queue<pair<double, vector<int>>> pqueue;
            for(auto i : points)
            {
                int x = i[0];
                int y = i[1];
                double dist = sqrt(pow(x, 2) + pow(y, 2));
                pqueue.push({dist, i});
                if(pqueue.size() > k)
                {
                    pqueue.pop();
                } 
            }
            // place in vector
            vector<vector<int>> res;
            while(!pqueue.empty())
            {
                res.push_back(pqueue.top().second);
                pqueue.pop();
            }
            return res;
        }
};
