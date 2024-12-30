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
    node* tail=NULL;
    void insertAttail(int d){
        node* n=new node(d);
        if(head==NULL){
            head=n;
            tail=n;
            tail->next=NULL;
        }
        else{
            //node* ptr=head;
            tail->next=n;
            tail=n;
            tail->next=NULL;
           /* while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n;
            n->next=NULL;*/
        }
    }

    void display(){
        node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
    }

    void reversal(int start,int end){
        node* current=head;
        node* prev=NULL;
        node* nextToprev=NULL;
        node* temphead;
        node* temptail;
        node* afterend;

        while(current!=NULL){
            if(start==current->data){
                temphead=current;
            }
            if(end==current->data){
                temptail=current;
                 afterend=temptail->next;
            }
            current=current->next;
        }
node* ptr=temphead;
        while(ptr!=afterend){
            nextToprev=prev;
            prev=ptr;
            ptr=ptr->next;
            prev->next=nextToprev;
        }
        temphead=prev;

        head->next=temphead;
        afterend->next=tail;
    }
};

int main(){
    linkedlist l;
    l.insertAttail(1);
    l.insertAttail(2);
    l.insertAttail(3);
    l.insertAttail(4);
    l.insertAttail(5);
    l.insertAttail(6);
    l.insertAttail(7);
    l.display();

    l.reversal(2,5);
    cout<<endl;
    l.display();
}