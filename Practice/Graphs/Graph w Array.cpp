#include <iostream>
using namespace std;
class Graph{
    int no_of_vertices;
    int **adjacency_matrix;
    public:
    Graph(int n):no_of_vertices(n){
        adjacency_matrix = new int *[no_of_vertices];
        for(int i=0;i<no_of_vertices;i++){
            adjacency_matrix[i]= new int[no_of_vertices];
            for(int j=0;j<no_of_vertices;j++){
                adjacency_matrix[i][j]=0; //initialize with 0 
            }
        }
    }
    void add_edge(int u,int v){ // adding an edge from U to V (0 based)
        adjacency_matrix[u][v]=1;
        adjacency_matrix[v][u]=1; //as its an undirected graph (for directed, remove this line)
        
    }
    void remove_edge(int u,int v){
        adjacency_matrix[u][v]=0;
        adjacency_matrix[v][u]=0;
    }
    void display_matrix(){
        for(int i=0;i<no_of_vertices;i++){
            for(int j=0;j<no_of_vertices;j++){
                cout<<adjacency_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    // add a destructor if necessary.
     void display_list() {
         for (int i = 0; i < no_of_vertices; i++) {
            cout << i << " --> ";
            for (int j = 0; j < no_of_vertices; j++) {
                if (adjacency_matrix[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
    }
     }
};
int main(){
    int vertices=5;
    Graph graph(vertices);
    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(3,2);
    graph.add_edge(4,2);
    graph.add_edge(2,2);
    graph.display_matrix();
    graph.display_list();
  

}