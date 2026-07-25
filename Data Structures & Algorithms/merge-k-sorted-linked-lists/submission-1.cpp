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
        // priority queue solution
        // time complexity: O(nlogk)
        // --> looping through n total nodes
        // --> pqueue takes logk iterations for each use
        // --> pqueue has at most k elements at a time
        // space complexity: O(k) due to pqueue
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            // priority queue is sorted by node value
            // whenever element is extracted from it...
            // its list index is used to pair with the previous node extracted
            priority_queue<pair<int, int>, 
                vector<pair<int, int>>, greater<pair<int, int>>> pqueue;
            // dummy node to act as the front of the list
            ListNode *dummy = new ListNode(0);
            ListNode *trail = dummy;
            // loop through list and add first element of each to pqueue (if it exists)
            // note if a list consists of a null pointer it is skipped over
            // lists with null pointers are considered finished
            // this logic will apply to the main loop as well
            for(int i = 0; i < lists.size(); i++)
            {
                if(lists[i] != nullptr)
                {
                    pqueue.push({lists[i]->val, i});
                }
            }
            // loop until the priority queue is empty (means no more elements to add)
            while(!pqueue.empty())
            {
                // extract next smallest element & pop it from the queue
                pair<int, int> next = pqueue.top();
                pqueue.pop();
                // attach it to the merged sorted list based on index provided
                trail->next = lists[next.second];
                // move trail for the next element
                trail = trail->next;
                // move the corresponding list to the next node
                lists[next.second] = lists[next.second]->next;
                // if the new list hasn't ended yet, add the node to the pqueue
                if(lists[next.second] != nullptr)
                {
                    pqueue.push({lists[next.second]->val, next.second});
                }
            }
            // return next of dummy as that is the real start of the list
            return dummy->next;
        }
};
