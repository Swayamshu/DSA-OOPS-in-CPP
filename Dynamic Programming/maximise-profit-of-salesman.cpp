// https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/

/*
Example 1:
Input: n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
Output: 3
Explanation: There are 5 houses numbered from 0 to 4 and there are 3 purchase offers.
We sell houses in the range [0,0] to 1st buyer for 1 gold and houses in the range [1,3] to 3rd buyer for 2 golds.
It can be proven that 3 is the maximum amount of gold we can achieve.

Example 2:
Input: n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
Output: 10
Explanation: There are 5 houses numbered from 0 to 4 and there are 3 purchase offers.
We sell houses in the range [0,2] to 2nd buyer for 10 golds.
It can be proven that 10 is the maximum amount of gold we can achieve.
*/

// Knapsack DP || Binary Search

vector<int> dp;

int nextValidOffer(int pos, vector<vector<int> > &offers)
{
    int left = pos + 1,
        right = offers.size() - 1,
        mid, idx = offers.size(),
        lastHouse = offers[pos][1], nextHouse;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        nextHouse = offers[mid][0];

        if (lastHouse < nextHouse)
            idx = mid,
            right = mid - 1;
        else
            left = mid + 1;
    }
    return idx;
}

int solve(int pos, vector<vector<int> > &offers)
{
    if (pos == offers.size())
        return 0;
    if (dp[pos] != -1)
        return dp[pos];

    int skip = solve(pos + 1, offers);

    int idx = nextValidOffer(pos, offers);
    int take = offers[pos][2] + solve(idx, offers);

    return dp[pos] = max(take, skip);
}

int maximizeTheProfit(int n, vector<vector<int> > &offers)
{
    sort(offers.begin(), offers.end());
    dp.assign(offers.size(), -1);
    return solve(0, offers);
}