// https://leetcode.com/problems/network-delay-time/description/

/*
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

vector<bool> visited;
vector<int> time;

void dfs_helper(int src, vector<vector<vector<int> > > &graph, int t = 0)
{
    visited[src] = true;
    time[src] = t;

    for (auto it : graph[src])
    {
        int node = it[0];
        if (!visited[node] || (visited[node] && t + it[1] < time[node]))
            dfs_helper(node, graph, t + it[1]);
    }
}

int networkDelayTime(vector<vector<int> > &times, int n, int k)
{
    vector<vector<vector<int> > > graph(n + 1);
    for (auto v : times)
        graph[v[0]].push_back({v[1], v[2]});

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end(),
             [](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });
    }

    visited.assign(n + 1, false);
    time.assign(n + 1, INT_MAX);
    time[0] = 0;
    dfs_helper(k, graph);

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            return -1;

    return *max_element(time.begin(), time.end());
}