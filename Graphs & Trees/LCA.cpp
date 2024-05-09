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
const ll MOD = 1e9 + 7;

class LCA
{
    int N, J, timer;
    vector<vector<int> > adj, up;
    vector<int> tin, tout;

    void dfs(int src, int par)
    {
        tin[src] = ++timer;
        up[src][0] = par;

        for (int j = 1; j <= J; j++)
            up[src][j] = up[up[src][j - 1]][j - 1];

        for (int nbr : adj[src])
        {
            if (nbr != par)
                dfs(nbr, src);
        }

        tout[src] = ++timer;
    }

    bool isAncestor(int ancestor_node, int node)
    {
        return tin[ancestor_node] <= tin[node] && tout[node] <= tout[ancestor_node];
    }

public:
    LCA(int n, vector<vector<int> > &edges, int root = 0)
    {
        N = n, J = ceil(log2(N));
        timer = 0;

        tin.resize(N);
        tout.resize(N);
        up.assign(N, vector<int>(J + 1));
        adj.assign(N, vector<int>());

        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(root, root);
    }

    int getLCA(int u, int v)
    {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;

        for (int j = J; j >= 0; j--)
        {
            int ancestor_u = up[u][j];

            if (!isAncestor(ancestor_u, v))
                u = ancestor_u;
        }

        return up[u][0]; // u's parent
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > edges;
    FOR(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    LCA tree(n, edges, 0);
    cout << tree.getLCA(8, 7);
}

signed main()
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