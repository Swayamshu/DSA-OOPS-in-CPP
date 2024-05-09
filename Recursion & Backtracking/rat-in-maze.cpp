// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

/*
Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
*/

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
char path_map[4] = {'R', 'D', 'L', 'U'};
vector<vector<int> > vis;

bool isValid(int i, int j, vector<vector<int> > &m, int n)
{
    return (0 <= i && i < n && 0 <= j && j < n && m[i][j] && !vis[i][j]);
}

void move(int i, int j, vector<vector<int> > &m, int n, vector<string> &ans, string &path)
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int x = i + di[k];
        int y = j + dj[k];

        if (isValid(x, y, m, n))
        {
            path.push_back(path_map[k]);
            vis[x][y] = 1;
            move(x, y, m, n, ans, path);
            vis[x][y] = 0;
            path.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int> > &m, int n)
{
    vector<string> ans;
    vis.assign(n, vector<int>(n, 0));
    string path = "";
    if (m[0][0])
    {
        vis[0][0] = 1;
        move(0, 0, m, n, ans, path);
    }
    return ans;
}