class Solution 
{
    public:
        // sliding window approach
        int maxProfit(vector<int>& prices) 
        {
            // result variable, always >= 0 as profit only occurs when it is positive
            int max_profit = 0; 
            // left pointer (left end of window)
            int left = 0;
            // loop
            // window consists of indices [left, right] (inclusive)
            // if no profit move left end of window
            // right end of window always moving
            for(int right = 0; right < prices.size(); right++)
            {
                // profit calculation and updating of maximum
                int profit = prices[right] - prices[left];
                max_profit = max(profit, max_profit);
                // update left pointer if no profit
                // update it to where right pointer is
                // any major profits will only occur after this movement
                if(profit < 0)
                {
                    left = right;
                }
            }            
            return max_profit;
        }
};
