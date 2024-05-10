#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // Recursive BFS function
    void recursiveBFS(int start, vector<bool>& visited) {
        if (visited[start]) return; // If already visited, return

        visited[start] = true;
        cout << start << " "; // Process the current vertex

        // Recur for all adjacent vertices
        for (int v : adj[start]) {
            if (!visited[v]) {
                recursiveBFS(v, visited);
            }
        }
    }

    // Wrapper function for BFS traversal
    void BFS(int start) {
        vector<bool> visited(V, false);
        recursiveBFS(start, visited);
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS Traversal starting from vertex 0: ";
    g.BFS(0);

    return 0;
}

