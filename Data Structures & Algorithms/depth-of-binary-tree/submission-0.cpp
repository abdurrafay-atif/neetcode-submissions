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
        int maxDepth(TreeNode* root) 
        {
            // edge case, empty tree, return 0
            if(root == nullptr)
            {
                return 0;
            }
            // call helper function to keep track of depths
            return maxDepthHelper(root, 0);
        }

        int maxDepthHelper(TreeNode *root, int depth)
        {
            // base case: reached nullptr
            // perform backtracking
            // depth here is # of nodes tracked till this point
            if(root == nullptr)
            {
                return depth;
            }
            // return maximum of depths of the two nodes
            // this'll backtrack all the way to the top
            return max(maxDepthHelper(root->left, depth + 1), 
                maxDepthHelper(root->right, depth + 1));
        }
};
