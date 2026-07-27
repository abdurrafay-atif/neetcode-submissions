class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = (n * (n + 1)) / 2;
        int array_sum = 0;
        for(auto i : nums)
        {
            array_sum += i;
        }
        return sum - array_sum;
    }
};
