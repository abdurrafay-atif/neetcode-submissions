class Solution 
{
    public:
        int characterReplacement(string s, int k) 
        {
            int left = 0;
            int longest = 0;
            unordered_map<char, int> freqs;
            int max_freq = 0;
            for(int right = 0; right < s.length(); right++)
            {
                char c = s[right];
                freqs[c] = freqs.find(c) == freqs.end() ? 1 : freqs[c] + 1;
                max_freq = max(freqs[c], max_freq);
                while(k < (right - left + 1) - max_freq)
                {
                    freqs[s[left]]--;
                    left++;
                    // for(auto i : freqs)
                    // {
                    //     max_char = freqs[i.first] >= freqs[max_char] ? i.first : max_char;
                    // }
                }
                longest = max(right - left + 1, longest);
            }
            return longest;
        }
};
