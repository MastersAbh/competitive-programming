#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair

typedef pair<int, int> pii;

struct Graph {
	int V, E;
	vector<pair<int, pii> > edges;
	
	Graph(int V, int E) {
		this->V = V;
		this->E = E;
	}
	
	void addEdge(int u, int v, int w) {
		edges.pb({w, {u, v}});
	}
	
	int kruskalMST();
};

struct DisjointSets {
	int* parent;
	int* rank;
	int n;
	
	DisjointSets(int n) {
		this->n = n;
        this->parent = new int[n];
        this->rank = new int[n];
		for(int i=1; i<=n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	
	int find(int i) {
		while(parent[i] != i) {
			i = parent[i];
		} 
		return i;
	}
	
	void union1(int x, int y) {
		x = find(x);
		y = find(y);
		if (rank[x] < rank[y]) {
			parent[x] = y;
			rank[y] += rank[x];
		} else {
			parent[y] = x;
			rank[x] += rank[y];
		}
	}
};

int Graph::kruskalMST() {
	int minCost = 0;
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	vector<pair<int, pii> >::iterator it;
	for(it = edges.begin(); it != edges.end(); it++) {
		int u = it->second.first;
		int v = it->second.second;
		
		int set_u = ds.find(u);
		int set_v = ds.find(v);
		
		if (set_u != set_v) {
			minCost += it->first;
			ds.union1(set_u, set_v);
		}
	}
	return minCost;
} 

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V = 9, E = 14; 
    Graph g(V, E); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    int mst_wt = g.kruskalMST(); 
  
    cout <<"Weight of MST is " << mst_wt; 

	return 0;
}

