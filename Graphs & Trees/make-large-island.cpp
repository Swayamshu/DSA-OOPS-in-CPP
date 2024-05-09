// https://leetcode.com/problems/making-a-large-island/description/

/*
Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
*/

int n, color, area, ans = 0;
unordered_map<int, int> mp;
int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, 1, 0, -1};

void paint(int i, int j, vector<vector<int> > &grid)
{
    grid[i][j] = color;
    area++;

    for (int k = 0; k < 4; k++)
    {
        int x = i + di[k],
            y = j + dj[k];
        if (0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 1)
            paint(x, y, grid);
    }
}

int largestIsland(vector<vector<int> > &grid)
{
    mp.clear();
    n = grid.size(), color = 2;

    mp[0] = 0;
    mp[1] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
            {
                area = 0;
                paint(i, j, grid);
                mp[color++] = area;
                ans = max(area, ans);
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 0)
            {
                int a = 0;
                set<int> vis;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + di[k],
                        y = j + dj[k];
                    if (0 <= x && x < n && 0 <= y && y < n && vis.find(grid[x][y]) == vis.end())
                    {
                        a += mp[grid[x][y]];
                        vis.insert(grid[x][y]);
                    }
                }
                ans = max(a + 1, ans);
            }

    return ans;
}