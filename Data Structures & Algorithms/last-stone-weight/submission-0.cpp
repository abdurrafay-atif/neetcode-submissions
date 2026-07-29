class Solution 
{
    public:
        int lastStoneWeight(vector<int>& stones)
        {
            priority_queue<int> pqueue;
            for(auto i : stones)
            {
                pqueue.push(i);
            }
            while(pqueue.size() > 1)
            {
                int s1 = pqueue.top();
                pqueue.pop();
                int s2 = pqueue.top();
                pqueue.pop();
                if(s1 != s2)
                {
                    pqueue.push(s1 - s2);
                }
            }
            return pqueue.size() != 0 ? pqueue.top() : 0;
        }
};
