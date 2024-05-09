// https://leetcode.com/problems/trapping-rain-water-ii/

/*
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
*/

typedef vector<int> vi;

int di[4] = {-1, 0, 1, 0},
    dj[4] = {0, -1, 0, 1};

int trapRainWater(vector<vector<int> > &heightMap)
{
    int n = heightMap.size(), m = heightMap[0].size();
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    priority_queue<vi, vector<vi>, greater<vi> > boundary;

    for (int j = 0; j < m; j++)
    {
        boundary.push({heightMap[0][j], 0, j});
        boundary.push({heightMap[n - 1][j], n - 1, j});
        vis[0][j] = true, vis[n - 1][j] = true;
    }

    for (int i = 0; i < n; i++)
    {
        boundary.push({heightMap[i][0], i, 0});
        boundary.push({heightMap[i][m - 1], i, m - 1});
        vis[i][0] = true, vis[i][m - 1] = true;
    }

    int water = 0;
    while (!boundary.empty())
    {
        auto curr = boundary.top();
        boundary.pop();
        int waterLevel = curr[0], i = curr[1], j = curr[2];

        for (int k = 0; k < 4; k++)
        {
            int x = i + di[k],
                y = j + dj[k];

            if (0 <= x && x < n && 0 <= y && y < m && !vis[x][y])
            {
                water += max(waterLevel - heightMap[x][y], 0);
                boundary.push({max(waterLevel, heightMap[x][y]), x, y});
                vis[x][y] = true;
            }
        }
    }

    return water;
}