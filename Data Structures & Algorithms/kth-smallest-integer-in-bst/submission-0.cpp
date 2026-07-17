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
        int count = 0;
        int kth_smallest;
        kthSmallestHelper(root, k, &count, &kth_smallest);
        return kth_smallest;
    }

    void kthSmallestHelper(TreeNode *root, int k, int *count, int *kth_smallest)
    {
        if(root == nullptr)
        {
            return;
        }
        kthSmallestHelper(root->left, k, count, kth_smallest);
        *count = *count + 1;
        if(*count == k)
        {
            *kth_smallest = root->val;
        }
        kthSmallestHelper(root->right, k, count, kth_smallest);
    }
};
