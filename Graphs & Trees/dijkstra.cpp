#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <queue>

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

const ll MOD = 1e9 + 7;

using namespace std;

void dijkstra(vector<vector<int> > &graph, int start)
{
    int n = graph.size();
    vector<int> distance(n, INF);
    distance[start] = 0;

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, start}); // !!! IMPORTANT ORDER: {dist, node} !!!

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > distance[u])
            continue;

        for (int v : graph[u])
        {
            if (distance[u] + 1 < distance[v])
            {
                distance[v] = distance[u] + 1;
                pq.push({distance[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Distance from " << start << " to " << i << ": " << distance[i] << "\n";
}

void solve()
{
    int n, m;
    cin >> n >>

        vector<vector<int> > graph(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    int start_node;
    cin >> start_node;

    dijkstra(graph, start_node);
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
    }
}