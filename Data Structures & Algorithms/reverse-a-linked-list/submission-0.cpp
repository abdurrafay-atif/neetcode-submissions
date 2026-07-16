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
        ListNode* reverseList(ListNode* head) 
        {
            // pointer for traversing list
            struct ListNode *curr = head;  
            // pointer for keeping track of the prior element
            // this is the element that the current's next will be assigned to
            // this reverses the direction of pointers...
            // upon rearranging next from the old, forward next     
            struct ListNode *prev = nullptr;  
            // loop until LL has been fully traversed
            // this is when we reach a null pointer, signal for end of list 
            while(curr != nullptr)
            {
                // hold the next pointer of the current node
                // since curr's pointer will be re-assigned to the previous
                // we will lose access to curr->next
                // so we temporarily store it here so we can traverse the list
                struct ListNode *temp = curr->next;
                // reverse the direction of the next pointer of current
                // this is the "reversal" action
                curr->next = prev;
                // update the previous for the next iteration
                // done prior to updating curr so it is correctly assigned
                prev = curr;
                // update the current to the original next element
                // standard list traversal line of code 
                curr = temp;
            }
            // the front of the list is now the previous pointer
            // since the previous pointer is always one behind the current
            // this'll mean technically prev is the new front
            // due to all the reversed pointers
            return prev;
        }
};
