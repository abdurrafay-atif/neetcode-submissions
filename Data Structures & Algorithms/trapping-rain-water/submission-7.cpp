class Solution 
{
    public:
        // 2P solution
        // time complexity: O(n)
        // space complexity: O(1)
        int trap(vector<int>& height) 
        {
            int left = 0;
            int right = height.size() - 1;
            int left_max = height[0];
            int right_max = height[height.size() - 1];
            int trapped = 0;
            while(left < right)
            {
                if(left_max < right_max)
                {
                    left++;
                    left_max = max(height[left], left_max);
                    trapped += (left_max - height[left]);
                }
                else
                {
                    right--;
                    right_max = max(height[right], right_max);
                    trapped += (right_max - height[right]);
                }
            }
            return trapped;
        }
};
