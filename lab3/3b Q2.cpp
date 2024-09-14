#include <iostream>
using namespace std;

class node{
public:
int data;
node* next;
node* prev;

node(int d){
    data=d;
    this->next=NULL;
    this->prev=NULL;
}
};

class doublylinkedlist{
public:
node* head=NULL;
node* tail=NULL;

void insert(int d){
    node* n=new node(d);

    if(head==NULL){
        head=tail=n;
    }
    else{
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
}

void display(){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

void concatenate(doublylinkedlist& M){
    if(head==NULL){
        head=M.head;
        tail=M.tail;
    }
    else if(M.head==NULL){
        return;
    }
    else{
        tail->next=M.head;
        M.head->prev=tail;
        tail=M.tail;
    }
}
};

int main(){
    doublylinkedlist L,M;
    int numL,numM,dataL,dataM;

    cout<<"Enter the number of nodes to insert in list L: ";
    cin>>numL;

    cout<<"\nEnter data for list L: ";
    for(int i=0;i<numL;i++){
        cin>>dataL;
        L.insert(dataL);
    }

    cout<<"Enter the number of nodes to insert in list M: ";
    cin>>numM;

    cout<<"\nEnter data for list M: ";
    for(int i=0;i<numM;i++){
        cin>>dataM;
        M.insert(dataM);
    }

    cout<<"\nLIST L:\n";
    L.display();
    cout<<endl;

    cout<<"LIST M:\n";
    M.display();

    cout<<"\nLIST AFTER CONCATENATING BOTH:\n";
    L.concatenate(M);
    L.display();

return 0;
}