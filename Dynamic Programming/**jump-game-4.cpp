// https://leetcode.com/problems/jump-game-vii/

// DP + Sliding Window

bool dp[100005];

bool canReach(string s, int mini, int maxi)
{
    // prev maintains a sliding window for [dp[i - maxi], dp[i - mini]]
    int prev = 0;
    memset(dp, 0, sizeof dp);
    dp[0] = true;

    for (int i = 1; i < s.size(); i++)
    {
        if (i >= mini)
            prev += dp[i - mini];
        if (i > maxi)
            prev -= dp[i - maxi - 1];
        dp[i] = prev > 0 && s[i] == '0';
    }

    return dp[s.size() - 1];
}
