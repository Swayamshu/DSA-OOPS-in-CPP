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

using namespace std;

typedef long long ll;
#define FOR(a, b, c) for (int a = b; a < (int)c; ++a)
#define FORN(a, b, c) for (int a = b; a >= (int)c; --a)
#define MAX INT_MAX
#define MIN INT_MIN
#define MAXll LLONG_MAX
#define ii pair<int, int>
#define f first
#define s second
#define print(arr)     \
    for (auto i : arr) \
        cout << i << " ";
#define all(a) a.begin(), a.end()
const ll MOD = 1e9 + 7;

ll nCr(int n, int r)
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

void solve()
{
}

int main()
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
    }
}