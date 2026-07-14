class Solution 
{
    public:
        int evalRPN(vector<string>& tokens) 
        {
            int tok1 = 0;
            int tok2 = 0;
            stack<int> toks;
            for(auto i : tokens)
            {
                if((i[0] == '+' || (i[0] == '-' && i.size() == 1) || i[0] == '*' || i[0] == '/'))
                {
                    tok1 = toks.top();
                    toks.pop();
                    tok2 = toks.top();
                    toks.pop();
                    int res = 0;
                    switch(i[0])
                    {
                        case '+':
                            res = tok2 + tok1;
                            break;
                        case '-':
                            res = tok2 - tok1;
                            break;
                        case '*':
                            res = tok2 * tok1;
                            break;
                        case '/':
                            res = tok2 / tok1;
                            break;
                    }
                    toks.push(res);
                }
                else
                {
                    toks.push(stoi(i));
                }
            }
            return toks.top();
        }
};
