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
        // time complexity: O(n), n = max(size(list1), size(list2))
        // space complexity: O(1)
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
        {
            // edge case: both are empty list
            if(list1 == nullptr && list2 == nullptr)
            {
                return nullptr;
            }
            // form new list & hold pointer for traversal
            struct ListNode *head = new ListNode(0, nullptr);
            struct ListNode *trail = head;
            struct ListNode *prev = nullptr;    // need this for setting next of last element
            // pointers for traversing lists
            struct ListNode *curr1 = list1;
            struct ListNode *curr2 = list2;
            // loop across lists until reach one
            // add elements in ascending order (by comparison elements in lists)
            while(curr1 != nullptr && curr2 != nullptr)
            {
                // determine which value to place from the two lists
                // to keep it in sorted value, send smaller value first always
                // move pointer of list that was used
                if(curr1->val <= curr2->val)
                {
                    trail->val = curr1->val;
                    curr1 = curr1->next;
                }
                else
                {
                    trail->val = curr2->val;
                    curr2 = curr2->next;
                }
                // move trail for next iteration
                trail->next = new ListNode(0, nullptr);
                prev = trail;
                trail = trail->next;
            }
            // add remaining of list1
            while(curr1 != nullptr)
            {
                trail->val = curr1->val;
                curr1 = curr1->next;
                trail->next = new ListNode(0, nullptr);
                prev = trail;
                trail = trail->next;
            }
            // add remaining of list2
            while(curr2 != nullptr)
            {
                trail->val = curr2->val;
                curr2 = curr2->next;
                trail->next = new ListNode(0, nullptr);
                prev = trail;
                trail = trail->next;
            }
            // delete trail as this is an unnecessary final node
            delete trail;
            prev->next = nullptr;
            return head;
        }
};
