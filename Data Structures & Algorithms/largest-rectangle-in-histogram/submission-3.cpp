class Solution 
{
    public:
        // brute force solution 
        // time complexity: O(n^2)
        // space complexity: O(1)
        int largestRectangleArea(vector<int>& heights) 
        {
            stack<pair<int, int>> st;   // stack for ascending monotonic stack
            int max_area = 0;           // final result
            // loop through each height
            for(int i = 0; i < heights.size(); i++)
            {   
                int curr_area = 0;
                int prev = i;
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
            while(!st.empty())
            {
                int curr_area = (heights.size() - st.top().first) * st.top().second;
                max_area = max(curr_area, max_area);
                st.pop();
            }
            return max_area;
        }
};
