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
        bool isSameTree(TreeNode* p, TreeNode* q) 
        {
            // both are null
            if(p == nullptr && q == nullptr)
            {
                return true;
            }
            // only one or the other is null but not both not the same tree
            else if(p == nullptr || q == nullptr)
            {
                return false;
            }
            // if neither are null
            // check that subtrees are same tree
            // also check that values are same
            return isSameTree(p->left, q->left) && 
                isSameTree(p->right, q->right) &&
                p->val == q->val;
        }
};
