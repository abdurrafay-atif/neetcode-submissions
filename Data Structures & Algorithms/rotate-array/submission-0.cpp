class Solution 
{
    public:
        // brute force solution 
        // time complexity: O(n)
        // space complexity: O(n)
        void rotate(vector<int>& nums, int k) 
        {
            vector<int> rot(nums.size());
            for(int i = 0; i < nums.size(); i++)
            {
                rot[(i + k) % nums.size()] = nums[i];
            }
            nums = rot;
        }
};