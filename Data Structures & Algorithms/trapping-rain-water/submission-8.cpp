class Solution 
{
    public:
        // stack solution
        // time complexity: O(n)
        // space complexity: O(n)
        int trap(vector<int>& height) 
        {
            stack<int> st;
            int trapped = 0;
            for(int i = 0; i < height.size(); i++)
            {
                while(!st.empty() && height[i] >= height[st.top()])
                {
                    int middle = height[st.top()];
                    st.pop();
                    if(!st.empty())
                    {
                        int left = height[st.top()];
                        int right = height[i];
                        int mid_height = min(left, right) - middle;
                        int dist = i - st.top() - 1;
                        trapped += (mid_height * dist);
                    }
                }
                st.push(i);
            }
            return trapped;
        }
};
