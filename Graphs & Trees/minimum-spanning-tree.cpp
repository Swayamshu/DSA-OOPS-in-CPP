// https://www.codingninjas.com/studio/problems/minimum-spanning-tree_631769?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

// prim's algorithm

bool compareEdges(vector<int> &edge1, vector<int> &edge2)
{
    return edge1[2] < edge2[2];
}

int getParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = getParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent)
{
    int parent1 = getParent(u, parent);
    int parent2 = getParent(v, parent);
    parent[parent1] = parent2;
}

int minimumSpanningTree(vector<vector<int> > &edges, int n)
{
    vector<vector<int> > mst;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), compareEdges);

    int minWeight = 0;
    for (auto edge : edges)
    {
        int u = edge[0],
            v = edge[1],
            w = edge[2];

        if (getParent(u, parent) != getParent(v, parent))
        {
            mst.push_back({u, v, w});
            minWeight += w;
            unionSet(u, v, parent);
        }
    }

    return minWeight;
}

class DisjointIntervals
{
public:
    set<int> s;
    DisjointIntervals() {}
    void addInteger(int val) { s.insert(val); }
    vector<vector<int> > getDisjointIntervals()
    {
        vector<vector<int> > v;
        set<int>::iterator it;
        int start, prev, end;
        for (it = s.begin(); it != s.end(); it++)
        {
            if (it == s.begin())
            {
                start = *it;
                prev = *it;
            }
            else
            {
                if (*it != prev + 1)
                {
                    end = prev;
                    v.push_back({start, end});
                    start = *it;
                }
                prev = *it;
            }
        }
        v.push_back({start, prev});
        return v;
    }
};