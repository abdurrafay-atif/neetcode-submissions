class Solution 
{
    public:
        int minEatingSpeed(vector<int>& piles, int h) 
        {
            // find maximum of piles array
            // this is used to determine bounds for binary search
            int maximum = 1;
            for(auto pile : piles)
            {
                maximum = max(pile, maximum);
            }
            // perform binary search on all possible eating rates
            // this range is [1, maximum], maximum found in previous step
            int left = 1;
            int right = maximum;
            int k = right;  // last valid eating rate
            while(left <= right)
            {
                int eating_rate = left + ((right - left) / 2);
                // determine hours eaten
                // sum all hours for each pile
                // if pile % eating_rate == 0, then simply divide by eating_rate
                // if pile % eating_rate != 0, divide by eating_rate and add 1
                long long hours = 0;
                for(auto pile : piles)
                {
                    hours += (pile / eating_rate);
                    if(pile % eating_rate != 0)
                    {
                        hours += 1;
                    }
                }
                // perform binary search algorithm 
                // if hours small compared to given, eliminate right half
                // only consider smaller eating rates 
                if(hours <= h)
                {
                    k = eating_rate;
                    right = eating_rate - 1;
                }
                // current eating rate too slow, check higher eating rates
                // this is done by eliminating left half of eating rates
                else
                {
                    left = eating_rate + 1;
                }
            }
            // return last valid eating rate
            return k;
        }
};
