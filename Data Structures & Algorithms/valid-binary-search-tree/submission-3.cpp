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
        // time complexity: O(n)
        // space complexity: O(n)
        bool isValidBST(TreeNode* root) 
        {
            // global for tracking across recursive calls
            bool is_valid = true;
            isValidBSTHelper(root, INT_MIN, INT_MAX, &is_valid);
            return is_valid;
        }

        // function requires mins & maxes for determining bounds
        // these bounds determine if current node is valid
        void isValidBSTHelper(TreeNode *root, int min, int max, bool *is_valid)
        {
            // base case, null node, return prematurely
            if(root == nullptr)
            {
                return;
            }
            // if root value outside of range given by parameters
            // this node violates BST
            if(root->val <= min || root->val >= max)
            {
                *is_valid = false;
            }
            // call left & right subtrees to check their validity
            // left node --> update maximum
            // right node --> update minimum
            isValidBSTHelper(root->left, min, root->val, is_valid);
            isValidBSTHelper(root->right, root->val, max, is_valid);
        }
};
