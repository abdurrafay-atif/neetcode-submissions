class Solution 
{
    public:
        // time complexity: O(nlogn) due to sorting
        // space complexity: O(1)
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            // place vector into vector of pairs consisting of integers and indices
            // this is so upon sorting, we still have access to initial indices
            vector<pair<int, int>> sorted;
            for(int i = 0; i < nums.size(); i++)
            {
                sorted.push_back({nums[i], i});
            }
            // sort the given array to use the two pointers technique
            sort(sorted.begin(), sorted.end());
            // use two pointers across sorted array
            // move left if too small
            // move right if too big
            // will eventually meet the target
            int left = 0;
            int right = sorted.size() - 1;
            while(left < right) // loop condition ensures indices don't match
            {
                int sum = sorted[left].first + sorted[right].first;
                if(sum == target)
                {
                    break;
                }
                else if(sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            // return summing indices in increasing order based on original array
            int first = min(sorted[left].second, sorted[right].second);
            int second = max(sorted[left].second, sorted[right].second);
            vector<int> res{first, second};
            return res;
        }
};
