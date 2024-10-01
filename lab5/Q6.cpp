#include <iostream>
using namespace std;

#define n 4

bool isValid(int row,int col,int flags[n][n]){
    for(int i=0;i<row;i++){
        if(flags[i][col]==1){
            return false;
        }
    }
    
    //checking left diagonal
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(flags[i][j]==1){
            return false;
        }
    }

    //checking right diagonal
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(flags[i][j]==1){
            return false;
        }
    }
    return true;
}

void flagsplacement(int row,int& maxflags,int flags[n][n],int currentflags){
    if(row==n){
        if(currentflags>maxflags){
            maxflags=currentflags;
        }
        return;
    }
    
    for(int col=0;col<n;col++){
        if(isValid(row,col,flags)){
            flags[row][col]=1;
            currentflags++;
            flagsplacement(row+1,maxflags,flags,currentflags);

            flags[row][col]=0;
            currentflags--;
        }
    }
}

int main(){
    int flags[n][n]={0};
    int maxflags=0;
    int currentflags=0;

    flagsplacement(0,maxflags,flags,currentflags);

    cout<<"MAXIMUM "<<maxflags<<" FLAGS CAN BE PLACED!"<<endl;

return 0;
}