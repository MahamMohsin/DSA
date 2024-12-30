#include <iostream>
#include <limits.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data=d;
        this->next=NULL;
    }
};

class stack{
    public:
    node* top=NULL;
    
    void push(int d){
        node* n=new node(d);

        if(top==NULL){
            top=n;
            n->next=NULL;
        }
        else{
            n->next=top;
            top=n;
        }
    }

    int pop(){
        if(top==NULL){
            return -1;
        }
        else{
            node* ptr=top;
            top=top->next;
            
            int x=ptr->data;
            return x;
            delete ptr;
        }
    }

void print(){
    node* ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}
};

int main(){
    stack A,B;

    A.push(2);
    A.push(3);
    A.push(4);
    A.push(5);
    A.print();
    cout<<endl;

    while(A.top!=NULL){
    int temp=A.pop();
    int min=INT_MAX;
    int max=INT_MIN;

    if(temp>max){
        max=temp;
    }
    if(temp<min){
        min=temp;
    }
B.push(temp);
    }
    B.print();

}