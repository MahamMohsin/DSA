#include <iostream>
using namespace std;

class node{
public:
char data;
node* next;

node(char d){
    data=d;
    this->next=NULL;
}
};

class linkedlist{
    public:
    node* head=NULL;

    void insert(char d){
        node* n=new node(d);

        if(head==NULL){
            head=n;
        }
        else{
            node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n;
            n->next=NULL;
        }
    }

    void display(){
        node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }

    void reversal(){
        node* current=head;
        node* previous=NULL;
        node* nexttoprev=NULL;

        while(current!=NULL){
        nexttoprev=previous;
        previous=current;
        current=current->next;
        previous->next=nexttoprev;
        }
        head=previous;
    }
};

int main(){
    linkedlist l;

    l.insert('M');
    l.insert('A');
    l.insert('H');
    l.insert('A');
    l.insert('M');

    l.insert('M');
    l.insert('O');
    l.insert('H');
    l.insert('S');
    l.insert('I');
    l.insert('N');

    l.display();
    cout<<"\npost reversal\n";
    l.reversal();
    l.display();


}