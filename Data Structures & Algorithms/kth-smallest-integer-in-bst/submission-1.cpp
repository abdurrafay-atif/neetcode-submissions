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
        int kthSmallest(TreeNode* root, int k) 
        {
            int res = -1;
            return kthSmallestHelper(root, &k, &res);
        }

        int kthSmallestHelper(TreeNode *root, int *k, int *res)
        {
            // base case
            if(root == nullptr || *res != -1)
            {
                return *res;
            }   
            kthSmallestHelper(root->left, k, res);
            if(*k != 0)
            {
                *k = *k - 1;
            }
            if(*k == 0 && *res == -1) // can do this as node.val >= 0
            {
                *res = root->val;
            }
            kthSmallestHelper(root->right, k, res);
            return *res;
        }
};
