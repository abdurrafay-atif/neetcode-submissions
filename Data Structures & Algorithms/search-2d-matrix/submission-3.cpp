class Solution 
{
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) 
        {
            // edge cases: target outside range of matrix
            if(matrix[0][0] > target || matrix[matrix.size() - 1][matrix[0].size() - 1] < target)
            {
                return false;
            }
            // binary search on rows
            int left_r = 0;
            int right_r = matrix.size();
            while(left_r <= right_r)
            {
                int mid_r = left_r + (right_r - left_r) / 2;
                int mid_r_leftmost = matrix[mid_r][0];
                int mid_r_rightmost = matrix[mid_r][matrix[mid_r].size() - 1];
                // perform binary search on this row if target possibly within it
                if(mid_r_leftmost <= target && mid_r_rightmost >= target)
                {
                    int left_c = 0;
                    int right_c = matrix[mid_r].size();
                    while(left_c <= right_c)
                    {
                        int mid_c = left_c + (right_c - left_c) / 2;
                        int val = matrix[mid_r][mid_c];
                        if(target == val)
                        {
                            return true;
                        }
                        else if(target < val)
                        {
                            right_c = mid_c - 1;
                        }
                        else
                        {
                            left_c = mid_c + 1;
                        }
                    }
                    return false;
                } 
                else if(target < mid_r_leftmost)
                {
                    right_r = mid_r - 1;
                }
                else
                {
                    left_r = mid_r + 1;
                }
            }
            return false;
        }
};
