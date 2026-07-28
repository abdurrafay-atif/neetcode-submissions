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
    private:
        int pre_index = 0;
        unordered_map<int, int> indices;

        TreeNode *divide(vector<int> &preorder, int left, int right)
        {
            // if reached end of the line then this is a null node
            if(left > right)
            {
                return nullptr;
            }
            // obtain root
            int root_val = preorder[pre_index++];
            TreeNode *root = new TreeNode(root_val);
            // determine location of root in inorder traversal
            int mid = indices[root_val];
            // recursively build left & right subtrees
            root->left = divide(preorder, left, mid - 1);
            root->right = divide(preorder, mid + 1, right);
            return root;
        }

    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
        {
            // build hashmap of value index pairs for fast inorder index lookup
            for(int i = 0; i < inorder.size(); i++)
            {
                indices[inorder[i]] = i;
            }
            // call to helper function
            return divide(preorder, 0, inorder.size() - 1);
        }
};
