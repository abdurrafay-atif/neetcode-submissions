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
            int goodNodes = 0;
            goodNodesHelper(root, INT_MIN, &goodNodes);
            return goodNodes;
        }

        void goodNodesHelper(TreeNode *root, int minimum, int *goodNodes)
        {
            // base case
            if(root == nullptr)
            {
                return;
            }
            // check for good node
            if(root->val >= minimum)
            {
                *goodNodes = *goodNodes + 1;
                minimum = root->val;
            }
            // DFS (pre-order)
            goodNodesHelper(root->left, minimum, goodNodes);
            goodNodesHelper(root->right, minimum, goodNodes);
        }
};
