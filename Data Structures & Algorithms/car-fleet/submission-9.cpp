class Solution 
{
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) 
        {
            // bucket sort on position-speed pairs
            // time complexity: O(m), m = target
            vector<pair<int, int>> buckets(target);
            for(int i = 0; i < position.size(); i++)
            {
                buckets[position[i]] = {position[i], speed[i]};
            }
            vector<pair<int, int>> sorted;
            for(auto i : buckets)
            {
                if(i.second != 0) // speed cannot be 0
                {
                    sorted.push_back(i);
                }
            }
            // stack solution
            stack<pair<int, int>> st;
            for(auto i : sorted)
            {
                while(!st.empty())
                {
                    double curr_time = (target - i.first) / (double) i.second;
                    double prev_time = (target - st.top().first) / (double) st.top().second;
                    if(prev_time <= curr_time)
                    {
                        st.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                st.push({i.first, i.second});
            }
            return st.size();
        }
};
