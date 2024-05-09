#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <set>

typedef long long ll;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORll(a, b, c) for (long long(a) = (b); (a) < (c); ++(a))
#define FORNll(a, b, c) for (long long(a) = (b); (a) >= (c); --(a))
#define INF INT_MAX
#define INFll LLONG_MAX
#define ii pair<int, int>
#define f first
#define s second
#define print(arr)     \
    for (auto i : arr) \
        cout << i << " ";

const ll MOD = 1e9 + 7;

using namespace std;

vector<vector<int> > tree;
vector<int> depth;
vector<int> ans;

void eval_depth(int src, int prev)
{
    int src_depth = 0;
    for (int child : tree[src])
        if (child != prev)
        {
            eval_depth(child, src);
            src_depth = max(src_depth, 1 + depth[child]);
        }

    depth[src] = src_depth;
}

void tree_dist(int src, int prev, int prev_ans)
{
    vector<int> prefixMax, suffixMax;

    for (int child : tree[src])
    {
        if (child != prev)
        {
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }

    FOR(i, 1, prefixMax.size())
    prefixMax[i] = max(prefixMax[i], prefixMax[i - 1]);
    FORN(i, suffixMax.size() - 2, 0)
    suffixMax[i] = max(suffixMax[i], suffixMax[i + 1]);

    int c_no = 0;
    for (int child : tree[src])
    {
        if (child != prev)
        {
            int op1 = (c_no == 0) ? INT_MIN : prefixMax[c_no - 1];
            int op2 = (c_no == suffixMax.size() - 1) ? INT_MIN : suffixMax[c_no + 1];
            int partial_ans = 1 + max(prev_ans, max(op1, op2));

            tree_dist(child, src, partial_ans);
            c_no++;
        }
    }

    ans[src] = 1 + max(prev_ans, (prefixMax.empty() ? -1 : prefixMax.back()));
}

void solve()
{
    int n;
    cin >> n;
    tree.assign(n + 1, vector<int>());
    FOR(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }

    depth.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    eval_depth(1, 0);
    tree_dist(1, 0, -1);
    FOR(i, 1, n + 1)
    cout << ans[i] << " ";
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