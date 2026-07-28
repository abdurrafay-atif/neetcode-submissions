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

class Codec 
{
    public:

        string serialize(TreeNode* root) 
        {
            string encode;
            serializeHelper(root, &encode);
            return encode;
        }

        void serializeHelper(TreeNode *root, string *encode)
        {
            if(root == nullptr)
            {
                encode->append("N");
                return;
            }
            encode->append("#");
            encode->append(to_string(root->val));
            serializeHelper(root->left, encode);
            serializeHelper(root->right, encode);
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) 
        {
            cout << data << "\n";
            int ptr = 0;
            return deserializeHelper(data, &ptr);
        }

        TreeNode *deserializeHelper(string data, int *ptr)
        {
            if(data[*ptr] == 'N')
            {
                *ptr = *ptr + 1;
                return nullptr;
            }
            string num_string;
            // extract value
            do
            {
                *ptr = *ptr + 1;
                if(data[*ptr] == '#' || data[*ptr] == 'N')
                {
                    break;
                }
                num_string.push_back(data[*ptr]);
            }
            while(1);
            TreeNode *root = new TreeNode(stoi(num_string));
            root->left = deserializeHelper(data, ptr);
            root->right = deserializeHelper(data, ptr);
            return root;
        }
};
