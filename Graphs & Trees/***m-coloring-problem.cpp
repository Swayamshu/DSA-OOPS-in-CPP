// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

/*
Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
*/

bool isSafe(int v, int c, bool graph[101][101], vector<int> &color, int n)
{
    for (int i = 0; i < n; i++)
        if (graph[v][i] && color[i] == c)
            return false;
    return true;
}

bool graph_helper(int v, bool graph[101][101], int m, int n, vector<int> &color)
{
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, c, graph, color, n))
        {
            color[v] = c;
            if (graph_helper(v + 1, graph, m, n, color))
                return true;
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, 0);
    if (graph_helper(0, graph, m, n, color))
        return true;
    return false;
}