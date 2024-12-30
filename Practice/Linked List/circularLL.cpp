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

class circularlinkedlist{
    public: 
    node* head=NULL;
    node* tail=head;

    void insertAthead(int d){
        node* n=new node(d);

        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        else{
            n->next=head;
            head=n;
            tail->next=head;
        }
    }

    void insertAtTail(int d){
        node* n=new node(d);
        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        else{
            tail->next=n;
            tail=n;
            tail->next=head;
        }
    }

    void insertAtpos(int pos,int d){
        node* n=new node(d);
        if(pos==1){
            insertAthead(d);
        }
        else{
            node* curr=head;
            for(int i=1;i<pos-1 && curr->next!=head;i++){
                curr=curr->next;
            }
            n->next=curr->next;
            curr->next=n;
        }
    }

    void deleting(int pos){

        if(head==tail){
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
        node* current=head;
        node* prev=tail;
            for(int i=1;i<pos;i++){
                prev=current;
                current=current->next;
            }
            if(current==head){
                head=head->next;//current only used for traversing to be deleted
                tail->next=head;
            }
            else if(current==tail){
                tail=prev;
                tail->next=head;
            }
            else{
                prev->next=current->next;//skips current
            }
            delete current;
        }
    }

    //reversing
    void reversal(){
        node* current=head;
        node* prev=NULL;
        node* nexttoprevious=NULL;

        do{
            nexttoprevious=prev;
            prev=current;
            current=current->next;

            prev->next=nexttoprevious;
        }while(current!=head);
        head->next=prev;
        prev=head;
    }

    //checking if circular LL
    bool iscircular(){
        node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
            if(ptr==head){
                return true;
            }
        }
        return false;
    }

    void display(){
        node* ptr=head;

        do{
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }while(ptr!=head);
        cout<<ptr->data;
    }
};

int main(){
    circularlinkedlist cll;
    cll.insertAthead(3);
    cll.insertAthead(2);
    cll.insertAthead(1);
    cll.insertAtTail(4);
    cll.insertAtpos(5,5);
    cll.display();

    cll.deleting(5);
    cout<<endl;
    cll.display();
    if(cll.iscircular()){
        cout<<"\ntrue";
    }
    else{
        cout<<"false";
    }

    cll.reversal();
    cout<<endl;
    cll.display();
}
