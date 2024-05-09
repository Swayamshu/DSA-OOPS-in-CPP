#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

template <typename T>

class Solution
{
public:
	map<int, list<int> > adj;
	vector<bool> visited;

	void makeEdge(int x, int y)
	{
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int dfsHelper(int source)
	{
		if (visited[source])
			return 0;

		int count = 1;
		visited[source] = true;

		for (auto neighbour : adj[source])
			count += dfsHelper(neighbour);

		return count;
	}

	long long countPairs(int n, vector<vector<int> > &edges)
	{
		vector<int> counts;

		adj.clear();
		for (auto edge : edges)
			makeEdge(edge[0], edge[1]);

		fill(visited.begin(), visited.end(), false);
		for (int i = 0; i < n; i++)
		{
			int count = dfsHelper(0);
			counts.push_back(count);
		}

		ll ans = 0;
		for (int i = 0; i < counts.size(); i++)
			for (int j = i + 1; j < counts.size(); j++)
				ans += (ll)counts[i] * counts[j];

		return ans;
	}
};

class Graph
{

	map<T, list<T> > M;

public:
	void makeEdge(T x, T y)
	{
		M[x].push_back(y);
		M[y].push_back(x);
	}

	void bfs(T source)
	{
		map<T, bool> visited; // map for visited corners
		queue<T> Q;			  // queue for level

		Q.push(source);
		visited[source] = true;

		while (!Q.empty())
		{
			T node = Q.front();
			Q.pop();
			cout << node << endl;

			for (auto neighbour : M[node])
			{
				if (!visited[neighbour])
				{
					Q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void dfsHelper(T source, map<T, bool> &visited)
	{
		// recursive function to traverse the graph

		cout << source << endl;
		visited[source] = true;

		for (auto neighbour : M[source])
		{
			if (!visited[neighbour])
			{
				dfsHelper(neighbour, visited);
			}
		}
	}

	void dfs(T source)
	{
		map<T, bool> visited; // map for visited corners

		for (auto pair : M)
		{ // make all nodes un-visited at first
			T node = pair.first;
			visited[node] = false;
		}

		dfsHelper(source, visited);
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph<int> g1;
	int x, y, t;
	cin >> t;

	while (t--)
	{
		cin >> x >> y;
		g1.makeEdge<int>(x, y);
	}

	// g1.makeEdge(0, 1);
	// g1.makeEdge(0, 3);
	// g1.makeEdge(1, 2);
	// g1.makeEdge(3, 2);
	// g1.makeEdge(3, 4);
	// g1.makeEdge(4, 5);

	g1.bfs(0);
	cout << endl
		 << endl;
	g1.dfs(0);

	return 0;
}
