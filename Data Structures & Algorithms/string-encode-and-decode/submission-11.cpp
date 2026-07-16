class Solution 
{
    private:
        vector<int> strlens;    // tracks each string length

    public:
        string encode(vector<string>& strs) 
        {
            // append all characters in strs to res in order
            // track each string length for use in decode() function
            string res;
            for(auto s : strs)
            {
                strlens.push_back(s.length());
                for(auto c : s)
                {
                    res.push_back(c);
                }
            }
            return res;
        }

        vector<string> decode(string s) 
        {
            vector<string> res(strlens.size()); // result vector
            int s_index = 0;                    // track current index of string
            int str_index = 0;                  // track index of string lengths array
            int num_chars_added = 0;            // track characters added to check with strlen[str_index]
            // while(1) loop due to edge case that string could consist of nothing
            // but there may be empty strings in original array that was encoded
            // which may not appear in the encoded string
            while(1)
            {
                // edge case: empty string
                // this is not clearly shown in input string
                // thus if strlen array has empty string (0 length string)
                // then just move along and  increment the str_index to move to next string
                // while loop as there could be multiple in a row
                // do not run if have already gone through every string
                while(str_index < strlens.size() && strlens[str_index] == 0) 
                {
                    str_index++;
                }
                // break out of loop if reached end of the string
                if(s_index >= s.length())
                {
                    break;
                }
                // obtain current character
                char c = s[s_index++];
                // append character to current string
                // increment # of characters added to check if string is done later
                res[str_index].push_back(c);
                num_chars_added++;
                // if reached end of string
                // move to next string
                if(num_chars_added == strlens[str_index])
                {
                    str_index++;
                    num_chars_added = 0;
                }
            }
            // empty out strlens array for future usages of these functions
            strlens.clear();
            return res;
        }
};
