#include <iostream>
using namespace std;

#define n 4

//solving for queens problem where no 2 queens are in the same column and not in the same diagonal
//we will check if there is already a queen placed in a row(not necessary) col and diagonal or not 

//let x be row y be column
bool isvalid(int* arr[],int x,int y){
    //checking each column so for that har row check hogi and har row send queens walay func mein hogi
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    //now checking left diagonal in which row and col both will decrement
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    //checking right diagonal in which col inc and row dec
    while(row>=0 && col<y){
        if(arr[row][col]==1){
            return false;
        }
        col++;
        row--;
    }

    return true;//if available move
}

//no need to take col bec we are recursively checking it by row in above function
bool QueenMove(int* arr[],int x){
    //base condition (when all rows checked)
    if(x==n){
        return true;//all placed
    }

    for(int col=0;col<n;col++){
        if(isvalid(arr,x,col)){
        arr[x][col]=1;//if valid pos set 1 there
        

        //iterating thro rows
        if(QueenMove(arr,x+1)){
            return true;
        }

        arr[x][col]=0;//backtrack
        }
    }
    return false;//when all failed
}

int main(){
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }

    //if true conditions met print
    if(QueenMove(arr,0)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<" "<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}