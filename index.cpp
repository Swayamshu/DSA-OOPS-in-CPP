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

int n;

int getMaxIntensity(int src, int dst, vector<vector<int> > &adj, set<int> &loud_speaker)
{
    vector<int> dist(n, INT_MAX), parent(n, -1);
    parent[src] = src;
    dist[src] = 0;

    queue<vector<int> > q;
    q.push({0, src, src});

    while (!q.empty())
    {
        int node = q.front()[1];
        int d = q.front()[0];
        int par = q.front()[2];
        q.pop();

        for (auto nbr : adj[node])
        {
            if (loud_speaker.count(nbr))
            {
                if (d + 1 < dist[nbr] && nbr != parent[par])
                {
                    dist[nbr] = d + 1;
                    parent[nbr] = par;
                    q.push({0, nbr, nbr});
                }
            }
            else if (d + 1 < dist[nbr])
            {
                dist[nbr] = d + 1;
                parent[nbr] = par;
                q.push({d + 1, nbr, par});
            }
        }
    }

    print(dist);
    cout << "\n";
    print(parent);
    cout << "\n";

    int ans = dist[dst];
    // while (dst != src)
    // {
    //     ans = max(ans, dist[dst]);
    //     dst = parent[dst];
    // }

    return ans;
}

vector<bool> visited;
bool possible(int src, int dst, int intensity, int max_intensity, vector<vector<int> > &adj, set<int> &loud_speakers)
{
    if (intensity < 0)
        return false;
    if (src == dst)
        return true;

    if (loud_speakers.count(src))
        intensity = max_intensity;

    visited[src] = true;
    bool ans = false;

    for (int nbr : adj[src])
    {
        if (!visited[nbr])
            ans |= possible(nbr, dst, intensity - 1, max_intensity, adj, loud_speakers);
    }
    return ans;
}

void solve()
{
    int m;
    cin >> n >> m;
    // vector<vector<int> > edges(m);
    vector<vector<int> > adj(n);
    FOR(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // FOR(i, 0, n)
    // {
    //     cout << i << ": ";
    //     for (auto k : adj[i])
    //         cout << k << " ";
    //     cout << "\n";
    // }

    int k;
    cin >> k;
    set<int> loud_speakers;
    FOR(i, 0, k)
    {
        int x;
        cin >> x;
        x--;
        loud_speakers.insert(x);
    }

    int start, end;
    cin >> start >> end;
    start--, end--;

    // cout << getMaxIntensity(start, end, adj, loud_speakers);

    int lo = 1,
        hi = 1e5, mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        visited.assign(n, false);

        if (possible(start, end, mid, mid, adj, loud_speakers))
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    cout << lo;
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