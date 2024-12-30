#include <iostream>
using namespace std;

#define n 6
class stack{
    int* arr;//we will dynamically allocate array 
    int top;//will keep track of indexes

    public:
    stack(){
        arr=new int[n];
        top=-1;//array se pehle 
    }

    //for inserting in array
    void push(int x){
        if(top==n-1){
            cout<<"No more values can be pushed"<<endl;
            return;//end
        }
        else{
            top++;//moves to next index
            arr[top]=x;//top ke index pe value inserted
        }
    }

    //removes value
    void pop(){
        if(top==-1){
            cout<<"Array is empty"<<endl;
        }
        else{
            top--;
        }
    }

    int Top(){
        if(top==-1){
            cout<<"Stack empty"<<endl;
        }
            return arr[top];
    }

    bool empty(){
        if(top==-1){
            return true;
        }
        return false;
    }
};

int main(){
    //pehle 5 nikla then 4 then 3
    stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    cout<<s.Top();//will display 4 bec 5 removed
    s.empty();
}