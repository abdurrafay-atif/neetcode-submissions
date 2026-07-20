class Solution 
{
    public:
        // dynamic programming solution
        // time complexity: O(n)
        // space complexity: O(n)
        int trap(vector<int>& height) 
        {
            vector<int> leftmax(height.size());
            leftmax[0] = height[0];
            for(int i = 1; i < height.size(); i++)
            {
                leftmax[i] = max(height[i], leftmax[i - 1]);
            }
            vector<int> rightmax(height.size());
            rightmax[height.size() - 1] = height[height.size() - 1];
            for(int i = height.size() - 2; i >= 0; i--)
            {
                rightmax[i] = max(height[i], rightmax[i + 1]);
            }
            int trapped = 0;
            for(int i = 0; i < height.size(); i++)
            {
                trapped += min(leftmax[i], rightmax[i]) - height[i];
            }
            return trapped;
        }
};
