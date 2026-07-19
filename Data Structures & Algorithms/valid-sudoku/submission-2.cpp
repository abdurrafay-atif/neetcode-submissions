class Solution 
{
    public:
        bool isValidSudoku(vector<vector<char>>& board) 
        {
            // unordered set of each row for duplicate checking
            vector<unordered_set<char>> rows(board.size());
            // unordered set of each column for duplicate checking
            vector<unordered_set<char>> cols(board[0].size());
            // unordered set of each row for duplicate checking
            // can obtain square of a row-col element by dividing the
            // row / col by 3 (since each square is 3x3)
            vector<vector<unordered_set<char>>> squares(board.size() / 3);
            for(auto &row : squares)
            {
                row.resize(board[0].size() / 3);
            }
            // loop
            for(int row = 0; row < board.size(); row++)
            {
                for(int col = 0; col < board[row].size(); col++)
                {
                    // extract current character
                    char curr = board[row][col];
                    // check if it is a duplicate in any set
                    if(rows[row].find(curr) != rows[row].end() ||
                        cols[col].find(curr) != cols[col].end() ||
                        squares[row / 3][col / 3].find(curr) != squares[row / 3][col / 3].end())
                    {
                        return false;
                    }
                    // add character if it is a numerical value to all corresponding sets
                    if(curr != '.')
                    {
                        rows[row].insert(curr);
                        cols[col].insert(curr);
                        squares[row / 3][col / 3].insert(curr);
                    }
                }
            }
            return true;
        }
};
