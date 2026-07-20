class Solution 
{
    public:
        bool isPalindrome(string s) 
        {
            // normalize string
            string pal;
            for(auto c : s)
            {
                if(isalnum(c))
                {
                    pal.push_back(tolower(c));
                }
            }
            // algorithm
            int left = 0;
            int right = pal.length() - 1;
            while(left < right)
            {
                if(pal[left] != pal[right])
                {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
};
