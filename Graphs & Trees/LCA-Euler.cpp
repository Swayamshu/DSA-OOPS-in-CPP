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

class LCA_Euler
{
    vector<int> height, euler, first, segTree;
    vector<bool> visited;
    int n;

public:
    LCA_Euler(vector<vector<int> > &adj, int root = 0)
    {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(2 * n);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segTree.resize(4 * m);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int> > &adj, int node, int h = 0)
    {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                dfs(adj, nbr, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int root, int left, int right)
    {
        if (left == right)
            segTree[root] = euler[left];
        else
        {
            int mid = (right + left) / 2;

            build(root << 1, left, mid);
            build(root << 1 | 1, mid + 1, right);

            int l = segTree[root << 1], r = segTree[root << 1 | 1];
            segTree[root] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int root, int left, int right, int qLeft, int qRight)
    {
        if (qRight < left || right < qLeft)
            return -1;
        if (qLeft <= left && right <= qRight)
            return segTree[root];

        int mid = (right + left) >> 1;

        int l = query(root << 1, left, mid, qLeft, qRight);
        int r = query(root << 1 | 1, mid + 1, right, qLeft, qRight);

        if (l == -1)
            return r;
        if (r == -1)
            return l;

        return height[l] < height[r] ? l : r;
    }

    int lca(int u, int v)
    {
        int l = first[u], r = first[v];
        if (l > r)
            swap(l, r);
        return query(1, 0, euler.size() - 1, l, r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LCA_Euler tree(adj);

    int m;
    cin >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c, --a, --b, --c;

        int lca_ab = tree.lca(c, b);
        cout << tree.lca(b, c) << " " << tree.lca(a, c) << " " << tree.lca(a, b) << '\n';
        // if (tree.lca(lca_ab, c) == lca_ab)
        //     cout << "YES\n";
        // else
        //     cout << "NO\n";
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
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}