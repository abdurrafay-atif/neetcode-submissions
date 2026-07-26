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
        bool isValidBST(TreeNode* root) 
        {
            return isValidBST(root, INT_MIN, INT_MAX);
        }

        bool isValidBST(TreeNode *root, int minimum, int maximum)
        {
            // empty tree is valid BST
            if(root == nullptr)
            {
                return true;
            }
            // check for BST tree
            if(root->val <= minimum || root->val >= maximum)
            {
                return false;
            }
            // DFS (pre-order)
            return isValidBST(root->left, minimum, root->val)
                && isValidBST(root->right, root->val, maximum);
        }
};
