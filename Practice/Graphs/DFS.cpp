#include <iostream>
using namespace std;

void DFS(int node, int graph[][5], int n, bool visited[]) {
    visited[node] = true; // Mark the current node as visited
    cout << node << " ";  // Process the current node

    // Explore all adjacent nodes
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i, graph, n, visited); // Recurse for unvisited adjacent nodes
        }
    }
}

int main() {
    // Example graph represented as an adjacency matrix (5 nodes)
    int graph[5][5] = {
        {0, 1, 1, 0, 0}, // Node 0 is connected to nodes 1 and 2
        {1, 0, 0, 1, 0}, // Node 1 is connected to nodes 0 and 3
        {1, 0, 0, 1, 1}, // Node 2 is connected to nodes 0, 3, and 4
        {0, 1, 1, 0, 1}, // Node 3 is connected to nodes 1, 2, and 4
        {0, 0, 1, 1, 0}  // Node 4 is connected to nodes 2 and 3
    };

    bool visited[5] = {false}; // Visited array initialized to false

    int startNode = 0; // Specify the starting node
    cout << "DFS Traversal starting from node " << startNode << ": ";
    DFS(startNode, graph, 5, visited);

    cout << endl;
    return 0;
}
