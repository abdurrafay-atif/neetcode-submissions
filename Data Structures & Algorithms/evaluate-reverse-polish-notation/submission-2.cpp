class Solution 
{
    public:
        int evalRPN(vector<string>& tokens) 
        {
            stack<int> toks;
            for(auto tok : tokens)
            {
                if(tok.length() == 1 && (tok[0] == '+' || 
                tok[0] == '-' || tok[0] == '*' || tok[0] == '/'))
                {
                    int tok1 = toks.top();
                    toks.pop();
                    int tok2 = toks.top();
                    toks.pop();
                    switch(tok[0])
                    {
                        case '+':
                            toks.push(tok2 + tok1);
                            break;
                        case '-':
                            toks.push(tok2 - tok1);
                            break;
                        case '*':
                            toks.push(tok2 * tok1);
                            break;
                        case '/':
                            toks.push(tok2 / tok1);
                            break;
                    }
                }
                else
                {
                    toks.push(stoi(tok));
                }
            }
            return toks.top();
        }
};
