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

class circularDoublyLL{
public:
node* head=NULL;
node* tail;

void insertAtend(int d){
    node* n=new node(d);

    if(head==NULL){
        head=n;
        head->next=head;
        head->prev=head;
    }
    else{
        tail=head->prev;
        tail->next=n;
        n->prev=tail;
        n->next=head;
        head->prev=n;
    }
}

void insertAtstart(int d){
    node* n=new node(d);

    if(head==NULL){
        head=n;
        head->next=head;
        head->prev=head;
    }
    else{
        tail=head->prev;
        n->next=head;
        n->prev=tail;
        head->prev=n;
        tail->next=n;
        head=n;
    }
}

void insertAtpos(int d,int pos){
    if(pos==1){
        insertAtstart(d);
    }
    else{
        node* n=new node(d);
        node* ptr=head;

        for(int i=1;i<pos-1;i++){
            ptr=ptr->next;
        }
            n->next=ptr->next;
            n->prev=ptr;
            ptr->next->prev=n;
            ptr->next=n;
    }
}

void deletion(int pos){
    if(pos==1){
        if(head->next==head){
            delete head;
            head=NULL;
        }
        else{
            tail=head->prev;
            node* ptr=head;//for node to delete
            head=head->next;
            head->prev=tail;
            tail->next=head;
            delete ptr;
        }
        return;
    }

    node* current=head;
    for(int i=1;i<pos;i++){
        current=current->next;
    }
    current->prev->next=current->next;
    current->next->prev=current->prev;
    delete current;
}

void display(){
        node* ptr=head;
        do{
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }while(ptr!=head);
        cout<<ptr->data<<"->";
    }
};

int main(){
    circularDoublyLL cdl;

    cdl.insertAtend(15);
    cdl.insertAtend(20);
    cdl.insertAtstart(5);
    cdl.insertAtpos(10,2);
    cdl.display();

    cdl.deletion(1);
    cout<<"\nPrinting After deleting first node"<<endl;
    cdl.display();

return 0;
}