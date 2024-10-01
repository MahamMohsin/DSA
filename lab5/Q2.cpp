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

void insert(node* &head,int d){
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

void display(node* ptr){
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
}

int countlength(node* ptr,int count){
        if(ptr==NULL){//when end reached
            return count;
        }
        return countlength(ptr->next,count+1);
}

int main(){
    node* head=NULL;

    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);

    display(head);
    cout<<endl;
    cout<<"LENGTH OF LINKED LIST IS: ";    
    int count=0;
    cout<<countlength(head,count);

return 0;
}