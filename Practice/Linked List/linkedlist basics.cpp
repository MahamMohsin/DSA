#include <iostream>
using namespace std;

//making a structure for node having a data and a next pointer connecting to next node in linked list
struct node{
    int data;
    struct node* next;
};

int main(){
    //making a linked list
    //first node
    struct node* first=new node();
    first->data=5;
    first->next=NULL;

    //second node
    struct node* second=new node();
    second->data=10;
    second->next=NULL;

    //third node in LL
    struct node* third=new node;
    third->data=15;
    third->next=NULL;

    //now linking the Linked list
    first->next=second;//the next box in node of first connected to second
    second->next=third;//the next box in node of second connected to third

   //traversing and printing the linked list
   struct node* ptr=first;//making a ptr that points at first
   while(ptr!=NULL){
    cout<<ptr->data<<endl;
    ptr=ptr->next;
   }

   //counting nodes
   struct node* p=first;
   int count=0;
   cout<<"\nCOUNTING NODES";
   while(p!=NULL){
    cout<<"\nData: "<<p->data<<endl;
    count++;
    p=p->next;
    cout<<"Total Nodes: "<<count;
}

}