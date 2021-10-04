#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<pair<int, int> > g[100005];

void addEdge(int u, int v, int wt) {
    g[u].push_back({v, wt});
}

void prims() {
    unordered_map<int, int> weight;
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;

    for(int i=0; i<=8; i++) {
        weight[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    weight[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        int node = p.second;
        pq.pop();
        visited[node] = true;
        for(auto child: g[node]) {
            if (!visited[child.first] && weight[child.first]>child.second) {
                weight[child.first] = child.second;
                pq.push({child.second, child.first});
                parent[child.first] = node;
            }
        }
    }

    ll sum = 0;
    for(int i=0; i<=8; i++) {
        cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        sum += weight[i];
    }
    cout<<"sum: "<<sum<<endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7);

    prims();

	return 0;
}

