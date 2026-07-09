class Solution 
{
    public:
        // brute force approach
        // time complexity
        int maxProfit(vector<int>& prices) 
        {
            // result variable, always >= 0 as profit only occurs when it is positive
            int max_profit = 0; 
            // nested for loop to check all possibilities
            for(int i = 0; i < prices.size(); i++)
            {
                for(int j = i + 1; j < prices.size(); j++)
                {
                    // calculate profit at this iteration
                    // determine if this is more profitable than current maximum
                    int profit = prices[j] - prices[i];
                    max_profit = max(profit, max_profit);
                }
            }
            return max_profit;
        }
};
