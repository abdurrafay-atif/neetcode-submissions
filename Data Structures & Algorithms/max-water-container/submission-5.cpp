class Solution 
{
    public:
        // time complexity: O(n)
        // space complexity: O(1)
        int maxArea(vector<int>& heights) 
        {
            int left = 0;                       // left pointer
            int right = heights.size() - 1;     // right pointer
            int max_area = 0;                   // final result
            // standard two pointers loop
            while(left < right)
            {
                // calculation of area in a container
                int area = (right - left) * min(heights[left], heights[right]);
                // update maximum if new area is larger
                max_area = max(area, max_area);
                // greedy algorithm: always update pointer of smaller height
                // smaller height determines height limit of water in container
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
