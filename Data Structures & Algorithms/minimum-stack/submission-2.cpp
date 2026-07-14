class MinStack 
{
    private:
        vector<int> st;     // main stack
        vector<int> mins;   // mins stack (for tracking minimums during pushes)
        int minimum;        // current minimum

    public:
        // used to initialize sizes & minimum
        MinStack() 
        {
            minimum = INT_MAX;
        }
        
        // pushes the element onto the stack
        // pushes the minimum of this new value and the current minimum onto the stack
        // thus when popping if new minimum gets popped it goes back to prior minimum
        // minimum is updated
        void push(int val) 
        {
            st.push_back(val);
            mins.push_back(min(val, minimum));
            minimum = mins[mins.size() - 1];
        }
        
        // removes from both stacks
        // updates minimum to previous one
        // edge case: mins becomes empty, minimum becomes INT_MAX
        void pop() 
        {
            st.pop_back();
            mins.pop_back();
            minimum = mins.size() == 0 ? INT_MAX : mins[mins.size() - 1];
        }
        
        // returns the top element of main stack
        // this is located at last index of stack
        int top() 
        {
            return st[st.size() - 1];
        }
        
        // returns minimum element (saved in min variable)
        int getMin() 
        {
            return minimum;
        }
    };
