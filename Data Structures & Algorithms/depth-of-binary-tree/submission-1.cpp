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
        int maxDepth(TreeNode* root) 
        {
            // base case, empty subtree which has depth 0
            if(root == nullptr)
            {
                return 0;
            }
            // can determine depth by adding 1 (for root)
            // and maximum of depths of two subtrees
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
};
