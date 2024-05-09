// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

class TreeAncestor
{
    vector<vector<int> > up;
    int N, J;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        N = n, J = log2(n) + 1;
        up = vector<vector<int> >(N, vector<int>(J, -1));

        for (int v = 0; v < n; v++)
            up[v][0] = parent[v];

        for (int j = 1; j < J; j++)
            for (int v = 0; v < n; v++)
                if (up[v][j - 1] != -1)
                    up[v][j] = up[up[v][j - 1]][j - 1]; // double jump
    }

    int getKthAncestor(int node, int k)
    {
        for (int j = 0; j < J; j++)
            if (k & (1 << j))
            {
                node = up[node][j];
                if (node == -1)
                    return -1;
            }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */