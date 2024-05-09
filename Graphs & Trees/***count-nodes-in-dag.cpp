// https://leetcode.com/problems/count-visited-nodes-in-a-directed-graph/

/*
Input: edges = [1,2,0,0]
Output: [3,3,3,4]
Explanation: We perform the process starting from each node in the following way:
- Starting from node 0, we visit the nodes 0 -> 1 -> 2 -> 0. The number of different nodes we visit is 3.
- Starting from node 1, we visit the nodes 1 -> 2 -> 0 -> 1. The number of different nodes we visit is 3.
- Starting from node 2, we visit the nodes 2 -> 0 -> 1 -> 2. The number of different nodes we visit is 3.
- Starting from node 3, we visit the nodes 3 -> 0 -> 1 -> 2 -> 0. The number of different nodes we visit is 4.

Input: edges = [1,2,3,4,0]
Output: [5,5,5,5,5]
Explanation: Starting from any node we can visit every node in the graph in the process.
*/

void fillCycle(int src, vector<int> &edges, vector<bool> &visited, vector<int> &ans)
{
    int len = 0;
    for (int n = src; !visited[n]; n = edges[n])
        visited[n] = true, len++;

    ans[src] = len;
    for (int n = edges[src]; n != src; n = edges[n])
        ans[n] = len;
}

vector<int> countVisitedNodes(vector<int> &edges)
{
    int n = edges.size();
    vector<int> indeg(n, 0), ans(n);
    vector<bool> visited(n, false);
    queue<int> q;
    stack<int> s;
    for (int i = 0; i < n; i++)
        indeg[edges[i]]++;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        s.push(node);
        visited[node] = true;

        if (--indeg[edges[node]] == 0)
            q.push(edges[node]);
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            fillCycle(i, edges, visited, ans);

    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        ans[node] = ans[edges[node]] + 1;
    }

    return ans;
}