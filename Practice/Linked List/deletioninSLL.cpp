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

  void insertAthead(int d){
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

void insertAtTail(int d){
    node* n=new node(d);

    if(head==NULL){
        head=n;
        n->next=NULL;
    }
    else{
        node* ptr=head;
        //stopping one step before ptr gets nulled
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=n;
        n->next=NULL;
    }
}

void insertAtpos(int pos,int d){
    node* n=new node(d);
    node* ptr=head;
    if(pos==1){
        insertAthead(d);
    }
    else{
        for(int i=1;i<pos-1 && ptr!=NULL ;i++){
            ptr=ptr->next;
        }
        n->next=ptr->next;//yani ptr ka next jisko point krrha hoga usko ab n karega 
        ptr->next=n;//new node ka address ptr ke next mein 

        //this is how the list will look: ptr->newnode->(ptr->next)
    }
}

void deleting(int pos){
    node* current=head;
    node* follower=NULL;//takay hum connect krwa skein
    if (pos==1){
        head=current->next;
        delete current;
    }
    else{
        for(int i=1;i<pos-1;i++){
            follower=current;
            current=current->next;
        }
        follower->next=current->next;
        delete current;

    }
}

void display(){
node* ptr=head;

while(ptr!=NULL){
    cout<<ptr->data<<"->";
    ptr=ptr->next;
}
}
};

int main(){
    linkedlist l;
    l.insertAthead(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtpos(1,1);
    l.display();
    cout<<endl;
    l.deleting(1);
    l.deleting(3);
    l.display();
}