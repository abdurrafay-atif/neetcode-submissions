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
        // time complexity: O(n)
        // space complexity: O(1)
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
        {
            // dummy node for holding the start of the new list
            // this is necessary for creating a new list consisting
            // of prior constructed nodes from parameter lists
            // we hold this element so the head can be stored later
            // since first element consists of a dummy, need to return its next
            struct ListNode *dummy = new ListNode(0, nullptr);
            struct ListNode *trail = dummy; // used for extending list
            struct ListNode *curr1 = list1; // used for traversing list1
            struct ListNode *curr2 = list2; // used for traversing list2
            // list comparison; always add smaller element to keep sorted order
            // move the list whose element has been added and always move trail
            while(curr1 != nullptr && curr2 != nullptr)
            {
                if(curr1->val < curr2->val)
                {
                    trail->next = curr1;
                    curr1 = curr1->next;
                }
                else
                {
                    trail->next = curr2;
                    curr2 = curr2->next;
                }
                trail = trail->next;
            }
            // add remaining of list1
            while(curr1 != nullptr)
            {
                trail->next = curr1;
                curr1 = curr1->next;
                trail = trail->next;
            }
            // add remaining of list2
            while(curr2 != nullptr)
            {
                trail->next = curr2;
                curr2 = curr2->next;
                trail = trail->next;
            }
            // since first element is a dummy must return its next
            return dummy->next;
        }
};
