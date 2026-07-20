class Solution 
{
    public:
        // brute force solution 
        // time complexity: O(n^2)
        // space complexity: O(1)
        int largestRectangleArea(vector<int>& heights) 
        {
            int max_area = 0;
            // loop through each height
            for(int i = 0; i < heights.size(); i++)
            {
                int left = i - 1;
                int right = i + 1;
                int area = heights[i];
                // find first smaller to the left
                while(left >= 0 && heights[left] >= heights[i])
                {
                    area += heights[i];
                    left--;
                }
                // find first smaller to the right
                while(right < heights.size() && heights[right] >= heights[i])
                {
                    area += heights[i];
                    right++;
                }
                // update maximum
                max_area = max(area, max_area);
            }
            return max_area;
        }
};
