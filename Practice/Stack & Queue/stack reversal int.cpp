#include <iostream>
using namespace std;

class stack{
    public:
    int top;
    int* arr;
    int size;

    stack(int size){
        this->size=size;
        top=-1;
        arr= new int[size];
    }

    void push(int x){
        if(top==size-1){
            cout<<"Array overflowed!";
        }
        else{
            top++;
            arr[top]=x;
        }
    }

    int pop(){
        if(top==-1){
            cout<<"Stack underflow";
        }  
            return arr[top--];//return element then decrement top
    }

    void reversal(stack &B){
        while(top!=-1){
            int temp=pop();
            B.push(temp);
        }
    }

    void print(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    stack A(5);
    stack B(5);
    A.push(4);
    A.push(3);
    A.push(2);
    A.push(1);

    A.print();//1 2 3 4

    A.reversal(B);
    cout<<endl;
    B.print();

}