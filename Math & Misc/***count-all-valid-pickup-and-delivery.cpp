// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

/*
Example 1:
Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.

Example 2:
Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

Example 3:
Input: n = 3
Output: 90
*/

int dp[501][501];
int mod = 1e9 + 7;

long totalWays(int unpicked, int undelivered)
{
    if (unpicked == 0 && undelivered == 0)
        return 1;
    if (unpicked < 0 || undelivered < 0 || undelivered < unpicked)
        return 0;
    if (dp[unpicked][undelivered] != -1)
        return dp[unpicked][undelivered];

    long ans = 0;
    // ways to pick
    // n * waysFor(n - 1) unpicked orders
    ans += unpicked * totalWays(unpicked - 1, undelivered);
    ans %= mod;

    // ways to deliver
    // orders that are picked but not delivered yet
    long canBeDelivered = undelivered - unpicked;
    ans += canBeDelivered * totalWays(unpicked, undelivered - 1);
    ans %= mod;

    return dp[unpicked][undelivered] = ans;
}

int countOrders(int n)
{
    memset(dp, -1, sizeof(dp));
    return (int)totalWays(n, n);
}