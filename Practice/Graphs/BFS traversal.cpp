#include <iostream>
#include <queue>
using namespace std;

void BFS(int start, int graph[][5], int n) {
    bool visited[n] = {false}; // Visited array initialized to false
    queue<int> q;              // Queue for BFS

    // Start BFS from the given node
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " "; // Process the current node

        // Explore all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true; // Mark the node as visited
            }
        }
    }
    cout << endl;
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

    int startNode = 0; // Specify the starting node
    BFS(startNode, graph, 5);

    return 0;
}
