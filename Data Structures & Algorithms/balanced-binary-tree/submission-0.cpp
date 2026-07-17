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
        bool isBalanced(TreeNode* root) 
        {
            // global variable for checking balance
            bool is_balanced = true;
            isBalancedHelper(root, &is_balanced);
            return is_balanced;
        }

        int isBalancedHelper(TreeNode *root, bool *is_balanced)
        {
            if(root == nullptr)
            {
                return 0;
            }
            int left_height = isBalancedHelper(root->left, is_balanced);
            int right_height = isBalancedHelper(root->right, is_balanced);
            if(abs(left_height - right_height) > 1)
            {
                *is_balanced = false;
            }
            return max(left_height + 1, right_height + 1);
        }

};
