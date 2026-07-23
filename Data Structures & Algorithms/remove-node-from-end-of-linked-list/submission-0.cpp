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
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            // obtain size of list
            struct ListNode *curr1 = head;
            int size = 0;
            while(curr1 != nullptr)
            {
                size++;
                curr1 = curr1->next;
            }
            // determine index where deletion should occur
            int del = size - n;
            // edge case: need to delete node at the start
            // simply return the next of the head (same as deleting first node)
            if(del == 0)
            {
                return head->next;
            }
            // delete nth node from end of list
            // need the following:
            // 1. curr_index --> for tracking index. when reaches del will delete
            // 2. prev node, so we know which node we need to use to delete nth node
            // 3. curr node, for traversal
            int curr_index = 0;
            struct ListNode *curr2 = head;
            struct ListNode *prev = nullptr;
            while(curr_index != del)
            {
                prev = curr2;
                curr2 = curr2->next;
                curr_index++;
            }
            prev->next = curr2->next;
            return head;
        }
};
