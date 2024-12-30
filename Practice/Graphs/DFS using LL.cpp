#include <iostream>
using namespace std;

class node {
public:
    int vertex;
    node* next;

    node(int v) {
        vertex = v;
        next = NULL;
    }
};

class graph {
public:
    int n;
    node** adjList;

    graph(int numofvertices) {
        n = numofvertices;
        adjList = new node*[n](); // Initialize all entries to NULL
    }

    void insert(int u, int v) {
        // Add v to u's adjacency list
        node* newnode = new node(v);
        newnode->next = adjList[u]; // Head insertion
        adjList[u] = newnode;

        // If undirected, add u to v's adjacency list
        node* Newnode = new node(u);
        Newnode->next = adjList[v];
        adjList[v] = Newnode;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            node* ptr = adjList[i]; // Traverse each vertex's adjacency list
            cout << i << " -> ";
            while (ptr != NULL) {
                cout << ptr->vertex << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }

    void DFSUtil(int v, bool* visited) {
        // Mark the current vertex as visited
        visited[v] = true;
        cout << v << " ";

        // Recur for all adjacent vertices
        node* temp = adjList[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                DFSUtil(temp->vertex, visited);
            }
            temp = temp->next;
        }
    }

    void DFS(int start) {
        bool* visited = new bool[n](); // Initialize visited array to false

        cout << "DFS Traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;

        delete[] visited; // Free the allocated memory for visited array
    }
};

int main() {
    graph g(5);
    g.insert(0, 1); // Add edges to the graph
    g.insert(0, 2);
    g.insert(0, 3);
    g.insert(1, 1);
    g.insert(4, 3);
    g.insert(3, 2);

    g.print(); // Print the adjacency list

    g.DFS(0); // Perform DFS starting from vertex 0

    return 0;
}
