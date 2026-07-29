class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // min-heap
        priority_queue<int, vector<int>, greater<int>> pqueue;
        // add to queue, remove if exceeding limit
        for(auto i : nums)
        {
            pqueue.push(i);
            if(pqueue.size() > k)
            {
                pqueue.pop();
            }
        }
        return pqueue.top();
    }
};
