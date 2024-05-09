class DSU
{
    vector<int> parent, rank, size;
    int N;

public:
    DSU(int n)
    {
        N = n;
        parent.resize(N);
        rank.resize(N);
        size.resize(N);
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    int getParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = getParent(parent[node]);
    }

    void unionSet(int u, int v)
    {
        int parent_u = getParent(u);
        int parent_v = getParent(v);

        if (rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        }
        else if (rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
        else
        {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
            size[parent_v] += size[parent_u];
        }
    }

    int getSize(int node)
    {
        int parent = getParent(node);
        return size[parent];
    }
};