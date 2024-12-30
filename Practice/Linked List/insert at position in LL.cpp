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

void insertAtTail(node* &head,node* &tail,int d){
node* t=new node(d);
//now since t will be our last node we alot its next to null
t->next=NULL;
if(head==NULL){
    head=tail=t;
}
else{
//assign t to tail's next 
tail->next=t;
//now make t as tail
tail=t;
}
}

//we'll take reference of head pointer bec we will start from first position to the required pos
void insertAtPos(node* head,int d,int pos){

    node* newnode=new node(d);//a new node made in heap using the value given from main
    node* p=head;//making a ptr to traverse through the list and stop at gievn position

    //we'll run till pos-1 kiyunke ussi position pe laakr chorna
    if(pos==1){
        insertAtHead(head,d);
    }
    //start at 1 kiyunke if ==1 hota tou head ko hee assign krdete
    for(int i=1;i<pos-1;i++){
        //make p traverse until we reach the position
        p=p->next;
    }
    //when finall position reached connect p's next to new node's next 
        newnode->next=p->next;
        p->next=newnode;//new node ka address p ke next mein


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
    node1->insertAtPos(head,13,3);
    node1->print(head);

}