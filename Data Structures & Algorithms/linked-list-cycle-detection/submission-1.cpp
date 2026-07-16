/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution 
{
    public:
        // time complexity: O(n), n = # of elements in the list
        // space complexity: O(1)
        bool hasCycle(ListNode* head) 
        {
            // fast / slow pointer technique for checking cycles
            struct ListNode *fast = head;
            struct ListNode *slow = head;
            // loop until the list ends
            // since fast pointer traverses at twice the rate...
            // must check that both fast & its next are non-null before proceeding
            // if loop reaches nullptr it is safe to say there is no cycle
            // if loop eventually ends up with fast & slow pointers at same address
            // this means there is a cycle, as there is no other way
            // the slow & fast pointer could have possibly met
            while(slow != nullptr && fast != nullptr && fast->next != nullptr)
            {   
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow)
                {
                    return true;
                }
            }
            return false;
        }
};
