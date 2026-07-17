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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
        {
            struct ListNode *dummy = new ListNode(0, nullptr);
            struct ListNode *trail = dummy;
            struct ListNode *curr1 = list1;
            struct ListNode *curr2 = list2;
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
            while(curr1 != nullptr)
            {
                trail->next = curr1;
                curr1 = curr1->next;
                trail = trail->next;
            }
            while(curr2 != nullptr)
            {
                trail->next = curr2;
                curr2 = curr2->next;
                trail = trail->next;
            }
            return dummy->next;
        }
};
