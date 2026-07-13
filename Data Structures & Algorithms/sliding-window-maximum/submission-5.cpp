class Solution 
{
    public:
        // deque solution
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            vector<int> maximums;       // result 
            deque<int> d;               // deque for caching maximums
            // loop for moving sliding window
            // note: deque is in decreasing order from back to front
            for(int i = 0; i < nums.size(); i++)
            {
                // remove elements outside of window
                while(!d.empty() && d.back() < i - k + 1)
                {
                    d.pop_back();
                }
                // for the current element, remove all elements less than it
                // this allows deque to be in descending order
                // all operations O(1), runs at most n times throughout whole duration
                while(!d.empty() && nums[d.front()] <= nums[i])
                {
                    d.pop_front();
                }
                // push current element (index, to check later if it needs to be popped off)
                d.push_front(i);
                // only add maximums when reached sliding window length
                // maximum is at back at deque, due to descending nature of deque
                if(i >= k - 1)
                {
                    maximums.push_back(nums[d.back()]);
                }
            }
            return maximums;
        }
};
