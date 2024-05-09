// https://leetcode.com/problems/regular-expression-matching/description/

/*
Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'.
Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/

int n, m;
vector<vector<int> > dp;

bool solve(int i, string &s, int j, string &p)
{
    if (j == m)
        return dp[i][j] = i == n;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (p[j + 1] == '*')
    {
        if (solve(i, s, j + 2, p))
            return dp[i][j] = 1;

        if (i < n && (p[j] == s[i] || p[j] == '.'))
            if (solve(i + 1, s, j, p))
                return dp[i][j] = 1;
    }
    else if (i < n && (p[j] == s[i] || p[j] == '.'))
        if (solve(i + 1, s, j + 1, p))
            return dp[i][j] = 1;

    return dp[i][j] = 0;
}

bool isMatch(string s, string p)
{
    n = s.size(), m = p.size();
    dp.assign(n + 1, vector<int>(m + 1, -1));
    return solve(0, s, 0, p);
}