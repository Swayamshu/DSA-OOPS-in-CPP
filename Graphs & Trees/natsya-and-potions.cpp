// https://codeforces.com/problemset/problem/1851/E

/*
Input:
4
5 1
30 8 3 5 10
3
3 2 4 5
0 
0 
2 3 5
0 
3 2
5 143 3
1 3
1 2
0 
2 1 2
5 1
5 4 1 3 4
2
2 4 5
3 3 5 4
2 1 4
1 5
0 
4 2
1 1 5 4
2 4
3 2 4 3
0 
2 2 4
1 2


Output:
23 8 0 5 10 
0 143 0 
5 0 1 3 4 
0 0 0 0 

*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>

typedef long long ll;

#define FOR(a, b, c) for (int a = b; a < c; ++a)
#define FORN(a, b, c) for (int a = b; a >= c; --a)
#define FORll(a, b, c) for (long long a = b; a < c; ++a)
#define FORNll(a, b, c) for (long long a = b; a >= c; --a)
#define INF INT_MAX
#define INFll LLONG_MAX
#define ii pair<int, int>
#define f first
#define s second
#define print(arr)     \
    for (auto i : arr) \
        cout << i << " ";
#define println(arr)   \
    for (auto i : arr) \
        cout << i << "\n";
#define all(a) a.begin(), a.end()
#define MAX_SIZE 100

const ll MOD = 1e9 + 7;

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> cost(n);
    for (ll &i : cost)
        cin >> i;

    FOR(x, 0, k)
    {
        int i;
        cin >> i;
        cost[i - 1] = 0;
    }

    vector<vector<int> > dag(n), adj(n);
    vector<int> indeg(n);
    FOR(i, 0, n)
    {
        int m;
        cin >> m;
        indeg[i] = m;

        FOR(j, 0, m)
        {
            int v;
            cin >> v;
            adj[i].push_back(v - 1);
            dag[v - 1].push_back(i);
        }
    }

    queue<int> q;
    FOR(i, 0, n)
    if (indeg[i] == 0)
        q.push(i);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        ll c1 = cost[curr],
           c2 = adj[curr].size() == 0 ? cost[curr] : 0;

        for (int x : adj[curr])
            c2 += 1LL * cost[x];

        for (int i : dag[curr])
        {
            if (--indeg[i] == 0)
                q.push(i);
        }

        cost[curr] = min(c1, c2);
    }
    print(cost);
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
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}
