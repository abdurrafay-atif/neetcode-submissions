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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            struct ListNode *dummy = new ListNode();    // handles front edge case
            struct ListNode *trail = dummy;             // used to form new list
            struct ListNode *curr1 = l1;                // used for addition
            struct ListNode *curr2 = l2;                // used for addition
            int carry = 0;                              // used when digit sum >= 10 (dec. add)
            while(curr1 != nullptr && curr2 != nullptr) // addition of corresponding elements of both lists
            {
                int sum = curr1->val + curr2->val + carry;      // calculate sum + carry
                carry = (sum >= 10);                            // re-calculate carry 
                trail->next = new ListNode(sum % 10);           // form new node to hold this sum
                trail = trail->next;                            // move to next node
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            while(curr1 != nullptr)                     // add remaining of l1
            {
                int sum = curr1->val + carry;
                carry = (sum >= 10);
                trail->next = new ListNode(sum % 10);
                trail = trail->next;
                curr1 = curr1->next;
            }
            while(curr2 != nullptr)                     // add remaining of l2
            {
                int sum = curr2->val + carry;
                carry = (sum >= 10);
                trail->next = new ListNode(sum % 10);
                trail = trail->next;
                curr2 = curr2->next;
            }
            if(carry)                                   // add carry node if there is still a carry
            {
                trail->next = new ListNode(carry);
            }
            return dummy->next;
        }
};
