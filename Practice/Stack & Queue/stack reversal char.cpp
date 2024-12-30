#include <iostream>
using namespace std;

class stack{
public:
char* arr;
int top;
int size;

stack(int size){
    this->size=size;
    top=-1;
    arr=new char[size];
}

void push(char x){
top++;
arr[top]=x;
}

int pop(){
    if(top==-1){
        cout<<"Stack out of bound";
        return -1;
    }
    else{
        top--;
        return arr[top];
    }
}

void reversal(stack &B){
    char min='Z';
    char max='A';
    char temp;

    while(top!=-1){
        temp=pop();

        if(temp>max){
            max=temp;
        }
        if(temp<min){
            min=temp;
        }

        B.push(temp);
    }
}

void print(){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
};

int main(){
    stack A(4);
    stack B(4);
    A.push('A');
    A.push('B');
    A.push('C');
    A.push('D');

    A.reversal(B);
    B.print();


}