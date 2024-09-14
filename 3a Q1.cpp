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

class linkedList{
public:
node* head=NULL;

void insertnode(int d){
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

void sepratingEO(){
//making 4 pointers to check the starting and ending of odd and even list seprately first then connecting them
    node* evenstart=NULL;
    node* eventail=NULL;
    node* oddstart=NULL;
    node* oddtail=NULL;
    node* current=head;

    while(current!=NULL){
        int num=current->data;
        if(num%2==0){
            if(evenstart==NULL){
                evenstart=current;
                eventail=evenstart;
            }
            else{
                eventail->next=current;
                eventail=eventail->next;
            }
        }
        else{
            if(oddstart==NULL){
                oddstart=current;
                oddtail=oddstart;
            }
            else{
                oddtail->next=current;
                oddtail=oddtail->next;
            }
        }
    current=current->next;
    }
        if(evenstart==NULL){
            head=oddstart;
        }
        else if(oddstart==NULL){
            head=evenstart;
        }
        else{
        eventail->next=oddstart;
        oddtail->next=NULL;

        head=evenstart;
        }
}
};

int main(){
    linkedList l;

    int n,data;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    cout<<"Enter the data: ";
    for(int i=0;i<n;i++){
        cin>>data;
        l.insertnode(data);
    }

    cout<<"\nORIGINAL LIST: "<<endl;
    l.display();

    l.sepratingEO();
    cout<<"\nMODIFIED LIST: "<<endl;
    l.display();

return 0;
}