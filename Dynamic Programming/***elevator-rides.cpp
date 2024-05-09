// https://cses.fi/problemset/task/1653/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>

using namespace std;

#define int long long
typedef long long ll;
#define FOR(a, b, c) for (int a = b; a < (int)c; ++a)
#define FORN(a, b, c) for (int a = b; a >= (int)c; --a)
#define MAX INT_MAX
#define MIN INT_MIN
#define MAXll LLONG_MAX
#define ii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define print(arr)     \
    for (auto i : arr) \
        cout << i << " ";
#define all(a) a.begin(), a.end()
#define rev(a) a.rbegin(), a.rend()
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

void solve()
{
    int n, x, max_weight;
    cin >> n >> x;
    vector<int> weight(n);
    for (int &i : weight)
        cin >> i;

    max_weight = x;
    vector<ii> dp(1 << n, mp(n + 1, x + 1));
    dp[0] = mp(1, 0);

    FOR(mask, 1, 1 << n)
    {
        FOR(i, 0, n)
        {
            if ((mask >> i) & 1)
            {
                auto [num_rides, total_weight] = dp[mask ^ (1 << i)];

                if (total_weight + weight[i] <= max_weight)
                    total_weight += weight[i];
                else
                {
                    num_rides++;
                    total_weight = weight[i];
                }

                dp[mask] = min(dp[mask], mp(num_rides, total_weight));
            }
        }
    }

    cout << dp[(1 << n) - 1].f;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }
}