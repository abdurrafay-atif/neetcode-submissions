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
        void reorderList(ListNode* head) 
        {
            // find middle element
            struct ListNode *slow = head;
            struct ListNode *fast = head;
            while(fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            // reverse second half of list
            struct ListNode *curr = slow;
            struct ListNode *prev = nullptr;
            while(curr != nullptr)
            {
                struct ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            // perform re-ordering of list
            // always save next pointers of rev & front
            // set front->next to rev
            // set rev->next to saved pointer of front->next
            // set front to saved pointer for next iteration
            // set rev to saved pointer for next iteration
            // note if rev is being pointed to itself
            // this is edge case and what should happen is it should point to null
            struct ListNode *front = head;
            struct ListNode *rev = prev; // prev is the front of the reversed list
            while(front != nullptr && rev != nullptr)
            {
                struct ListNode *front_next = front->next;
                struct ListNode *rev_next = rev->next;
                front->next = rev;
                rev->next = rev == front_next ? nullptr : front_next;
                front = front_next;
                rev = rev_next;
            }
        }
};
