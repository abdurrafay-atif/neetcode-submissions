class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        // use a set to track elements we have seen
        unordered_set<int> s;
        // need to loop through all elements to check for duplicates
        for(auto i : nums)
        {
            // check that the element is in the set
            // if it is, this is a duplicate
            if(s.find(i) != s.end())
            {
                return true;
            }
            // add element to the set so in the future, we can check if this element reappears
            // if it does reappear, it is a duplicate
            s.insert(i);
        }
        // all elements have been checked and none were duplicates
        // so array does not contain any duplicates
        return false;
    }
};