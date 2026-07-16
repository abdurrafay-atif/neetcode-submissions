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
        // recursive O(n) solution with O(n) space for recursion
        // does not use a helper function
        ListNode* reverseList(ListNode* head) 
        {
            // base case: passed in node is nullptr
            // this happens when we've reached the end of the list
            // return nullptr as this should be the end of the new list
            if(head == nullptr)
            {
                return nullptr;
            }
            // keep track of the current head
            // this is the head of the "subproblem"
            // we want to reverse the "rest" of the list besides this pointer
            // after reversing the entire list, we set head's next to nullptr
            // thus effectively reversing this element also
            struct ListNode *new_head = head;
            // only continue recursive loop if not at end of list
            // if not at end of list, need to continue recursive loop
            if(head->next != nullptr)
            {
                // recursive loop
                // this will return a head 
                new_head = reverseList(head->next);
                // once recursive loop is done, the next element of head's...
                // pointer is reversed (hence double next)
                head->next->next = head;
            }
            // reverse this node
            head->next = nullptr;
            // return the new head for further recursive calls
            return new_head;
        }
};
