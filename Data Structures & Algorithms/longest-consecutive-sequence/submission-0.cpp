class Solution 
{
    public:
        // brute force solution... 
        // O(n^2) time complexity, 
        // O(n^2) space complexity
        int longestConsecutive(vector<int>& nums) 
        {
            // edge cases 
            if(nums.size() <= 1)
            {
                return nums.size();
            }
            // push all elements of the array to a min-heap
            // this is used to determine consecutive sequences
            // O(nlogn) loop, n = # of elements in nums
            priority_queue<int, vector<int>, greater<int>> res;
            for(auto i : nums)
            {
                res.push(i);
            }
            cout << "\n";
            // setup for checking consecutive elements
            int longest = 0;        // to be returned
            int consecutive = 1;    // current consecutive total
            // element to be compared
            // C++ doesn't pop with variable so must used .top()
            int prev = res.top();   
            res.pop();
            // O(nlogn) loop, n = # of elements in nums
            while(!res.empty())
            {
                // current element... must also use .top() then .pop() here
                // need to also pop() element as per C++ priority queue
                int top = res.top();  
                int curr = top - prev; 
                res.pop();
                // check if the above result is 1 (means it is consecutive)
                if(curr == 1)
                {
                    consecutive++;
                }
                // if not (and elements aren't equal), reset consecutive counter to 0
                // set longest if this run was the longest
                else if(curr != 0 && curr != 1)
                {
                    if(consecutive > longest)
                    {
                        longest = consecutive;
                    }
                    consecutive = 1;
                }
                // save previous top for next iteration
                prev = top;
        
            }
            return consecutive > longest ? consecutive : longest; 
        }
};
