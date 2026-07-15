class Solution 
{
    public:
        // time complexity: O(n)
        // space complexity: O(n)
        vector<int> dailyTemperatures(vector<int>& temperatures) 
        {
            // result vector
            vector<int> res(temperatures.size());
            // monotonic stack
            // this stores index-value pairs of the temperatures array
            // for every new temperature found, it pops off any recent colder temperatures
            // these are the temps for which result[i] != 0
            // if this doesn't occur for a temp that means result[i] = 0 for that temp
            // aka there is no warmer temperature after temp[i]
            stack<pair<int, int>> st;
            // loop across temperatures
            for(int i = 0; i < temperatures.size(); i++)
            {
                // update prior temperatures if they are colder than current one
                // top elements will have all prior elements for which there
                // could possibly be a smaller element due to nature of monotonic stack
                while(!st.empty() && st.top().second < temperatures[i])
                {
                    pair<int, int> curr_top = st.top();
                    res[curr_top.first] = i - curr_top.first;
                    st.pop();
                }
                st.push({i, temperatures[i]});
            }
            return res;
        }
};
