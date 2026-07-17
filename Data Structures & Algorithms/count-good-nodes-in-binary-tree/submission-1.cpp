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
        int goodNodes(TreeNode* root) 
        {
            // use a global num_good_nodes tracker which can be accessed by call recursive calls
            int num_good_nodes = 0;
            goodNodesHelper(root, INT_MIN, &num_good_nodes);
            return num_good_nodes;
        }

        // helper function
        void goodNodesHelper(TreeNode *root, int min, int *num_good_nodes)
        {
            // base case
            if(root == nullptr)
            {
                return;
            }
            // determine if good node
            // if so, increment global count and set minimum for subtrees
            if(root->val >= min)
            {
                min = root->val;
                *num_good_nodes = *num_good_nodes + 1;
            }
            // recursively call subtrees
            goodNodesHelper(root->left, min, num_good_nodes);
            goodNodesHelper(root->right, min, num_good_nodes);
        }
};
