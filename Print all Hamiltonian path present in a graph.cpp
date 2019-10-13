#include <iostream>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
		// An array of vectors to represent adjacency list
	vector<int> *adjList;

	// Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// allocate memory
		adjList = new vector<int>[N];

		// add edges to the undirected graph
		for (unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

void printAllHamiltonianPaths(Graph const& g, int v, vector<bool>
						visited, vector<int> &path, int N)
{
	// if all the vertices are visited, then
	// Hamiltonian path exists
	if (path.size() == N)
	{
		// print Hamiltonian path
		for (int i : path)
			cout << i << " ";
		cout << endl;

		return;
	}

	// Check if every edge starting from vertex v leads
	// to a solution or not
	for (int w : g.adjList[v])
	{
		// process only unvisited vertices as Hamiltonian
		// path visits each vertex exactly once
		if (!visited[w])
		{
			visited[w] = true;
			path.push_back(w);

			// check if adding vertex w to the path leads
			// to solution or not
			printAllHamiltonianPaths(g, w, visited, path, N);

			// Backtrack
			visited[w] = false;
			path.pop_back();
		}
	}
}

// main function
int main()
{
	// consider complete graph having 4 vertices
	vector<Edge> edges =
	{
		{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
	};

	// starting node
	int start = 0;

	// Number of vertices in the graph
	int N = 4;

	// create a graph from edges
	Graph g(edges, N);

	// add starting node to the path
	vector<int> path;
	path.push_back(start);

	// mark start node as visited
	vector<bool> visited(N);
	visited[start] = true;

	printAllHamiltonianPaths(g, start, visited, path, N);

	return 0;
}