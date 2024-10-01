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

void insert(node* &head,int d){
    node* n=new node(d);
    if(head==NULL){
        head=n;
        n->next=NULL;
    }
    else{
        n->next=head;
        head=n;
    }
}

void display(node* ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

bool searching(node* ptr,int key){
    if(ptr==NULL){
        return false;
    }
    if(ptr->data==key){
        return true;
    }
    return searching(ptr->next,key);
}

int main(){
    node* head=NULL;

    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);

    display(head);

    int key=3;
    if(searching(head,key)){
        cout<<"\nVALUE "<<key<<" FOUND IN LINKED LIST";
    }
    else{
        cout<<"\nVALUE NOT FOUND";
    }

return 0;
}