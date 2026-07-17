class Solution 
{
    public:
        int maxArea(vector<int>& heights) 
        {
            int left = 0;
            int right = heights.size() - 1;
            int max_area = 0;
            while(left < right)
            {
                int area = (right - left) * min(heights[left], heights[right]);
                max_area = max(area, max_area);
                if(heights[left] < heights[right])
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            return max_area;
        }
};
