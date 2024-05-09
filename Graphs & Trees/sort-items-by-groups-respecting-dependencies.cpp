// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/

/*
Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
Output: [6,3,4,1,5,2,0,7]

Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
Output: []
Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
*/

vector<int> topoSort(vector<unordered_set<int> > &adj, vector<int> &indeg)
{
    vector<int> order;
    int processed = 0, n = adj.size();

    queue<int> q;
    for (int u = 0; u < n; u++)
        if (indeg[u] == 0)
            q.push(u);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        ++processed;
        order.push_back(u);

        for (int v : adj[u])
        {
            --indeg[v];
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    return processed < n ? vector<int>{} : order;
}

vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int> > &beforeItems)
{
    for (int u = 0; u < n; u++)
        if (group[u] == -1)
            group[u] = m++;

    vector<unordered_set<int> > groupAdj(m), nodeAdj(n);
    vector<int> groupIndeg(m, 0), nodeIndeg(n, 0);

    for (int u = 0; u < n; u++)
    {
        int g = group[u];

        for (int v : beforeItems[u])
        {
            int src_g = group[v];

            if (g != src_g && !groupAdj[src_g].count(g))
            {
                groupAdj[src_g].emplace(g);
                ++groupIndeg[g];
            }

            if (!nodeAdj[v].count(u))
            {
                nodeAdj[v].emplace(u);
                ++nodeIndeg[u];
            }
        }
    }

    vector<int> sortedNodes = topoSort(nodeAdj, nodeIndeg);
    vector<int> sortedGroups = topoSort(groupAdj, groupIndeg);
    vector<int> sorted;

    vector<vector<int> > groupSortedNodes(m);
    for (int u : sortedNodes)
        groupSortedNodes[group[u]].emplace_back(u);

    for (int g : sortedGroups)
        for (int u : groupSortedNodes[g])
            sorted.emplace_back(u);

    return sorted;
}