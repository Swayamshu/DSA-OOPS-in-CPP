// https://leetcode.com/problems/n-queens/description/

vector<vector<string> > ans;
vector<string> board;

bool isSafe(int row, int col, int n)
{
    for (int j = 0; j < n; j++)
        if (board[row][j] == 'Q')
            return false;
    for (int i = row, j = col; 0 <= i && 0 <= j; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i < n && 0 <= j; i++, j--)
        if (board[i][j] == 'Q')
            return false;
    return true;
}

void solve(int col, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string> > solveNQueens(int n)
{
    ans.clear();
    board.assign(n, string(n, '.'));
    solve(0, n);
    return ans;
}