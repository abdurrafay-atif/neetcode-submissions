class MinStack 
{
    stack<int> st;
    stack<int> mins;

    public:
        MinStack() 
        {
            mins.push(INT_MAX);
        }
        
        void push(int val) 
        {
            st.push(val);
            mins.push(min(val, mins.top()));
        }
        
        void pop() 
        {
            st.pop();
            mins.pop(); 
        }
        
        int top() 
        {
            return st.top();
        }
        
        int getMin() 
        {   
            return mins.top();
        }
};
