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
        int diameterOfBinaryTree(TreeNode* root) 
        {
            int diameter = 0;
            diameterOfBinaryTreeHelper(root, &diameter);
            return diameter - 1; // # of edges = # of nodes - 1
        }

        int diameterOfBinaryTreeHelper(TreeNode *root, int *diameter)
        {   
            if(root == nullptr)
            {
                return 0;
            }   
            int left_len = diameterOfBinaryTreeHelper(root->left, diameter);
            int right_len = diameterOfBinaryTreeHelper(root->right, diameter);
            int path_len = left_len + right_len + 1;
            *diameter = max(path_len, *diameter);
            return 1 + max(left_len, right_len);
        }
};
