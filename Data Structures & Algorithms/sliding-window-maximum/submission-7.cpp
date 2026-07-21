class Solution 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            // result
            vector<int> res;
            // max-heap for keeping track of window & maxes in window
            // second element of pair consists of indices
            // this prevents elements outside of window from appearing in result
            priority_queue<pair<int, int>> window; 
            // loop
            for(int i = 0; i < nums.size(); i++)
            {
                // pop elements outside of window
                while(!window.empty() && window.top().second <= (i - k))
                {
                    window.pop();
                }
                // add current element to heap
                window.push({nums[i], i});
                // add current maximum when window size has been reached
                if(i >= k - 1)
                {
                    res.push_back(window.top().first);
                }
            }
            return res;
        }
};
