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
        ListNode* reverseKGroup(ListNode* head, int k) 
        {
            struct ListNode *curr = head;           // traversal
            struct ListNode *new_head = nullptr;    // used for return at the end
            struct ListNode *group_start = curr;    // indicates when a group starts for reversal
            struct ListNode *prev_gs = nullptr;     // keeps track of previous group start
            struct ListNode *prev_gs2 = nullptr;    // another one for some reason
            struct ListNode *prev = nullptr;        // element to attach reversed group's next
            int group_size = 0;                     // indicates when we've completed a group
            // loop runs until there are no more groups that can be processed
            // this is done when the current is null (check done inside loop)
            while(1)  
            {
                // if we've reached the group size, we start reversing the k-group
                if(group_size == k)
                {
                    // need to store for later
                    prev_gs2 = group_start;
                    // set the previous to the current
                    // the k-group as a whole's next is this element
                    prev = curr;
                    // perform reversal
                    while(group_start != curr)
                    {
                        struct ListNode *temp = group_start->next;
                        group_start->next = prev;
                        prev = group_start;
                        group_start = temp;
                    }
                    // set new_head for return later
                    if(new_head == nullptr)
                    {
                        new_head = prev;
                    }
                    // only set prior group to this group if it is non-null
                    // since null pointers cannot be accessed
                    if(prev_gs != nullptr)
                    {
                        prev_gs->next = prev;
                    }
                    // set the next prev_gs to what group start was earlier for next time
                    prev_gs = prev_gs2;
                    // reset group size for next k-group
                    group_size = 0;
                }
                // if the current is null, break out of the loop
                if(curr == nullptr)
                {
                    break;
                }
                // otherwise increase the group size and move the pointer
                curr = curr->next;
                group_size++;
            }
            // the new head is the front of the first reversed group
            return new_head;
        }
};
