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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        {
            int smaller = p->val < q->val ? p->val : q->val;
            int bigger = p->val > q->val ? p->val : q->val;
            TreeNode *curr = root;
            while(curr != nullptr)
            {
                int val = curr->val;
                // if smaller is smaller than current
                // and bigger is bigger than current
                // then this must be the LCA
                // as this is the lowest ancestor common to these values
                if(val >= smaller && val <= bigger)
                {
                    return curr;
                }
                // if both are smaller search left subtree
                // LCA can be lower & smaller values always in left
                else if(smaller < val && bigger < val)
                {
                    curr = curr->left;
                }
                // if both are bigger search right subtree
                // LCA can be lower & bigger values always in right
                else
                {
                    curr = curr->right;
                }
            }
            // placeholder
            return nullptr;
        }
};
