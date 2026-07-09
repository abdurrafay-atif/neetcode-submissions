class Solution 
{
    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            // set for checking duplicates
            unordered_set<char> dup_check;
            // check that rows are valid
            // clear set after each iteration
            for(auto i : board)
            {
                for(auto j : i)
                {
                    if(dup_check.find(j) != dup_check.end())
                    {
                        return false;
                    }
                    // ignore empty spaces
                    if(j != '.')
                    {
                        dup_check.insert(j);
                    }
                }
                dup_check.clear();
            }
            // check that cols are valid
            // clear set after each iteration
            for(int i = 0; i < board[0].size(); i++)
            {
                for(int j = 0; j < board.size(); j++)
                {
                    char curr = board[j][i];
                    if(dup_check.find(curr) != dup_check.end())
                    {
                        return false;
                    }
                    // ignore empty spaces
                    if(curr != '.')
                    {
                        dup_check.insert(board[j][i]);
                    }
                }
                dup_check.clear();
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
                            cout << curr << "\n";
                            if(dup_check.find(curr) != dup_check.end())
                            {
                                return false;
                            }
                            // ignore empty spaces
                            if(curr != '.')
                            {
                                dup_check.insert(board[k][l]);
                            }
                        }
                    }
                    dup_check.clear();
                }
            }
            return true;
        }
};
