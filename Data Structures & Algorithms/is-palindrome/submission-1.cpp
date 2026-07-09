class Solution 
{
    public:
        bool isPalindrome(string s) 
        {
            // form new string with only alphanumeric characters
            // O(n) loop
            string s2;
            for(auto c : s)
            {
                if(isalnum(c))
                {
                    s2.push_back(c);
                }
            }
            // two pointers
            int left = 0;
            int right = s2.length() - 1;
            // loop until pointers meet
            // elements at s[left] & s[right] must match for palindrome
            // this is because palindromes read same from left & right side
            // so the path must be the same at both ends
            // if not returns false prematurely
            // otherwise returns true at the end
            // note: no need to check middle element if only one
            // this is because a single middle element matches with itself
            // O(n) loop, as loops through half the characters at worst case
            while(left <= right)
            {
                // check
                // case-insensitive to make letters lowercase for check
                if(tolower(s2[left]) != tolower(s2[right]))
                {
                    return false;
                }
                // move pointers
                left++;
                right--;
            }
            return true;
        }
};
