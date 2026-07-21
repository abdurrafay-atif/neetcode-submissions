class Solution 
{
    public:
        int minEatingSpeed(vector<int>& piles, int h) 
        {
            // attain maximum for binary search
            int maximum = INT_MIN;
            for(auto pile : piles)
            {
                maximum = max(pile, maximum);
            }
            // perform binary search on eating rates
            int left = 1;
            int right = maximum;
            while(left <= right)
            {
                // eating rate being checked
                int eating_rate = left + (right - left) / 2;
                // calculate number of hours it takes to eat all bananas
                int num_hours = 0;
                for(auto pile : piles)
                {
                    num_hours += ceil(pile / (double) eating_rate);
                }
                // if hours small, can eat slower
                if(num_hours <= h)
                {
                    right = eating_rate - 1;
                }
                else
                {
                    left = eating_rate + 1;
                }
            }
            return left;
        }
};
