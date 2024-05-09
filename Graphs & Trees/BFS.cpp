#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;


template<typename T>

class Graph{

	map<T, list<T>> M;

public:
	void makeEdge(T x, T y){
		M[x].push_back(y);
		M[y].push_back(x);
	}

	void bfs(T source){
		map<T, bool> visited;  // map for visited corners
		queue<T> Q;		   // queue for level 

		Q.push(source);
		visited[source] = true;

		while(!Q.empty()){
			T node = Q.front();
            Q.pop();
			cout<<node<<endl;

			for(auto neighbour : M[node]){
				if(!visited[neighbour]){
					Q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	Graph<int> g1;
	g1.makeEdge(0, 1);
	g1.makeEdge(0, 3);
	g1.makeEdge(1, 2);
	g1.makeEdge(3, 2);
	g1.makeEdge(3, 4);
	g1.makeEdge(4, 5);
	g1.bfs(0);

	return 0;
}







