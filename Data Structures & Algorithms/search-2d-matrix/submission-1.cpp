class Solution 
{
    public:
        // standard binary search
        int search(vector<int>& nums, int target) 
        {
            // pointers for left and right ends of array
            // these will shrink the bounds at every iteration
            int left = 0;
            int right = nums.size();
            // loop until pointers meet
            while(left <= right)
            {
                // calculate middle index of array
                int middle = left + ((right - left) / 2);
                // if element at this index search is done
                if(nums[middle] == target)
                {
                    return middle;
                }
                // if element small compared to target eliminate left half of array
                // this is done by moving left index to index after mid
                else if(nums[middle] < target)
                {
                    left = middle + 1;
                }
                // if element big compared to target eliminate right half of array
                // this is done by moving right index to index before mid
                else
                {
                    right = middle - 1;
                }
            }
            // if element not found return -1 to indicate such
            return -1;
        }

        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            // edge cases:
            // 1. target smaller than smallest element
            // 2. target larger than largest element
            if(target < matrix[0][0] || 
            target > matrix[matrix.size() - 1][matrix[matrix.size() - 1].size() - 1])
            {
                return false;
            }
            // pointers for binary search on rows of matrix
            int left_row = 0;
            int right_row = matrix.size();
            // perform binary search until correct row is found
            // then perform binary search on that row (done with standard binary search)
            while(left_row <= right_row)
            {
                // calculate middle index
                int mid_row = left_row + ((right_row - left_row) / 2);
                // determine if this is the correct row
                // done by determining if target is within bounds of this row
                if(matrix[mid_row][0] <= target && matrix[mid_row][matrix[mid_row].size() - 1] >= target)
                {
                    return search(matrix[mid_row], target) != -1;
                }
                // if the element is smaller than start element of mid_row 
                // eliminate right half of matrix rows
                else if(target < matrix[mid_row][0])
                {
                    right_row = mid_row - 1;
                }
                // if the element is larger than end element of mid_row
                // eliminate left half of matrix rows
                else if(target > matrix[mid_row][matrix[mid_row].size() - 1])
                {
                    left_row = mid_row + 1;
                }
            }
            // if above loop somehow exits the element cannot be found
            return false;
        }
};
