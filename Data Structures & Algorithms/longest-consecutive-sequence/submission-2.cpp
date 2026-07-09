class Solution 
{
    public:
        // HashMap solution
        // 1. Build HashMap of elements in nums & their consecutive elements
        // 2. Loop through elements of HashMap
        // 3. Follow trail until an endpoint has been reached
        // 4. Keep doing this until the HashMap is empty
        // 5. Whichever trail had longest run is the answer to the problem
        // Time: O(n)
        // Space: O(n)
        int longestConsecutive(vector<int>& nums) 
        {
            // O(n) space, n = # of elements in nums
            unordered_set<int> elements;
            // O(n) loop, n = # of elements in nums
            for(auto i : nums)
            {
                elements.insert(i);
            }
            int longest = 0;
            // O(n) loop, n = # of elements in loop
            // Each HashSet element is only accessed once, then removed once reached
            while(!elements.empty())
            {
                // start the trail wherever the HashMap currently begins
                // remove the trail element as it has been accessed
                int trail_start = *elements.begin();
                elements.erase(trail_start);
                // trail trackers for counting upward & downward
                int trail_up = trail_start;
                int trail_down = trail_start;
                // track the current length
                int curr_trail_length = 1;
                // loop upwards until end of trail is reached
                while(elements.find(trail_up + 1) != elements.end())
                {
                    trail_up++;
                    curr_trail_length++;
                    elements.erase(trail_up);
                }
                // loop downwards until end of trail is reached
                while(elements.find(trail_down - 1) != elements.end())
                {
                    trail_down--;
                    curr_trail_length++;
                    elements.erase(trail_down);
                }
                // update longest length if it has been exceeded
                if(curr_trail_length > longest)
                {
                    longest = curr_trail_length;
                }
            }
            return longest;
        }
};
