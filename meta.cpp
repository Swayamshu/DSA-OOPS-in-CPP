#include <bits/stdc++.h>
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
#define fast                              \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(nullptr);                 \
        cout.tie(nullptr);                \
    }
#define int long long
#define ld long double
#define f(n) for (auto i = 0; i < n; i++)
const int M = 1000000007;
const int N = 100005;

void IO();

vector<int> ans;
void solve(int sum, int n, vector<int> &temp)
{
    if (ans.size() && (ans.size() <= temp.size()))
        return;

    if (sum < 0 || n < 1)
        return;

    if (n == 1)
    {
        if (ans.size() && (ans.size() <= temp.size() + sum))
            return;

        vector<int> x = temp;

        for (int i = 0; i < sum; i++)
            x.push_back(1);

        ans = x;

        if (ans.size() || (ans.size() < x.size()))
            return;
    }

    for (int i = 41; i >= 2; i--)
    {
        if (n % i || sum < i)
            continue;

        temp.push_back(i);
        solve(sum - i, n / i, temp);
        temp.pop_back();
    }
}

int32_t main()
{
    fast
    IO();

    int t;
    cin >> t;
    int cnt = 1;
    while (t--)
    {
        cout << "Case #" << cnt++ << ": ";
        int n;
        cin >> n;
        vector<int> temp;
        ans.clear();
        solve(41, n, temp);
        if (ans.empty())
        {
            cout << -1 << endl;
            continue;
        }

        cout << ans.size() << " ";
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}

void IO()
{
#ifndef ONLINE_JUDGE
    freopen("abcd.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}