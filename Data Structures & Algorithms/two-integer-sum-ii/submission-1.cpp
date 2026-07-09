class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        // two pointers
        int left = 0;
        int right = numbers.size() - 1;
        // loop
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
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
        return vector<int> {left + 1, right + 1};
    }
};
