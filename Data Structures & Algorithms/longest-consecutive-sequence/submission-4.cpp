class Solution 
{
    public:
        // time complexity: O(n)
        // space complexity: O(n)
        int longestConsecutive(vector<int>& nums) 
        {
            // add all elements in nums into a set
            // this allows for O(1) trailing
            unordered_set<int> s;
            for(auto i : nums)
            {
                s.insert(i);
            }
            // algorithm for determining longest consecutive sequence
            // loop until the set is empty (meaning no more sequences to check)
            // obtain element from hashset
            // determine how long its sequence is by trailing backward & forward
            // this is the length of its sequence
            // update longest if this length is the new longest
            int longest = 0;
            while(!s.empty())
            {
                int start = *s.begin();
                int inc = start;
                int dec = start;
                int length = 1;
                while(s.find(inc + 1) != s.end())
                {   
                    inc++;
                    s.erase(inc);
                    length++;
                }
                while(s.find(dec - 1) != s.end())
                {
                    dec--;
                    s.erase(dec);
                    length++;
                }
                s.erase(start);
                longest = max(length, longest);
            }
            return longest;
        }
};
