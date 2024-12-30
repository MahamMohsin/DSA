#include <iostream>
using namespace std;

//creating Linked list
//inserting(start,any pos,end)
//searching thro the list
//counting elements in list
//summing elements in the list

//a structure of node declared containing data and a next pointer
class node{
public:
int data;
node* next;

node(int d){
    data=d;
    this->next=NULL;//making the next as null
}

//function to insert a node at head
void insertAtHead(node* &head,int d){
//here we create a new node in heap using a temp pointer and giving it the data we want
node* temp=new node(d);
//now we will make the next of temp as head(head ko temp mein assign krwado)
temp->next=head;
//then we will give the head position to temp
head=temp;
}

//function to print the linked list for which we will need to traverse the LL
//since we have to print from head we will send reference of head ptr
void print(node* &head){
cout<<"PRINTING LINKED LIST: ";
//now creating a temp pointer and assgning head to it just to deal with printing
node* p=head;
while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;
}
}

};

int main(){
    node* node1=new node(10);
    cout<<"Printing value of node created: "<<node1->data<<endl;

    node* head=node1;//a head pointer pointing to node1 which is the first node 
    cout<<"\nPrinting value of head: "<<head->data<<endl;

    //now functions will be called through node1 object
    node1->insertAtHead(head,15);
    cout<<"\nPrinting modified value at head: "<<head->data<<endl<<endl;

    node1->print(head);
}