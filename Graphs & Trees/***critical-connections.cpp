// https://leetcode.com/problems/critical-connections-in-a-network/description/

/*
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
*/

// find bridge in the graph -> TARJAN'S Algorithm

class Solution
{
    vector<vector<int> > network;
    vector<bool> visited;
    vector<int> lowest_time, discovery_time;
    int time = 0;

    void findCriticalConnections(int source_node, int parent_node, vector<vector<int> > &critical_connections)
    {
        visited[source_node] = true;
        lowest_time[source_node] = discovery_time[source_node] = ++time;

        for (int child_node : network[source_node])
        {
            if (!visited[child_node])
            {
                findCriticalConnections(child_node, source_node, critical_connections);

                lowest_time[source_node] = min(lowest_time[child_node], lowest_time[source_node]);
                if (discovery_time[source_node] < lowest_time[child_node])
                {
                    critical_connections.push_back({source_node, child_node});
                }
            }
            else if (child_node != parent_node)
            {
                lowest_time[source_node] = min(discovery_time[child_node], lowest_time[source_node]);
                // lowest_time[source_node] = min(lowest_time[child_node], lowest_time[source_node]);
                // both works -> 2nd should be more intuitive;
            }
        }
    }

public:
    vector<vector<int> > criticalConnections(int n, vector<vector<int> > &connections)
    {
        network.assign(n, vector<int>());
        for (auto connection : connections)
        {
            int start_node = connection[0],
                end_node = connection[1];

            network[start_node].push_back(end_node);
            network[end_node].push_back(start_node);
        }

        vector<vector<int> > critical_connections;
        visited.assign(n, false);
        lowest_time.assign(n, 0);
        discovery_time.assign(n, 0);

        for (int node = 0; node < n; node++)
        {
            if (!visited[node])
                findCriticalConnections(node, -1, critical_connections);
        }

        return critical_connections;
    }
};