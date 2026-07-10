class Solution 
{
    public:
        // longest repeating character replacement
        // longest substring without repeating characters: 
        // --> check for no duplicate
        // longest substring with repeating characters:
        // --> check for most repeated character, add k to it
        int characterReplacement(string s, int k) 
        {
            if(s.length() == 0) // edge case
            {
                return 0;
            }
            unordered_map<char, int> my_set;    // map for prior checked indices
            int left = 0;                       // left pointer
            int right = 1;                      // right pointer
            int largest_freq = 0;               // tracks current largest frequency
            int size = 0;                       // window size tracker
            int longest = 0;                    // actual result
            // loop (O(n), as each iteration right increases, for the length of the string
            while(right <= s.length())
            {
                // calculate window size
                size = right - left;
                // extract current character at right end of window for processing
                char c = s[right - 1];
                // update frequency count of extracted character
                my_set[c] = my_set.find(c) == my_set.end() ? 1 : my_set[c] + 1;
                // determine if this new character is now the largest frequency
                // if so, move left pointer, shifting the sliding window 
                if(my_set[c] > largest_freq)
                {
                    largest_freq = my_set[c];
                }
                // check if largest frequency + replacements < size of window
                // if so, we need to shrink window to make sure replacements, 
                // make string entirely just one character
                if(largest_freq + k < size)
                {
                    my_set[s[left]]--;  // remove element from left end
                    left++;             // shrink window
                    size--;             // decrement window size
                }
                // update longest sequence if one character, 
                // can fill up the entire upon replacing k characters in substring
                if(largest_freq + k >= size)
                {
                    longest = max(size, longest);
                }
                // increment right pointer of sliding window for next iteration
                right++;
            }
            // if longest was never updated (due to no duplicates in entire string)
            // just use size calculated
            return size > longest ? size : longest;
        }
};
