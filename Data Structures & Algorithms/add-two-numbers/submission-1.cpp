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
        struct ListNode *res = new ListNode(0);  // to be returned (front of list)
        struct ListNode *behind = nullptr;       // stays behind tracker
        struct ListNode *track = res;            // keep track of sum
        int carry = 0;                           // carry to be tracked 
        // loop to add corresponding digits
        // O(size of smaller list) loop, O(n) at worst case
        while(l1 != nullptr && l2 != nullptr)
        {   
            // sum used more than once so store its value for reusage
            int sum = l1->val + l2->val + carry;
            // calculate carry
            carry = (sum >= 10) ? 1 : 0;
            // update value
            track->val = sum % 10;
            // setup next ListNode pointer
            struct ListNode *next = new ListNode(0);
            // set the next pointer to be the next of the current pointer
            track->next = next;
            // set the tracker to the next pointer for each list
            behind = track;
            track = track->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // add rest of l1 (if remaining) [O(n) at worst case, if l1 >>>> l2 in size]
        while(l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = (sum >= 10) ? 1 : 0;
            track->val = sum % 10;
            struct ListNode *next = new ListNode(0);
            track->next = next;
            behind = track;
            track = track->next;
            l1 = l1->next;
        }
        // add rest of l2 (if remaining) [O(n) at worst case, if l2 >>>> l1 in size]
        while(l2 != nullptr)
        {
            int sum = l2->val + carry;
            carry = (sum >= 10) ? 1 : 0;
            track->val = sum % 10;
            struct ListNode *next = new ListNode(0);
            track->next = next;
            behind = track;
            track = track->next;
            l2 = l2->next;
        }
        // if carry still applies, add a new node with a 1 [O(1)]
        // otherwise, delete the tracker (unnecessary final node)
        if(carry)
        {
            track->val = 1;
        }
        else
        {
            delete track;
            behind->next = nullptr;
        }
        return res;
    }
};
