class Solution 
{
    public:
        // binary search solution
        vector<int> twoSum(vector<int>& numbers, int target) 
        {
            for(int i = 0; i < numbers.size(); i++)
            {
                int left = i + 1; 
                int right = numbers.size() - 1;
                int val = target - numbers[i];
                while(left <= right)
                {
                    int mid = left + (right - left) / 2;
                    if(val == numbers[mid])
                    {
                        return vector<int> {i + 1, mid + 1};
                    }
                    else if(val < numbers[mid]) // mid val too high
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
            return vector<int> {};
        }
};
