#include <iostream>
using namespace std;
#define n 5

bool solvingmaze(int maze[n][n],int x,int y,int solvemaze[n][n]);

void displaysolvedmaze(int solvemaze[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<" "<<solvemaze[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int maze[n][n],int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1){
        return true;
    }
    return false;
}

bool solvemaze(int maze[n][n]){
    int solvemaze[n][n]={0};

    if(solvingmaze(maze,0,0,solvemaze)==false){
        cout<<"No solution possible!"<<endl;
        return false;
    }
    displaysolvedmaze(solvemaze);
    return true;
}

bool solvingmaze(int maze[n][n],int x,int y,int solvemaze[n][n]){
    if(x==n-1 && y==n-1 && maze[x][y]==1){
        solvemaze[x][y]=1;
        return true;
    }

    if(isSafe(maze,x,y)==true){
        if(solvemaze[x][y]==1){
            return false;
        }
        solvemaze[x][y]=1;
        if(solvingmaze(maze,x+1,y,solvemaze)==true){
            return true;
        }
        if(solvingmaze(maze,x-1,y,solvemaze)==true){
            return true;
        }
        if(solvingmaze(maze,x,y+1,solvemaze)==true){
            return true;
        }
        if(solvingmaze(maze,x,y-1,solvemaze)==true){
            return true;
        }

        solvemaze[x][y]=0;
        return false;        
    }
    return false;
}

int main(){
    int maze[n][n]={
        {1,0,1,0,1},
        {1,1,1,1,1},
        {0,1,0,1,1},
        {1,0,0,1,1},
        {1,1,1,0,1}
    };

    solvemaze(maze);

return 0;
}