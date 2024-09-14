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

class doublycircular{
public:
node* head=NULL;
node* tail=NULL;

void insert(int d){
    node* n=new node(d);

    if(head==NULL){
        head=tail=n;
        head->next=head->prev=head;
    }
    else{
        tail->next=n;
        n->prev=tail;
        n->next=head;
        head->prev=n;
        tail=n;
    }
}

void display(){
    node* ptr=head;
    do{
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }while(ptr!=head);           
}

void swap(int key1,int key2){
    node* n1=NULL;
    node* n2=NULL;
    node* current=head;

    for(int i=1;i<=key1;i++){
        n1=current;
        current=current->next;
    }
    current=head;

    for(int i=1;i<=key2;i++){
        n2=current;
        current=current->next;
    }

    node* prev1=n1->prev;
    node* nextptr1=n1->next;
    node* prev2=n2->prev;
    node* nextptr2=n2->next;

    if(n1->next==n2){ 
        n1->next=nextptr2;
        n1->prev=n2;
        n2->next=n1;
        n2->prev=prev1;
        prev1->next=n2;
        nextptr2->prev=n1;
    }
    else if(n1==n2->next){
        n2->next=nextptr1;
        n2->prev=n1;
        n1->next=n2;
        n1->prev=prev2;
        prev2->next=n1;
        nextptr1->prev=n2;
    }
    else{//for non adjascent case
        prev1->next=n2;
        nextptr1->prev=n2;
        prev2->next=n1;
        nextptr2->prev=n1;

        n1->next=nextptr2;
        n1->prev=prev2;
        n2->next=nextptr1;
        n2->prev=prev1;
    }

    if(head==n1){
        head=n2;
    }
    else if(n2==head){
        head=n1;
    }
    if(tail==n1){
        tail==n2;
    }
    else if(tail==n2){
        tail=n1;
    }
    tail->next=head;
    head->prev=tail;
}
};

int main(){
    doublycircular dl;
    int num,data;

    cout<<"Enter number of nodes: ";
    cin>>num;
    
    cout<<"\nEnter data: ";
    for(int i=0;i<num;i++){
        cin>>data;
        dl.insert(data);
    }

    cout<<"\nINITIAL LIST: "<<endl;
    dl.display();

    int key1,key2;
    cout<<"\nEnter keys: ";
    cin>>key1>>key2;

    dl.swap(key1,key2);
    cout<<"\nLIST AFTER SWAPPING: ";
    dl.display();

return 0;
}