class Solution 
{
    public:

        string encode(vector<string>& strs) 
        {
            string res;
            for(auto s : strs)
            {
                res.append(to_string((int) s.length()));
                res.append("&");
                res.append(s);
            }
            return res;
        }

        vector<string> decode(string s) 
        {
            vector<string> res;
            int right = 0;
            while(right < s.length())
            {
                int left = right;
                while(s[right] != '&') 
                {
                    right++;
                };
                int length = stoi(s.substr(left, right - left));
                left = right + 1;
                right = left + length;
                res.push_back(s.substr(left, right - left));
            }
            return res;
        }
};
