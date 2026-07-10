class Solution 
{
    public:
        // brute force solution
        // nested for loop: all possible substrings
        // inside loop:
        // 1. obtain frequency counts of letters
        // 2. if any character has substring.length() - k instances, 
        // update longest if this is longest possible
        int characterReplacement(string s, int k) 
        {
            int longest = 0; // end result
            // nested for loop for all possible substrings
            for(int left = 0; left < s.length(); left++)
            {
                // frequency map for characters in all substrings starting from left
                unordered_map<char, int> freqs;
                int largest_freq = 0;
                // loop through substrings starting from left index
                for(int right = left + 1; right <= s.length(); right++)
                {
                    int size = right - left;    // current substring length
                    char c = s[right - 1];      // current character
                    // if character not already in frequency map, 
                    // add it with a frequency of 1
                    // else increment its frequency count
                    freqs[c] = (freqs.find(c) == freqs.end()) ? 1 : freqs[c] + 1;
                    // check if this character has largest count seen so far
                    if(freqs[c] > largest_freq)
                    {
                        largest_freq = freqs[c];
                    }
                    // check if any character can appear for entire substring if replacements occur
                    if(largest_freq + k >= size && longest < size)
                    {
                        longest = size;
                    }
                }
            }
            return longest;
        }
};
