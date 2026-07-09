class Solution 
{
    public:
        // dynamic programming approach
        int maxProfit(vector<int>& prices) 
        {
            // dp variable
            int lowest = INT_MAX;
            // result variable
            int max_profit = 0;
            // simple pass through array
            for(auto i : prices)
            {
                // update lowest price seen so far
                lowest = min(i, lowest);
                // calculate the current profit
                int profit = i - lowest;
                // determine new max profit based on lowest
                max_profit = max(profit, max_profit);
            }
            return max_profit;
        }
};
