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
        bool isBalanced(TreeNode* root) 
        {
            // use a global variable for checking through all recursive calls
            bool is_balanced = true;
            isBalancedHelper(root, &is_balanced);
            return is_balanced;
        }

        int isBalancedHelper(TreeNode *root, bool *is_balanced)
        {
            // base case
            if(root == nullptr)
            {
                return 0;
            }
            // obtain left & right heights
            int left_height = isBalancedHelper(root->left, is_balanced);
            int right_height = isBalancedHelper(root->right, is_balanced);
            // determine if this subtree is balanced
            // if not, set is_balanced to false (confirms the whole tree as non-balanced)
            if(abs(left_height - right_height) > 1)
            {
                *is_balanced = false;
            }
            // scale up the tree, indicating max height where the tree goes deeper
            return max(left_height + 1, right_height + 1);
        }

};
