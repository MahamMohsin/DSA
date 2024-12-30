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
};

class linkedlist{
public:
node*head;
//making linked list when obj made
linkedlist(){
node* n=new node(5);
node* n1=new node(10);
node* n2=new node(15);
head=n;

n->next=n1;
n1->next=n2;
n2->next=NULL;
}

node* reversing(){
node* current=head;
node* prev=NULL;
node* nextptr;

while(current!=NULL){
    nextptr=current->next;
    current->next=prev;

    prev=current;//moving prev forward
    current=nextptr;//moving current forward

}
head=prev;//previous ko head bnadia
return prev;
}

void insertAtHead(){
    node* newnode=new node(2);
newnode->next=head;
head=newnode;
}

void print(){
    node*ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
}
};

int main(){
    linkedlist l;
    l.insertAtHead();
    l.print();
    l.reversing();
    cout<<endl;
    l.print();
}
