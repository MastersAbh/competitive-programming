#include <iostream>
using namespace std;
#define inf 1e9

/*
5 8
0 1 -1
0 2 4
1 2 3
3 2 5
4 3 -3
1 4 2
1 3 2
3 1 1
*/

class Edge {
public:
	int src, dest, weight;
};

class Graph {
public:
	int v, e;
	Edge *edge;
	
	Graph(int v, int e) {
		this->v = v;
		this->e = e;
		edge = new Edge[e];
	}
	
	void addEdge(int u, int v, int w, int count) {
		edge[count].src = u;
		edge[count].dest = v;
		edge[count].weight = w;
	}
	
	void bellmanFord(int src) {
		int distance[v];
		for(int i=0; i<v; i++) {
			distance[i] = inf;
		}
		distance[src] = 0;
		
		// Relaxation code
		for(int i=1; i<=v-1; i++) {
			for(int j=0; j<e; j++) {
				int src= edge[j].src;
				int dest = edge[j].dest;
				int weight = edge[j].weight;
				
				// Relaxation check
				if (distance[src] != inf and distance[src] + weight < distance[dest]) {
					distance[dest] = distance[src] + weight;
				}
			}
		}
		
		// Check for -ve weight cycles
		for(int j=0; j<e; j++) {
			int src= edge[j].src;
			int dest = edge[j].dest;
			int weight = edge[j].weight;
			
			// Relaxation check
			if (distance[src] != inf and distance[src] + weight < distance[dest]) {
				cout<<"Graph has negative weight cycle";
				return;
			}
		}
		
		// Print the distance array
		for(int i=0; i<v; i++) {
			cout<<i<<" -> "<<distance[i]<<endl;
		}
		return;
	}
};

int main() {
	
	int v, e;
	cin>>v>>e;
	
	Graph g(v, e);
	
	for(int i=0; i<e; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		g.addEdge(u, v, w, i);
	}
	
	int src= 0;
	g.bellmanFord(src);

	return 0;
}

