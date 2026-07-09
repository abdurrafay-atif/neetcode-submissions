class Solution 
{
    public:
        // brute force solution using two pointers
        int trap(vector<int>& height) 
        {
            int total_trapped = 0; // total result
            // loop through each index to individually calculate water trapped
            // O(n^2), n = # of elements in height
            // Loop through height n times
            // Pointers move at most 2*n times inside loop
            for(int i = 0; i < height.size(); i++)
            {
                int left = i - 1;       // left pointer
                int right = i + 1;      // right pointer
                int max_left = 0;       // maximum bar at left of height[i]
                int max_right = 0;      // maximum bar at right of height[i]
                // locate maximum bar at left of height[i]
                while(left >= 0)
                {
                    max_left = max(max_left, height[left--]);
                }
                // locate maximum bar at right of height[i]
                while(right < height.size())
                {
                    max_right = max(max_right, height[right++]);
                }
                // calculate total trapped based on this formula:
                // min(height[l], height[r]) - height[i]
                // whatever is smaller bar is where trapping caps out
                // must exclude total in bar included at index i
                int trapped_i = min(max_left, max_right) - height[i];
                // only add to total trapped if positive (means actually trapped)
                if(trapped_i >= 0)
                {
                    total_trapped += min(max_left, max_right) - height[i];
                }
            }
            return total_trapped;
        }
};
