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
        // time complexity: O(n), n = # of nodes in tree
        // space complexity: O(n)
        TreeNode* invertTree(TreeNode* root) 
        {
            // base case: reached a nullptr node
            // this is where we start backing up
            // just return this null pointer 
            if(root == nullptr)
            {
                return nullptr;
            }
            // since root->left will be updated here, we need to save root->left
            TreeNode *temp = root->left;
            // set each pointer to the inverted tree of the opposite pointer
            root->left = invertTree(root->right);
            root->right = invertTree(temp);
            // return the current node to bring back to parent node
            return root;
        }
};
