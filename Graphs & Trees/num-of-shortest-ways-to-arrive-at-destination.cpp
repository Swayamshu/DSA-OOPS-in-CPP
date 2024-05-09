// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

/*
Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
*/

// dijkstra's algorithm approach and storing num of paths along the way.

typedef pair<long long, long long> ll;
const long long mod = 1e9 + 7;
const long long INF = LLONG_MAX;

int countPaths(int n, vector<vector<int> > &roads)
{
    vector<vector<ll> > adj(n, vector<ll>());
    for (auto v : roads)
    {
        adj[v[0]].push_back({v[1], v[2]});
        adj[v[1]].push_back({v[0], v[2]});
    }

    vector<long long> times(n, INF), path(n, 0);
    times[0] = 0;
    path[0] = 1;

    priority_queue<ll, vector<ll>, greater<ll> > pq;
    pq.push({0, 0}); // !!! IMPORTANT PQ ORDER: {dist/time, node} !!!

    while (!pq.empty())
    {
        auto [time, node] = pq.top();
        pq.pop();

        for (auto [nbr, t] : adj[node])
        {
            if (time + t < times[nbr])
            {
                times[nbr] = time + t;
                path[nbr] = path[node];
                pq.push({time + t, nbr});
            }
            else if (time + t == times[nbr])
            {
                path[nbr] += path[node] % mod;
            }
        }
    }
    return path[n - 1] % mod;
}