// https://leetcode.com/problems/cherry-pickup/description/

/*
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.


Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0
*/

int dp[51][51][51];
int n;

int pick(int r1, int c1, int r2, vector<vector<int> > &grid)
{
    int c2 = r1 + c1 - r2; // r1 + c1 == r2 + c2

    if (n <= r1 || n <= r2 || n <= c1 || n <= c2 || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        return INT_MIN;

    if (r1 == n - 1 && c1 == n - 1)
        return grid[r1][c1];

    if (dp[r1][c1][r2] != -1)
        return dp[r1][c1][r2];

    int cherries = 0;
    if (r1 == r2 && c1 == c2)
        cherries += grid[r1][c1];
    else
        cherries += grid[r1][c1] + grid[r2][c2];

    int a = pick(r1, c1 + 1, r2 + 1, grid), // h v
        b = pick(r1 + 1, c1, r2, grid),     // v h
        c = pick(r1 + 1, c1, r2 + 1, grid), // v v
        d = pick(r1, c1 + 1, r2, grid);     // h h

    return dp[r1][c1][r2] = cherries + max({a, b, c, d});
}

int cherryPickup(vector<vector<int> > &grid)
{
    n = grid.size();
    memset(dp, -1, sizeof(dp));
    int ans = pick(0, 0, 0, grid);
    return ans < 0 ? 0 : ans;
}