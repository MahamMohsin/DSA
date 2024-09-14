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

void insert(int d){
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
        n->prev=ptr;
        n->next=NULL;
    }
}

void display(){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

node* getAlternates(){
    node* alternatelist=NULL;
    node* current=head;
    node* prev=NULL;

    bool flag=0;//for checking alternates

    while(current!=NULL){
        if(flag){
            node* ptr=current;    
        if(prev!=NULL){
            prev->next=current->next;
        }
        if(current->next!=NULL){
            current->next->prev=prev;
        }
        current=current->next;

        //reversing
        ptr->next=alternatelist;
        if(alternatelist!=NULL){
            alternatelist->prev=ptr;
        }
        alternatelist=ptr;
        alternatelist->prev=NULL;
        }

        else{
            prev=current;
            current=current->next;
        }
        flag=!flag;
    }
    return alternatelist;
}

void insertAlternates(node* alternatelist){
    node* ptr=head;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=alternatelist;
    if(alternatelist!=NULL){
        alternatelist->prev=ptr;
    }
}

void merging(){
    node* alternatelist=getAlternates();
    insertAlternates(alternatelist);
}
};

int main(){
    doublylinkedlist l;
    int num,data;

    cout<<"Enter number of nodes: ";
    cin>>num;

    cout<<"Enter data: ";
    for(int i=0;i<num;i++){
        cin>>data;
        l.insert(data);
    }

    cout<<"\nORIGINAL LIST: "<<endl;
    l.display();

    l.merging();
    cout<<"\nMODIFIED LIST: "<<endl;
    l.display();

return 0;
}