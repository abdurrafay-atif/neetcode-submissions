class Solution 
{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) 
        {
            // result vector
            vector<vector<int>> res;
            // sort the numbers array so extra space is unneeded
            // takes O(n log n) time which is fine for this problem
            sort(nums.begin(), nums.end());
            // loop through array... nums[i]
            for(int i = 0; i < nums.size() - 2; i++)
            {
                // stop when reaching positive number
                // sum of 3 positive numbers is never 0
                if(nums[i] > 0)
                {
                    break;
                }
                // skip this iteration if previous = curr
                // this is to prevent duplicates
                if(i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                // two pointers
                int j = i + 1;
                int k = nums.size() - 1;
                // loop until pointers meet (two-pointers technique)
                while(j < k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0)
                    {
                        // add to the list
                        res.push_back({nums[i], nums[j], nums[k]});
                        // move pointer by 1
                        j++;
                        // skip duplicates
                        while(j < nums.size() && nums[j] == nums[j - 1])
                        {
                            j++;
                        }
                    }
                    else if(sum < 0)
                    {
                        j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            }
            return res;
        }
};
