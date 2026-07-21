class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int min_price = INT_MAX;
            int max_profit = 0;
            for(auto price : prices)
            {
                min_price = min(price, min_price);
                int profit = price - min_price;
                max_profit = max(profit, max_profit);
            }
            return max_profit;
        }
};
