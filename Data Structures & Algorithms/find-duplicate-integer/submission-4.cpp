class Solution 
{
public:
    // hashset solution
    // time complexity: O(n)
    // space complexity: O(n)
    int findDuplicate(vector<int>& nums) 
    {  
        for(int i = 0; i < nums.size(); i++)
        {
            // extract current element with seen bit cleared out
            // this is so we get the correct value for checking
            int curr = nums[i];
            curr &= (~(1 << 30));
            // check if this value has been seen already
            // if so this is the duplicate
            if(nums[curr] & (1 << 30))
            {
                return curr;
            }
            // set the seen bit (30) at index of current number
            // this supplements hashset functionality so we have O(1) space complexity
            nums[curr] |= (1 << 30);
        }
        return 0;
    }
};
