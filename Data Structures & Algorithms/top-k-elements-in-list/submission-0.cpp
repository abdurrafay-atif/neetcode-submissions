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
            }
            // obtain top k frequencies by determining max in each iteration
            vector<int> res;
            int prev_freq = INT_MAX; // to track highest frequencies in prior iterations
            for(int i = 0; i < k; i++)
            {
                int max_freq_i = INT_MIN;   // highest frequency at this iteration
                int max_ele_i = 0;          // element with highest frequency in this iteration
                for(auto j : int_freqs)
                {
                    // check if frequency is the largest and smaller than previous largest
                    // if so update the maximums
                    if(j.second > max_freq_i && j.second <= prev_freq)
                    {
                        max_freq_i = j.second;
                        max_ele_i = j.first;
                    }
                }
                // next maximums have been found, update globals
                res.push_back(max_ele_i);
                prev_freq = max_freq_i;
                // remove element from hashset so it doesn't get reused
                int_freqs.erase(max_ele_i);
            }
            return res;
        }
};
