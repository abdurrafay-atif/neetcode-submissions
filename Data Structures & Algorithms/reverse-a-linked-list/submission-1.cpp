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
        ListNode* reverseList(ListNode* head) 
        {
            // uses the helper function due to the necessity of a previous pointer
            return reverseListHelper(nullptr, head);
        }
        
        // helper function for list reversal
        // requires previous & current pointers for reversing pointers
        ListNode *reverseListHelper(ListNode *prev, ListNode *curr)
        {
            // base case: end of list
            // return the previous pointer as this is the start of the reversed list
            if(curr == nullptr)
            {
                return prev;
            }
            // obtain temp of current's next for traversal later
            struct ListNode *temp = curr->next;
            // reverse pointer
            curr->next = prev;
            // move to next iteration, updating prev pointer on the way
            return reverseListHelper(curr, temp);
        }
};
