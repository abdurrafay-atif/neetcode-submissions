class Solution 
{
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        // this type of set has O(1) access, insert, remove
        // sets are incredibly useful for detecting duplicates efficiently
        unordered_set<int> set;
        // use the enhanced for loop to iterate through the vector
        for(auto i : nums)
        {
            // duplicate means the set contains the value already
            if(set.contains(i))
            {
                return true;
            }
            // insert this value so when it is seen again 
            // it can be considered a duplicate
            set.insert(i);
        }
        return false;
    }
};