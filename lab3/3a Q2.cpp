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
node* copylist(){
    node* copyhead=new node(head->data);
    node* current=head->next;
    node*cptr=copyhead;

    while(current!=NULL){
        cptr->next=new node(current->data);
        cptr=cptr->next;
        current=current->next;
}
return copyhead;
}

node* reverse(node* head){
    node*current=head;
    node* previous=NULL;
    node* nextToprev=NULL;

    while(current!=NULL){
        nextToprev=previous;
        previous=current;
        current=current->next;

        previous->next=nextToprev;
    }
    head=previous;
    return previous;
}

bool isPalindrome(){
    node* copied=copylist();
    node* reversed=reverse(copied);

    node* ptrToOriginal=head;
    node* ptrToreversed=reversed;

    while(ptrToOriginal!=NULL && ptrToreversed!=NULL){
        if(ptrToOriginal->data!=ptrToreversed->data){
            return false;
        }
        else{
            ptrToOriginal=ptrToOriginal->next;
            ptrToreversed=ptrToreversed->next;
        }
        }
        return(ptrToOriginal==NULL&&ptrToreversed==NULL);
}
};

int main(){
    linkedlist l;
    int n,data;

    cout<<"Enter number of nodes: ";
    cin>>n;

    cout<<"Enter the data: ";
    for(int i=0;i<n;i++){
        cin>>data;
        l.insert(data);
    }

    cout<<"\nDISPLAYING LINKED LIST\n";
    l.display();

    cout<<"\nIS THE ABOVE LIST PALINDROME? ";
    if(l.isPalindrome()){
        cout<<"\nList is palindrome!";
    }
    else{
        cout<<"\nNot palindrome!";
    }

return 0;    
}