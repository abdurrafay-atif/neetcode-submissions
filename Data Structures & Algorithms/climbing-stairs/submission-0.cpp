class Solution 
{
    public:
        int climbStairs(int n) 
        {
            // edge case
            if(n == 1)
            {
                return 1;
            }
            // base values (1 & 2 steps)
            int count1 = 1;
            int count2 = 2;
            // loop to cover remaining steps
            for(int i = 3; i <= n; i++)
            {
                // # of ways to climb current
                // can either climb all ways to n - 2 or all ways to n - 1, then one more step
                // so must combine the two counts
                // use temp variable for switching
                int temp = count2;
                count2 = count1 + count2;
                count1 = temp;
            }
            return count2;
        }
};