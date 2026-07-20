class Solution 
{
    public:
        // optimal Stack-Based solution
        // time complexity: O(n)
        // space complexity: O(n)
        int largestRectangleArea(vector<int>& heights) 
        {
            stack<pair<int, int>> st;   // stack for ascending monotonic stack
            int max_area = 0;           // final result
            // loop through each height
            for(int i = 0; i < heights.size(); i++)
            {   
                // track current area when popping back
                int curr_area = 0;
                // this keeps track of the index to fall back to
                // this keeps track of the "left smaller" of each rectangle
                int prev = i;
                // loop which rolls back each height
                // this determines the "right smaller" of each rectangle 
                // which we have encountered so far
                // this is combined with the left smaller to determine area of each rectangle
                // this is how we achieve O(n) time via a monotonic stack
                while(!st.empty() && heights[i] < st.top().second)
                {
                    curr_area = (i - st.top().first) * st.top().second;
                    max_area = max(curr_area, max_area);
                    prev = st.top().first;
                    st.pop();
                }
                st.push({prev, heights[i]});
            }
            // final loop through stack
            // this tracks all areas missed due to loop above ending
            while(!st.empty())
            {
                int curr_area = (heights.size() - st.top().first) * st.top().second;
                max_area = max(curr_area, max_area);
                st.pop();
            }
            return max_area;
        }
};
