class Solution 
{
    public:
        // brute force solution
        // time complexity: O(n^2), n = length of s2
        // space complexity: O(n^2), n = length of s2
        bool checkInclusion(string s1, string s2) 
        {
            // obtain frequency mapping of s1
            unordered_map<char, int> m1;
            for(auto c : s1)
            {
                m1[c] = m1.find(c) == m1.end() ? 1 : m1[c] + 1;
            }
            // iterate through all possible substrings
            for(int i = 0; i < s2.size(); i++)
            {
                unordered_map<char, int> m2; // frequency mapping for substring
                for(int j = i; j < s2.size(); j++)
                {
                    // extract character at index j of s2
                    char c = s2[j];
                    // update frequency mapping
                    m2[c] = m2.find(c) == m2.end() ? 1 : m2[c] + 1;
                    // check that frequency mappings between m1 & m2 match
                    // this indicates that they are permutations
                    if(m1 == m2)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};
