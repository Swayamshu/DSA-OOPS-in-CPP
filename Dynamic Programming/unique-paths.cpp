// DP solution

int uniquePaths(int m, int n) // Time: O(m*n), Space: O(m*n)
{
    vector<vector<int> > paths(m, vector<int>(n, 1));

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];

    return paths[m - 1][n - 1];
}

// Math Solution

int nCr(int n, int r)
{
    if (n < r)
        return 0;

    ll num = 1, den = 1;

    if (r == 0)
        return 1;

    while (r)
    {
        num *= n--;
        den *= r--;

        ll temp = gcd(num, den);

        num /= temp;
        den /= temp;
    }
    return num;
}

int uniquePaths(int m, int n) // Time: O(m+n), Space: O(1);
{
    return nCr(m + n - 2, m - 1);
}