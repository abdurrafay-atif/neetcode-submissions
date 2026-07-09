class Solution {
public:
    // Time Complexity: O(N^2) worst case, O(N) best case
    // Space Complexity: O(# of distinct characters) worst case, O(1) best case
    int lengthOfLongestSubstring(string s) 
    {
        if(s.length() == 0) // edge case
        {
            return 0;
        }
        unordered_set<char> set; // set for checking repeats...
        int left = 0;            // left pointer
        int right = 0;           // right pointer
        int longest = 0;         // actual result
        // loop (O(n), as each iteration right increases, for the length of the string
        while(right <= s.length() - 1)
        {
            // check that the current character is not a duplicate
            // this is O(1) check due to hashset having O(1) operations
            if(set.find(s[right]) != set.end())
            {
                // check if this string range is the longest
                // done every time the string starts to shrink again
                // O(1) check
                if(set.size() >= longest)
                {
                    longest = set.size();
                }
                // remove all characters prior to the duplicate + the duplicate itself
                // this is because the no-duplicates string now starts after the prior instance of the duplicate
                // O(n) as this could possibly go through entire string at worst case
                // this is a while(1) loop as the deletion MUST exist at least for the first element
                // must check if element at s[left] is the duplicate found to proceed
                // left is incremented always, but must check s[left] != s[right] before increment for accuracy
                while(1)
                {
                    set.erase(s[left]);
                    if(s[left] == s[right])
                    {
                        left++;
                        break;
                    }
                    left++;
                }
            }
            set.insert(s[right]);
            right++;
        }
        // if longest was never updated (due to no duplicates in entire string)
        // just use curr_longest
        return set.size() >= longest ? set.size() : longest;
    }
};
