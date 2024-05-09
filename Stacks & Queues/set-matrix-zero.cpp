
void modifyMatrix(int &x, int &y, vector<vector<int> > &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
        matrix[i][y] = 0;
    for (int j = 0; j < matrix[0].size(); j++)
        matrix[x][j] = 0;
}

void setZeroes(vector<vector<int> > &matrix)
{
    queue<pair<int, int> > q;

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            if (matrix[i][j] == 0)
                q.push({i, j});

    while (!q.empty())
    {
        modifyMatrix(q.front().f, q.front().s, matrix);
        q.pop();
    }
}