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
        int goodNodes(TreeNode* root) 
        {
            int num_good_nodes = 0;
            goodNodesHelper(root, INT_MIN, &num_good_nodes);
            return num_good_nodes;
        }

        void goodNodesHelper(TreeNode *root, int min, int *num_good_nodes)
        {
            if(root == nullptr)
            {
                return;
            }
            if(root->val >= min)
            {
                min = root->val;
                *num_good_nodes = *num_good_nodes + 1;
            }
            goodNodesHelper(root->left, min, num_good_nodes);
            goodNodesHelper(root->right, min, num_good_nodes);
        }
};
