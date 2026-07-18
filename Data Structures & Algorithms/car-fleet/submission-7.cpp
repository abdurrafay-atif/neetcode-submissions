class Solution 
{
    public:
        // time complexity: O(nlogn)
        // --> O(nlogn) for sorting
        // --> O(n) for main algorithm
        // space complexity: O(n) for stack
        int carFleet(int target, vector<int>& position, vector<int>& speed) 
        {
            // place all position-speed pairs into a vector of pairs
            // this is needed as the vector needs to be sorted
            // sorting is needed as this'll determine the order the cars are in
            // which makes determining car fleets more intuitive
            vector<pair<int, int>> cars;
            for(int i = 0; i < position.size(); i++)
            {
                cars.push_back({position[i], speed[i]});
            }
            // sort the cars vector to show how the cars are positioned in order
            // obviously, the cars are sorted by position
            sort(cars.begin(), cars.end());
            // stack to track cars that are behind the current
            // consists of position-speed pairs (parameter vectors)
            // whatever cars that are behind current will be removed...
            // if they can reach the current before the target
            // otherwise they remain on stack
            // # of items in the stack is the # of car fleets as the end result
            stack<pair<int, int>> st;
            for(int i = 0; i < cars.size(); i++)
            {
                // extract the current car at index i 
                pair<int, int> car_i = cars[i];
                // loop which runs through stack until it reaches a car...
                // which cannot reach the current car by the target
                // if stack is empty that means no prior cars, so stop iterating
                while(!st.empty())
                {
                    // obtain attributes of current car
                    int i_pos = car_i.first;
                    int i_speed = car_i.second;
                    // obtain car at the top of the stack & attributes
                    pair<int, int> car_top = st.top();
                    int top_pos = car_top.first;
                    int top_speed = car_top.second;
                    // calculation times which the cars take to reach the target
                    // this is used to determine whether previous can reach current
                    double i_time = (target - i_pos) / (double) i_speed;
                    double top_time = (target - top_pos) / (double) top_speed;
                    // if the car can be reached by the previous, pop from the stack
                    // this car is no longer on its own, it is part of the fleet
                    if(top_time <= i_time)
                    {
                        st.pop();
                    }
                    // if the car cannot be reached by previous
                    // it cannot join the car fleet with this car
                    // it may be able to join a further car that is slower
                    // but certainly not with this one
                    // so break out of loop as cannot process any further
                    else
                    {
                        break;
                    }
                }
                // always push current car to stack once loop above is done
                // so that it can be processed by cars ahead
                st.push(car_i);
            }
            return st.size();
        }
};
