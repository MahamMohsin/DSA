#include <iostream>
using namespace std;

class DirectedGraph
{
private:
    struct Node
    {
        int vertex;
        Node *next;
        Node(int v) : vertex(v), next(nullptr) {}
    };

    int vertices;
    Node **adjacencyList;

public:
    DirectedGraph(int n)
    {
        vertices = n;
        adjacencyList = new Node *[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            adjacencyList[i] = nullptr;
        }
    }

    void addEdge(int from, int to)
    {
        Node *newNode = new Node(to);
        if (adjacencyList[from] == nullptr)
        {
            // If the list is empty, make the new node the head
            adjacencyList[from] = newNode;
        }
        else
        {
            // Traverse to the end of the list and append the new node
            Node *temp = adjacencyList[from];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void BFS(int startVertex)
    {
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            visited[i] = false;
        }

        int *queue = new int[vertices];
        int front = 0, rear = -1;

        visited[startVertex] = true;
        queue[++rear] = startVertex;

        while (front <= rear)
        {
            int currentVertex = queue[front++];
            cout << "Current Vertex: " << currentVertex << endl;

            Node *temp = adjacencyList[currentVertex];
            while (temp != nullptr)
            {
                int adjacentVertex = temp->vertex;
                if (!visited[adjacentVertex])
                {
                    visited[adjacentVertex] = true;
                    queue[++rear] = adjacentVertex;
                }
                temp = temp->next;
            }
        }

        delete[] visited;
        delete[] queue;
    }

    ~DirectedGraph()
    {
        for (int i = 0; i < vertices; ++i)
        {
            Node *temp = adjacencyList[i];
            while (temp != nullptr)
            {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adjacencyList;
    }
};

int main()
{
    DirectedGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    graph.BFS(0);
}