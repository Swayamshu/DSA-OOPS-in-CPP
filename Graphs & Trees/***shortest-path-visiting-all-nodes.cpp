// https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

/*
for shortest path -> bfs
but bfs doesn't visit all nodes due to visited array
so we need to make smart bfs traversal where 'mask' can be
used to keep track of all visited nodes. ans we make repeated 
bfs traversals for all nodes so that all nodes are visited.
*/

int setbit(int mask, int i)
{
    return mask | (1 << i);
}

int shortestPathLength(vector<vector<int> > &graph)
{
    int n = graph.size(),
        row = (int)pow(2, n),
        col = n;

    // dist[mask][lead] keeps track of min dist till node = lead
    // and visited nodes uptill then is given by mask.
    vector<vector<int> > dist(row, vector<int>(col, -1));
    queue<pair<int, int> > q;

    // pushing all nodes in queue for faster bfs
    // instead of using bfs on every node individually
    for (int i = 0; i < n; i++)
    {
        int lead = i,            // node
            mask = setbit(0, i); // visited nodes

        q.push({lead, mask});
        dist[mask][lead] = 0;
    }

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            auto [lead, mask] = q.front();
            q.pop();

            if (mask == row - 1) // all nodes are visited
                return dist[mask][lead];

            for (auto child : graph[lead])
            {
                int newMask = setbit(mask, child);
                if (dist[newMask][child] != -1)
                    continue;

                dist[newMask][child] = dist[mask][lead] + 1;
                q.push({child, newMask});
            }
        }
    }
    return 1221;
}