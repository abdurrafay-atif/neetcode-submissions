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
        // iterative solution:
        // loop through lists, always add smaller first
        // if reach end of list, append the remaining list
        // recursive solution:
        // subproblem: which list should we append? 
        // we end when one of the lists is done --> we append the non-null list
        // when recursing back, we append whichever list was supposed to be the next
        // this is based on same logic of always adding smaller first
        // we return the list same as at the end
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
        {
            // append list2 when list1 is done
            if(list1 == nullptr)
            {
                return list2;
            }
            // append list1 if list2 is done
            if(list2 == nullptr)
            {
                return list1;
            }
            // if list1 has the smaller element
            // the next element is from list1
            // and we return list1 for the prior recursive call
            // as this is the next for the previous
            if(list1->val <= list2->val)
            {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            // opposite case of above
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
};
