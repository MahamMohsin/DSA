#include <iostream>
using namespace std;

bool friends[5][5]={
    {0,1,0,1,1},//person 0 is friends with 1,3,4
    {1,0,1,0,1},//person 1 is friends with 0,2,4
    {0,1,0,0,0},//person 2 is friends with 1
    {1,0,0,0,1},//person 3 is friends with 0,4
    {1,1,0,1,0}//person 4 is friends with 0,1,3
};

bool mutual(int p1,int p2){
    for(int i=0;i<5;i++){
        if(friends[p1][i] && friends[p2][i]){
            return true;
        }
    }
     return false;
}

int main(){
    int p1,p2;
    cout<<"Finding Mutual Friends"<<endl<<endl;

    cout<<"Enter person 1: ";
    cin>>p1;
    cout<<"Enter person 2: ";
    cin>>p2;

    if(mutual(p1,p2)){
        cout<<"Mutual friend(s) found!";
    }
    else{
        cout<<"Mutual friend not found";
    }

return 0;
}