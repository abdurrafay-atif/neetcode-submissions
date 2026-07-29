class KthLargest
{
    private:
        int k;
        priority_queue<int, vector<int>, greater<int>> pqueue;

    public:
        KthLargest(int k, vector<int>& nums) 
        {
            this->k = k;
            // add all numbers to binary search tree
            for(auto i : nums)
            {
                pqueue.push(i);
                if(pqueue.size() > k)
                {
                    pqueue.pop();
                }
            }
        }
        
        int add(int val) 
        {   
            pqueue.push(val);
            if(pqueue.size() > k)
            {
                pqueue.pop();
            }
            return pqueue.top();
        }
};
