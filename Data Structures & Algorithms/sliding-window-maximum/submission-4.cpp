class Solution 
{
    public:
        void printQueue(queue<int> q)
        {
            while(!q.empty()) 
            {
                cout << " " << q.front();
                q.pop();
            }
            cout << "\n";
        }

        // priority queue (heap) solution
        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
        {
            // result vector
            vector<int> maximums;
            // priority queue for maintaining value-index pairs
            // value determines whether this element is maximum
            // index determines bound; if out-of-bounds of window, 
            // it is popped off the queue in favor of elements within window
            priority_queue<pair<int, int>> pqueue;
            // loop through each element of the nums array for determining maximums
            // need to loop through indices as it is important for window determination
            // O(nlogn) loop at worst case... 
            // 1. inner while loop is O(log n) as that is worst case runtime for pop() in pqueue
            // 2. for loop runs n times in all cases
            for(int i = 0; i < nums.size(); i++)
            {
                // code that always runs... the value-index pair is added to the queue
                pqueue.push({nums[i], i});
                // window maximums cannot be determined until have reached minimum window length
                // this occurs at index k - 1, so below code won't run until then
                if(i >= k - 1)
                {
                    // loop and pop through the priority queue
                    // the first valid element in it gets added to the result vector
                    // this is the maximum element which is within bounds of the window
                    while(pqueue.top().second <= (i - k))
                    {
                        pqueue.pop();
                    }
                    maximums.push_back(pqueue.top().first);
                }
            }
            return maximums;
        }
};
