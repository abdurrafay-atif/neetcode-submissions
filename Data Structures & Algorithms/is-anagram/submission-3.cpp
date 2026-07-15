class Solution 
{
    public:
        // time complexity: O(nlogm)
        // space complexity: O(1)
        bool isAnagram(string s, string t) 
        {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
};
