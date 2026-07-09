class Solution 
{
    public:
        // brute force solution
        // time complexity: O(n^2)
        // space complexity: O(1)
        int maxArea(vector<int>& heights) 
        {
            // two pointers
            int left = 0;
            int right = heights.size() - 1;
            int max_area = 0;
            // loop (runs until left & right pointers meet, as part of two pointers approach)
            // O(n) loop, as each element is only accessed once
            while(left < right)
            {
                // determine the area based on current pointer bar heights
                // area is based on distance * height of smaller
                int smaller_height = 
                    (heights[left] < heights[right]) ?
                    heights[left] : heights[right];
                bool left_smaller = smaller_height == heights[left];
                int area = (right - left) * smaller_height;
                // determine if the current area is the largest seen so far
                if(area > max_area)
                {
                    max_area = area;
                }
                // move left pointer if it is the smaller bar
                // container water height only changes when smallest bar increases height
                // thus greedy algorithm is to always move pointer of smaller bar to higher bar
                if(left_smaller)
                {
                    left++;
                }
                // move right pointer if right bar is smaller
                // again part of greedy algorithm
                else
                {
                    right--;
                }
            }
            return max_area;
        }
};
