class TimeMap 
{
    private:
        unordered_map<string, vector<pair<int, string>>> store;

    public:
        TimeMap() 
        {
        
        }
        
        void set(string key, string value, int timestamp) 
        {
            // update map if key not in there
            if(store.find(key) == store.end())
            {
                store.insert({key, vector<pair<int, string>> {}});
            }
            // push value-timestamp pair to associated key list
            store[key].push_back({timestamp, value});
        }
        
        string get(string key, int timestamp) 
        {
            // edge case, key not in map or timestamp is too low
            if(store.find(key) == store.end() || timestamp < store[key][0].first)
            {
                return "";
            }
            // extract list
            vector<pair<int, string>> vals = store[key];
            // search list
            int left = 0;
            int right = vals.size() - 1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(vals[mid].first <= timestamp)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            return vals[left - 1].second;
        }
};
