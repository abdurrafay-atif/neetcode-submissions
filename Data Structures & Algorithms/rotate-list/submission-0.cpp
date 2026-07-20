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
        ListNode* rotateRight(ListNode* head, int k) 
        {
            // handle edge cases
            // in these cases k doesn't really matter
            if(head == nullptr || head->next == nullptr)
            {
                return head;
            }
            // find length of list
            // stop when reach the end
            // the end will be connected to the front of the old list
            int length = 0;
            struct ListNode *end = head;
            while(end->next != nullptr)
            {
                length++;
                end = end->next;
            }
            // do k % length to get rotation based on length of list
            // do +1 as technically there was one node not accounted for
            int rotation = k % (length + 1);
            // if rotation equals 0 no need to do the rest of the algorithm
            if(rotation == 0)
            {
                return head;
            }
            // traverse list until reach node of new end based on rotation
            // keep track of previous as this'll be new head
            // new_head will obviously be new head
            struct ListNode *new_head = head;
            struct ListNode *prev = nullptr;
            int index = 0;
            while(index != (length - rotation + 1))
            {
                index++;
                prev = new_head;
                new_head = new_head->next;
            }
            // make the previous the new end (by setting its next to nullptr)
            // make the new head the new head
            // make the end that was found earlier point to the new head
            prev->next = nullptr;
            end->next = head;
            return new_head;
        }
};