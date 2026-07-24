class Solution 
{
public:
    // hashset solution
    // time complexity: O(n)
    // space complexity: O(n)
    int findDuplicate(vector<int>& nums) 
    {  
        unordered_set<int> dups;
        for(auto i : nums)
        {
            if(dups.find(i) != dups.end())
            {
                return i;
            }
            dups.insert(i);
        }
        return 0;
    }
};
