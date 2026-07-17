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
        int diameterOfBinaryTree(TreeNode* root) 
        {
            // diameter stored variable which is present across entire recursive solution
            // this is passed as a pointer to the recursive helper
            // this allows all recursive calls to access same variable
            // thus each call can determine a new maximum diameter
            int diameter = 0;
            diameterHelper(root, &diameter);
            return diameter;
        }

        int diameterHelper(TreeNode *root, int *diameter)
        {
            // base case, root is null
            // a null pointer has a depth of 0
            if(root == nullptr)
            {
                return 0;
            }
            // determine the left end depth recursively
            int left_depth = diameterHelper(root->left, diameter);
            // determine the right end depth recursively
            int right_depth = diameterHelper(root->right, diameter);
            // diameter of this subtree is longest path between any two nodes
            // this is maximized by using the max depth of left & right subtrees...
            // and summing them together
            // using global diameter passed as parameter we can always see...
            // if this path exceeds the current maximum and update as needed
            *diameter = max(left_depth + right_depth, *diameter);
            // increase the depth as we scale back up the tree
            // by adding 1 to both ends
            // we only care about max depth as we go back up, so use such function
            return max(left_depth + 1, right_depth + 1);
        }

};
