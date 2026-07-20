class Solution 
{
    public:
        int numRescueBoats(vector<int>& people, int limit) 
        {
            // sort the list of people
            // this allows pointers to easily pair small weights with big weights
            // which is the optimal strategy here
            sort(people.begin(), people.end());
            // two pointers loop
            // if sum of weights is greater than limit, update bigger
            // if sum of weights less than or equal to limit, update both pointers
            // update total number of boats at each iteration
            int left = 0;
            int right = people.size() - 1;
            int num_boats = 0;
            while(left <= right)
            {
                int sum = people[left] + people[right];
                if(sum <= limit)
                {
                    left++;
                    right--;
                }
                else
                {
                    right--;
                }
                num_boats++;
            }
            return num_boats;
        }
};