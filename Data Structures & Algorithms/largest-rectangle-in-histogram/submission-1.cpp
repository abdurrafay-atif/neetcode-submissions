class Solution 
{
    public:
        // optimal solution
        int largestRectangleArea(vector<int>& heights) 
        {
            stack<pair<int, int>> st;
            int max_area = 0;
            // initial pass
            for(int i = 0; i < heights.size(); i++)
            {
                int curr_area = 0;
                int index = i;
                while(!st.empty() && heights[i] <= st.top().second)
                {
                    curr_area = (i - st.top().first) * st.top().second;
                    max_area = max(curr_area, max_area);
                    index = st.top().first;
                    st.pop();
                }
                st.push({index, heights[i]});
            }
            // remove rest of the elements and update maximal areas
            while(!st.empty())
            {
                int curr_area = (heights.size() - st.top().first) * st.top().second;
                max_area = max(curr_area, max_area);
                st.pop();
            }
            return max_area;
        }
};
