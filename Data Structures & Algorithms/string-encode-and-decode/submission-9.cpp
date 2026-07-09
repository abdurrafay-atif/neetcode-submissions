class Solution 
{
    public:
        // O(n) space, n = # of number of vector breaks
        vector<int> indices;
        int num_empty_strings;
        bool last_string_empty;
        bool array_empty;

        string encode(vector<string>& strs) 
        {
            // edge case: empty array
            if(strs.size() == 0)
            {
                string res;
                array_empty = true;
                return res;
            }
            array_empty = false;
            // edge case: last string is empty
            // if so need to force add it in decode()
            last_string_empty = strs[strs.size() - 1] == "";
            string res;    // result string... O(m) space
            int index = 0; // current index
            // loop through each string
            // O(m) loop, m = sum of lengths of all strings
            for(auto s : strs)
            {
                // append the current index to the global vector
                // this is where the strings break in the OG vector
                indices.push_back(index);
                // loop through each character of each string
                for(auto c : s)
                {
                    // append each character to the result string
                    res.push_back(c);
                    index++;
                }
                // increment variable if empty string
                if(s == "")
                {
                    num_empty_strings++;
                }
            }
            for(auto i : indices)
                cout << i << ",";
            cout << "\n";
            return res;
        }

        vector<string> decode(string s) 
        {
            // edge case, array was empty, return empty array
            if(array_empty)
            {
                vector<string> res;
                return res;
            }
            // edge case, empty string
            if(s.length() == 0)
            {
                vector<string> res;
                for(int i = 0; i < num_empty_strings; i++)
                {
                    res.push_back("");
                }
                cout << num_empty_strings << "\n";
                return res;
            }
            // result vector which should be the original vector from encode() function
            // O(m) + O(n) space... O(m + n) space
            vector<string> res;
            int curr_break = -1; // determine index of vector to track
            // need to track indices to determine vector breaks
            for(int index = 0; index < s.length(); index++)
            {   
                // determine if a break needs to happen
                // may run multiple times due to empty strings
                while(curr_break + 1 < indices.size() && index == indices[curr_break + 1])
                {
                    res.push_back("");
                    curr_break++;
                }
                // add to the current string
                res[curr_break].push_back(s[index]);
            }
            // clear out class variables
            indices.clear();
            num_empty_strings = 0;
            // add another empty string if it is indicated
            if(last_string_empty)
            {
                res.push_back("");
            }
            return res;
        }
};
