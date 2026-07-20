class Solution 
{
    public:
        // brute force solution
        int largestRectangleArea(vector<int>& heights) 
        {
            int largest_area = 0;
            for(int i = 0; i < heights.size(); i++)
            {
                int minimum = heights[i];
                for(int j = i; j < heights.size(); j++)
                {
                    minimum = min(heights[j], minimum);
                    int area = minimum * (j - i + 1);
                    largest_area = max(area, largest_area);
                }
            }
            return largest_area;
        }
};
