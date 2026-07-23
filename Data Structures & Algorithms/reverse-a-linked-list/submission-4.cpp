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
        // how does recursion work?
        // for every recursive call, we are working on a "sub-problem"
        // that is, we see how each call resembles each other
        // reversing a linked list... the values in the nodes DO NOT MATTER!
        // we treat each reversal like this:
        // 1. we have a node connected to a larger list
        // 2. the rest of the list is already reversed
        // so we just need to reverse this single node
        // note that in each case, the next node's next points to null
        // this is because the rest of the list is reversed in a standard way
        // where the reversed list ends in null (like a normal list)
        // so we need to set the next's next to point to the current
        // and then set the current's next to null
        // so we can reverse the current element
        // two more problems:
        // 1. what is the base case?
        // --> this is when the head's next is null
        // --> here we do not perform the recursive call
        // 2. how do we bring the new head to the front
        // --> when we reach the end of the list, we save the new head 
        // --> this is done by setting a new head pointer as the return value
        // --> this'll trace back to the start of the recursion call stack
        // note that this solution actually requires more space
        // so despite being mentally taxing on the brain it is a crappy
        // solution compared to the iterative which is not as hard to think about
        ListNode* reverseList(ListNode* head) 
        {
            // edge case: empty list
            // the constraints include 0 as a list size, so we need this
            if(head == nullptr)
            {
                return nullptr;
            }
            // save our current head
            // this MAY or MAY NOT BE the end of the list
            // we don't know right now, we'll find out later
            struct ListNode *front = head;
            // BASE CASE: if we are not at the end of the list, continue recursion loop
            // if we are at end of list, we stop recursing
            // we stop at the element right before null because we need to save 
            // the current front as our new head
            if(head->next != nullptr)
            {
                // continue recursion calls
                // when recursion ends, this will be set to whatever was last element in list
                // this makes sense as that is the front of the reversed list
                front = reverseList(head->next);
                // set the next element's next to the current & the current's to null
                // this performs a "reversal" on this subproblem
                head->next->next = head;
                head->next = nullptr;
            }
            // return the front which will recurse back and be returned
            return front;
        }
};
