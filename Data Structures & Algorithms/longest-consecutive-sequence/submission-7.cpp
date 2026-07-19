class Solution 
{
    public:
        // union find algorithm
        int longestConsecutive(vector<int>& nums) 
        {
            unordered_map<int, int> s;  // map for storing adjacent sequences
            int longest = 0;            // result
            for(auto i : nums)          // loop
            {
                if(s[i] == 0)           // if not seen
                {
                    s[i] = s[i - 1] + s[i + 1] + 1; // update current 
                    s[i - s[i - 1]] = s[i];         // update leftmost
                    s[i + s[i + 1]] = s[i];         // update rightmost
                    longest = max(s[i], longest);   // update maximum
                }
            }
            return longest;
        }
};
