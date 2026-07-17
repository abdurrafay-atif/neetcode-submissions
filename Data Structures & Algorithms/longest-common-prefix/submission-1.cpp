class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            string prefix = strs[0];
            int right = prefix.size();
            for(int i = 0; i < strs.size(); i++)
            {
                string s = strs[i];
                int c = 0;
                while(c < right)
                {
                    if(prefix[c] != s[c])
                    {
                        break;
                    }
                    c++;
                }
                right = c;
            }
            return prefix.substr(0, right);
        }
};