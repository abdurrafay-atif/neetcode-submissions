class Solution 
{
    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            // bits for checking duplicates
            // LSB 10 bits of int are the dup_checker [O(1) space]
            int dup_check = 0;
            // check that rows are valid using bit manipulation
            // clear set after each iteration
            for(auto i : board)
            {
                for(auto j : i)
                {
                    if((dup_check >> (j - '0')) & 1)
                    {
                        return false;
                    }
                    // ignore '.' characters
                    if(j != '.')
                    {
                        dup_check |= (1 << (j - '0'));
                    }
                }
                dup_check = 0;
            }
            // check that cols are valid using bit manipulation
            // clear set after each iteration
            for(int i = 0; i < board[0].size(); i++)
            {
                for(int j = 0; j < board.size(); j++)
                {
                    char curr = board[j][i];
                    if((dup_check >> (curr - '0')) & 1)
                    {
                        return false;
                    }
                    // ignore empty spaces
                    if(curr != '.')
                    {
                        dup_check |= (1 << (board[j][i] - '0'));
                    }
                }
                dup_check = 0;
            }
            // check that 3x3 grids are valid
            // clear set after each iteration
            // note this loop, despite being 4 deep...
            // takes same time as previous three loops
            for(int i = 0; i < board.size(); i += 3)
            {
                for(int j = 0; j < board[0].size(); j += 3)
                {
                    for(int k = i; k < (i + 3); k++)
                    {
                        for(int l = j; l < (j + 3); l++)
                        {
                            char curr = board[k][l];
                            if((dup_check >> (curr - '0')) & 1)
                            {
                                return false;
                            }
                            // ignore empty spaces
                            if(curr != '.')
                            {
                                dup_check |= (1 << (curr - '0'));
                            }
                        }
                    }
                    dup_check = 0;
                }
            }
            return true;
        }
};
