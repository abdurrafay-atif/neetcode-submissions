/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution 
{
    public:
        int maxPathSum(TreeNode* root) 
        {
            int max_sum = INT_MIN;
            maxPathSumHelper(root, &max_sum);
            return max_sum;
        }

        int maxPathSumHelper(TreeNode *root, int *max_sum)
        {   
            if(root == nullptr)
            {
                return 0;
            }
            int left_sum = maxPathSumHelper(root->left, max_sum);
            int right_sum = maxPathSumHelper(root->right, max_sum);
            int left_sum_with_root = left_sum + root->val;
            int right_sum_with_root = right_sum + root->val;
            int tot_sum = left_sum + right_sum + root->val;
            *max_sum = max({left_sum_with_root, right_sum_with_root, tot_sum, root->val, *max_sum});
            // don't consider tot sum as for upper trees this'll result in repeated nodes
            return max({left_sum_with_root, right_sum_with_root, root->val}); 
        }
};
