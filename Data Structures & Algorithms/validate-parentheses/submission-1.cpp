class Solution 
{
    public:
        bool isValid(string s) 
        {
            // stack for tracking matching characters
            // for each item in stack, it must match current element
            // essentially, when we close something, it should come out in the stack
            // this is due to LIFO nature of stack
            // the latest parantheses to open should also be the next one to close
            stack<char> st;
            // simple loop across the characters
            for(auto c : s)
            {
                // if this is an opening bracket, simply push to the stack
                if(c == '(' || c == '{' || c == '[')
                {
                    st.push(c);
                }
                // all other characters are closing brackets, so just a simple else statement
                else
                {
                    // if the stack is empty, we do not have a matching opening bracket
                    // so simply return false immediately
                    // if the top doesn't have matching bracket, also return false
                    if(st.empty() || 
                    (st.top() == '(' && c != ')') || 
                    (st.top() == '{' && c != '}') || 
                    (st.top() == '[' && c != ']'))
                    {
                        return false;
                    }   
                    // if match occurs, pop the bracket from the stack
                    // this bracket has been processed
                    st.pop();
                }
            }
            // if the stack still consists of elements, it is not valid
            // this is because there are some brackets which haven't been closed
            // if the stack is empty, that means all brackets have been closed
            return st.empty();
        }
};
