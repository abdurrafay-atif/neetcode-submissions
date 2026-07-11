class Solution 
{
    public:
        // sliding window solution
        // time complexity: O(n), n = length of s2
        // space complexity: O(1), as only 26 characters
        bool checkInclusion(string s1, string s2) 
        {
            // obtain set of characters in s1
            // O(m) loop, m = length of s1
            unordered_map<char, int> m1_freqs;
            for(auto c : s1)
            {
                m1_freqs[c] = m1_freqs.find(c) == m1_freqs.end() ? 
                    1 : m1_freqs[c] + 1;
            }
            // left pointer of window
            int left = 0;     
            // frequency mapping of portion of s2
            unordered_map<char, int> m2_freqs;
            // loop through the string
            // left moved to right position when character appears...
            // that does not satisfy permutation constraints
            for(int right = 0; right < s2.length(); right++)
            {
                // extract character at current index
                char c = s2[right];
                // if character not in m1 map, move to next iteration
                // tighten window to be where right position is
                // also clear map
                if(m1_freqs.find(c) == m1_freqs.end()) 
                {
                    left = right;
                    m2_freqs.clear();
                    continue;
                }
                // update m2_freqs with new frequency count
                m2_freqs[c] = m2_freqs.find(c) == m2_freqs.end() ? 
                    1 : m2_freqs[c] + 1;
                // if any frequency gets too large, 
                // move left pointer until its frequency matches again
                while(m2_freqs[c] > m1_freqs[c])
                {
                    m2_freqs[s2[left]]--;
                    left++;
                }
                // if m1 & m2 frequency maps are equivalent, this is permutation
                if(m1_freqs == m2_freqs)
                {
                    return true;
                }
            }
            return m1_freqs == m2_freqs;
        }
};
