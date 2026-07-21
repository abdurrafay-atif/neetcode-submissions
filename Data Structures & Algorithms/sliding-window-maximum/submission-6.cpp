class Solution 
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            // result
            vector<int> res;
            // deque for keeping track of window
            deque<int> window; 
            // loop
            for(int i = 0; i < nums.size(); i++)
            {
                // pop all elements outside of window
                // only do this when window has elements
                while(!window.empty() && window.back() <= (i - k))
                {
                    window.pop_back();
                }
                // pop elements at front if they are smaller than current
                // these elements can never be maximum due to this element
                while(!window.empty() && nums[window.front()] <= nums[i])
                {
                    window.pop_front();
                }
                // add element index to front of window as this is the least maximum 
                // the deque is ordered as a descending deque by definition
                window.push_front(i);
                // add current maximum (at back of deque) if window size has been reached
                if(i >= k - 1)
                {
                    res.push_back(nums[window.back()]);
                }
            }
            return res;
        }
};
