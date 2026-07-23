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

class Solution {
public:
    bool hasCycle(ListNode* head) 
    {
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        while(slow != nullptr && head != nullptr && head->next != nullptr)
        {
            slow = slow->next;
            head = head->next->next;
            if(slow == head)
            {
                return true;
            }
        }
        return false;
    }
};
