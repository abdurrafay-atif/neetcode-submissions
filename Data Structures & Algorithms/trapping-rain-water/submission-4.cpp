class Solution 
{
    public:
        // brute force solution
        // time complexity: O(n^2)
        // space complexity: O(1)
        int trap(vector<int>& height) 
        {
            int trapped = 0;
            for(int i = 0; i < height.size(); i++)
            {
                int left = i - 1;
                int right = i + 1;
                int left_max = height[i];
                int right_max = height[i];
                while(left >= 0)
                {
                    left_max = max(height[left], left_max);
                    left--;
                }
                while(right < height.size())
                {
                    right_max = max(height[right], right_max);
                    right++;
                }
                trapped += min(left_max, right_max) - height[i];
            }
            return trapped;
        }
};
