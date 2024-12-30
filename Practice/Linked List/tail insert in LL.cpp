#include <iostream>
using namespace std;

class node{
public:
int data;
node* next;

node(int d){
    data=d;
    this->next=NULL;
}

void insertAtHead(node* &head,int d){
//making a temp node in heap
node* temp=new node(d);
temp->next=head;
head=temp;
}

//we will utalized both head and tail pointer 
void insertAtTail(node* &head,node* &tail,int d){
//a temporary pointer will be made in heap to check conditions and set the vaue to last
node* t=new node(d);
//now since t will be our last node we assign its next to null
t->next=NULL;

//now we will check if humara head/first hee tou last nhi?
if(head==NULL){
    head=tail=t;//make all same
}
else{
//assign t to tail's next 
tail->next=t;
//now make t as tail
tail=t;
}
}

void print(node* &head){
    node* p=head;//to start traversing from p
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

}
};

int main(){
    node* node1=new node(10);

    node* head=node1;
    node* tail=node1;//pointing to node1 that has value 10

    node1->insertAtHead(head,5);
    node1->insertAtTail(head,tail,15);
    node1->print(head);
}