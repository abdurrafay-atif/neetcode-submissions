class TimeMap 
{
    private: 
        // map data structure for the TimeMap class
        // key is the key string 
        // value is a vector consisting of a list of pairs
        // these pairs are <int, string>, where int = timestamp, string = value
        // O(m * n) space complexity
        // m = # of keys
        // n = max # of values associated with a key
        unordered_map<string, vector<pair<int, string>>> timemap;
    public:
        TimeMap() 
        {
            
        }
        
        // O(1) time complexity
        void set(string key, string value, int timestamp) 
        {
            // check if the key is not already in the map
            // if so add it and insert new vector into it
            // O(1) check based on time complexity of HashMap
            if(timemap.find(key) == timemap.end())
            {
                vector<pair<int, string>> v;
                timemap[key] = v;
            }
            // add the timestamp-value pair to the associated vector
            // O(1) amortized push
            // O(1) access to HashMap
            // this will always be sorted by timestamps
            // this is due to increasing nature of timestamps
            timemap[key].push_back({timestamp, value});
        }
        
        // O(log n) time complexity due to binary search
        string get(string key, int timestamp) 
        {
            // check if the key is not in the map
            // if not, cannot obtain any value, so return ""
            // O(1) access to HashMap
            if(timemap.find(key) == timemap.end())
            {
                return "";
            }
            // obtain vector associated with the key
            // O(1) extraction
            vector<pair<int, string>> values = timemap[key];
            string prev = "";
            for(auto i : values)
            {
                if(i.first > timestamp)
                {
                    return prev;
                }
                prev = i.second;
            }
            return prev;
            // // use binary search on timestamps to find appropriate value
            // // O(log n) time complexity
            // int left = 0;
            // int right = values.size();
            // while(left <= right)
            // {
            //     int mid = left + (right - left) / 2;
            //     if(timestamp == values[mid].first)
            //     {
            //         return values[mid].second;
            //     }
            //     else if(timestamp < values[mid].first)
            //     {
            //         right = mid - 1;
            //     }
            //     else
            //     {
            //         left = mid + 1;
            //     }
            // }
            // // if current timestamp smaller than required at left index
            // // return the left timestamp
            // // if not timestamp too large, return ""
            // return values[left].first < timestamp ? values[left].second : "";
        }
};
