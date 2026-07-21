class Solution 
{
    public:
        int maxProfit(vector<int>& prices) 
        {
            int left = 0;
            int max_profit = 0;
            for(int right = 1; right < prices.size(); right++)
            {
                int profit = prices[right] - prices[left];
                max_profit = max(profit, max_profit);
                if(profit < 0)
                {
                    left = right;
                }
            }
            return max_profit;
        }
};
