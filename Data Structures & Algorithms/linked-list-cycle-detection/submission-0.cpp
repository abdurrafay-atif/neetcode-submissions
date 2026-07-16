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
        bool hasCycle(ListNode* head) 
        {
            struct ListNode *fast = head;
            struct ListNode *slow = head;
            while(slow != nullptr && fast != nullptr && fast->next != nullptr)
            {   
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow)
                {
                    return true;
                }
            }
            return false;
        }
};
