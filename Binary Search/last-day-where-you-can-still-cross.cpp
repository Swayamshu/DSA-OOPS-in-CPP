// https://leetcode.com/problems/last-day-where-you-can-still-cross/description/

typedef pair<int, int> ii;

class Solution
{
public:
    vector<vector<int> > grid;
    int n, m;
    int di[4] = {-1, 0, 1, 0},
        dj[4] = {0, -1, 0, 1};

    bool canWalk(int day, vector<vector<int> > &cells)
    {
        grid.assign(n, vector<int>(m, 0));
        for (int i = 0; i < day; i++)
        {
            int x = cells[i][0] - 1,
                y = cells[i][1] - 1;
            grid[x][y] = 1;
        }

        queue<ii> q;
        for (int i = 0; i < m; i++)
            if (grid[0][i] == 0)
            {
                q.push({0, i});
                grid[0][i] = 1;
            }

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1)
                return true;

            for (int k = 0; k < 4; k++)
            {
                int x = i + di[k],
                    y = j + dj[k];

                if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 0)
                {
                    q.push({x, y});
                    grid[x][y] = 1;
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int> > &cells)
    {
        n = row, m = col;
        int left = 0, right = cells.size() - 1, mid, ans;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (canWalk(mid, cells))
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        return ans;
    }
};