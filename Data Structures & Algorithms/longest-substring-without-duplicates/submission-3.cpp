class Solution 
{
    public:
    // Time Complexity: O(N)
    // Space Complexity: O(# of distinct characters)
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length() == 0) // edge case
        {
            return 0;
        }
        unordered_map<char, int> my_set;    // map for prior checked indices
        int left = 0;                       // left pointer
        int right = 0;                      // right pointer
        int size = 0;                       // window size tracker
        int longest = 0;                    // actual result
        // loop (O(n), as each iteration right increases, for the length of the string
        while(right < s.length())
        {
            // calculate window length at every iteration
            size = right - left;
            // check that the current character is not a duplicate
            // only consider if within window (>= left)
            // this is O(1) check due to hashset having O(1) operations
            if(my_set.find(s[right]) != my_set.end() && my_set[s[right]] >= left)
            {
                // check if this string range is the longest... O(1) check
                if(size > longest)
                {
                    longest = size;
                }   
                // update left pointer to indicate window has changed
                // move it to start one character after duplicate
                // thus there will definitely be no duplicates in new window
                left = my_set[s[right]] + 1;
            }
            my_set[s[right]] = right;
            right++;
        }
        // re-calculated size one last time in case it is outdated
        size = right - left;
        // if longest was never updated (due to no duplicates in entire string)
        // just use size calculated
        return size > longest ? size : longest;
    }
};
