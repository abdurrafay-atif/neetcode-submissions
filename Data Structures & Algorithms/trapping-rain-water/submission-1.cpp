class Solution 
{
    public:
        // brute force solution using two pointers
        int trap(vector<int>& height) 
        {
            // store maximum & minimum heights at each index in dp vectors
            vector<int> max_left_store;
            vector<int> max_right_store;
            // left & right maximum trackers
            int max_left = 0;
            int max_right = 0;
            for(int i = 0; i < height.size(); i++)
            {
                max_left_store.push_back(max_left);
                max_right_store.push_back(max_right);
                max_left = max(max_left, height[i]);
                max_right = max(max_right, height[height.size() - i - 1]);
            }
            // loop through heights again
            // use dp vectors to calculate trapped water at each bar
            // formula: min(height[l], height[r]) - height[i]
            int total_trapped = 0; // total result
            for(int i = 0; i < height.size(); i++)
            {
                // calculate trapped water at index
                int trapped_i = min(max_left_store[i], 
                    max_right_store[height.size() - i - 1]) - height[i];
                // only add trapped water if positive (means actually trapped)
                if(trapped_i >= 0)
                {
                    total_trapped += trapped_i;
                }
            }
            return total_trapped;
        }
};
