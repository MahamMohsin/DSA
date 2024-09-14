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

class circularlist{
public:
node* head=NULL;
node* tail=head;

void insertAtend(int d){
        node* n=new node(d);

        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        else{
            tail->next=n;
            tail=n;
            tail->next=head;
        }
}

void insertAtstart(int d){
        node* n=new node(d);

        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        else{
            n->next=head;
            head=n;
            tail->next=head;
        }
    }

void insertAtpos(int d,int pos){
        node* n=new node(d);

        if(pos==1){
            insertAtstart(d);
        }

        node*ptr=head;
        for(int i=1;i<pos-1&&ptr->next!=head;i++){
            ptr=ptr->next;
    }       
        n->next=ptr->next;
        ptr->next=n;
    }

void deletion(int pos){
        node* current=head;
        node* previous=tail;

        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
    }
    else{
        for(int i=1;i<pos;i++){
            previous=current;
            current=current->next;
        }
        if(current==head){
            head=head->next;
            tail->next=head;
        }
        else if(current==tail){
            tail=previous;
            tail->next=head; 
        }
        else{
            previous->next=current->next;
        }
        delete current;
    }
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
    circularlist cll;

    cll.insertAtstart(10);
    cll.insertAtstart(5);
    cll.insertAtend(20);
    cll.insertAtpos(15,3);
    cll.deletion(2);
    cll.display();
   
return 0;
}