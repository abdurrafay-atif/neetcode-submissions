/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
    public:
        Node* copyRandomList(Node* head) 
        {
            // edge case: empty list, just return null pointer
            if(head == nullptr)
            {
                return nullptr;
            }
            // create pointer-index pairs for original list
            unordered_map<struct Node*, int> og_pairs;
            struct Node *curr = head;
            int size = 0;
            while(curr != nullptr)
            {
                og_pairs.insert({curr, size});
                curr = curr->next;
                size++;
            }
            // create "size" nodes which will represent the new list
            // place them in a HashMap with index as key to assign pointers later
            unordered_map<int, struct Node*> deep_copy;
            for(int i = 0; i < size; i++)
            {
                struct Node *new_node = new Node(0);
                deep_copy.insert({i, new_node});
            }
            // assign pointers based on indices
            curr = head;
            while(curr != nullptr)
            {
                // extract indices
                int curr_index = og_pairs[curr];
                int next_index = curr->next != nullptr ? og_pairs[curr->next] : -1;
                int rand_index = curr->random != nullptr ? og_pairs[curr->random] : -1;
                // extract node at corresponding index in deep copy
                struct Node *curr_copy = deep_copy[curr_index];
                // set val, next & random pointers based on index found in original node
                curr_copy->val = curr->val;
                curr_copy->next = next_index != -1 ? deep_copy[next_index] : nullptr;
                curr_copy->random = rand_index != -1 ? deep_copy[rand_index] : nullptr;
                // move the current pointer for next iteration
                curr = curr->next;
            }
            // // traverse copy
            // struct Node *test = deep_copy[0];
            // while(test != nullptr)
            // {
            //     int curr_val = test->val;
            //     int next_val = test->next != nullptr ? test->next->val : 0;
            //     int rand_val = test->random != nullptr ? test->random->val : 0;
            //     cout << curr_val << " : " << next_val << " : " << rand_val << "\n";
            //     test = test->next;
            // }
            // return first node of list (node associated with index 0)
            return deep_copy[0];
        }
};
