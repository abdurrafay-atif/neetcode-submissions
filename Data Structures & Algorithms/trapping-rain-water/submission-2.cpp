class Solution 
{
    public:
        int trap(vector<int>& height) 
        {
            int left = 0;                       // left pointer
            int right = height.size() - 1;      // right pointer
            int left_max = height[left];        // track left maximum
            int right_max = height[right];      // track right maximum
            int trapped = 0;                    // final result
            // standard two pointers loop
            while(left < right)
            {
                // greedy algorithm: always increase pointer whose maximum is smaller
                // trapped water is limited by the smaller height
                // formula: trapped_water[i] = min(h[left], h[right]) - h[i]
                // so if we track height left maximums & right maximums along the way
                // we can determine the limiting height at each iteration
                if(left_max < right_max)
                {
                    left++;
                    left_max = max(height[left], left_max);
                    trapped += left_max - height[left];
                }   
                else
                {
                    right--;
                    right_max = max(height[right], right_max);
                    trapped += right_max - height[right];
                }
            }
            return trapped;
        }
};
