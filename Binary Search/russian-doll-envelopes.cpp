// https://leetcode.com/problems/russian-doll-envelopes/description/

/*
Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/

// Binary Search Approach -> all test cases passed
// Time: O(N * log N), Space: O(N)

static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1]; // reverse sorting of height removes duplicacy in LIS
    return a[0] < b[0];     // width increasing, height decreasing
}

int maxEnvelopes(vector<vector<int> > &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), comp);
    print(envelopes);
    vector<int> env;
    env.push_back(envelopes[0][1]);

    for (int i = 1; i < envelopes.size(); i++)
    { // LIS algorithm
        if (env.back() < envelopes[i][1])
            env.push_back(envelopes[i][1]);
        else
        {
            auto idx = lower_bound(env.begin(), env.end(), envelopes[i][1]) - env.begin();
            env[idx] = envelopes[i][1];
        }
    }

    return env.size();
}

// DP Approach -> TLE on 85th case
// Time: O(N ^ 2), Space: O(N ^ 2)

vector<vector<int> > dp;

int solve(int pos, int prv, vector<vector<int> > &env)
{
    if (pos == env.size())
        return 0;
    if (dp[pos][prv + 1] != -1)
        return dp[pos][prv + 1];

    int skip = solve(pos + 1, prv, env);

    int take = 0;
    if (prv == -1)
        take = 1 + solve(pos + 1, pos, env);
    else if (env[prv][0] < env[pos][0] && env[prv][1] < env[pos][1])
        take = 1 + solve(pos + 1, pos, env);

    return dp[pos][prv + 1] = max(take, skip);
}

int maxEnvelopes(vector<vector<int> > &envelopes)
{
    dp.assign(envelopes.size(), vector<int>(envelopes.size() + 1, -1));
    sort(envelopes.begin(), envelopes.end());
    return solve(0, -1, envelopes);
}