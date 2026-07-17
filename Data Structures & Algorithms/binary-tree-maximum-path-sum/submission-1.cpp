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
            int max_pathsum = INT_MIN;
            maxPathHelper(root, &max_pathsum);
            return max_pathsum;
        }

        int maxPathHelper(TreeNode *root, int *max_pathsum)
        {
            if(root == nullptr)
            {
                return 0;
            }
            int left_sum = maxPathHelper(root->left, max_pathsum);
            int right_sum = maxPathHelper(root->right, max_pathsum);
            int total_left_only = left_sum + root->val;
            int total_right_only = right_sum + root->val;
            int total = total_left_only + total_right_only - root->val;
            int pathsum = max({total_left_only, total_right_only, total, root->val});
            *max_pathsum = max(pathsum, *max_pathsum);
            return max({total_left_only, total_right_only, root->val});
        }

};
