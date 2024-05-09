#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

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

const ll MOD = 1e9 + 7;

using namespace std;

/* Test Cases
Input:
7
1 2 3
1 3 4
2 4 4
2 5 6 
3 6 6 
3 7 8 
5
2 6
7 4
3 5
3 3
4 5

Output:
3
5
3
0
2
*/

bool dfs_helper(int src, int dst, vector<int> &weights, unordered_map<int, vector<ii> > &m, vector<bool> &visited)
{
    if (src == dst)
        return true;

    visited[src] = true;

    for (auto p : m[src])
    {
        if (!visited[p.f])
        {
            weights.push_back(p.s);
            bool path = dfs_helper(p.f, dst, weights, m, visited);
            if (path)
                return true;
            else
                weights.pop_back(); // Only pop if the destination is not found from this neighbor
        }
    }
    return false;
}

int minimize(vector<int> &weights)
{
    if (weights.size() == 0)
        return 0;

    sort(weights.begin(), weights.end());
    int median = weights[weights.size() / 2],
        operations = 0;

    for (int i : weights)
        operations += abs(i - median);

    return operations;
}

void solve()
{
    int n, q;
    cin >> n;
    unordered_map<int, vector<ii> > m;
    vector<bool> visited(n, false);
    FOR(i, 0, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        m[u].push_back({v, w});
        m[v].push_back({u, w});
    }

    cin >> q;
    FOR(i, 0, q)
    {
        int u, v;
        cin >> u >> v;

        vector<int> weights;
        fill(visited.begin(), visited.end(), false);
        dfs_helper(u, v, weights, m, visited);
        cout << minimize(weights) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}