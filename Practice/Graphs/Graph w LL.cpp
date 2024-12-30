#include <iostream>
#include <queue>
using namespace std;

class node{
public:
int vertex;
node* next;

node(int v){
    vertex=v;
    next=NULL;
}
};

class graph{
    public:
    int n;
    graph(int numofvertices){
        n=numofvertices;
    }
    node** adjList=new node*[n]();//node type list made and all following arr initiallized to null 

    void insert(int u,int v){
        //adding v to u's adj list
        node* newnode=new node(v);
        newnode->next=adjList[u];//head insertion
        adjList[u]=newnode;

        //if undirected
       node* Newnode=new node(u);
       Newnode->next=adjList[v];
       adjList[v]=Newnode;
    }

    void print(){
        for(int i=0;i<n;i++){
        node* ptr=adjList[i];//for traversing every vertex and its adj
        cout<<i<<" -> ";//displaying vertex index
        while(ptr!=NULL){
            cout<<ptr->vertex<<" ";//just like data representation
            ptr=ptr->next;
        }
        cout<<endl;
    }
    }

    void BFS(int start) {
        bool* visited = new bool[n](); // Initialize visited array to false
        queue<int> q; // Queue for BFS

        // Start BFS from the starting vertex
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from vertex " << start << ": ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Traverse all adjacent vertices of the current vertex
            node* temp = adjList[current];
            while (temp != NULL) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    q.push(temp->vertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;
        delete[] visited; // Free the allocated memory for visited array
    }
};



int main(){
    graph g(5);
    g.insert(0,1);//from 0 to 1 and 1 to 0 vice versa(for undirected)
    g.insert(0,2);
    g.insert(0,3);
    g.insert(1,1);
    g.insert(4,3);
    g.insert(3,2);

    g.print();
return 0;
}