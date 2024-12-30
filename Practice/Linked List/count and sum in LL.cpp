#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        this->next = NULL;
    }

    void insertAtHead(node* &head, int d) {
        node* temp = new node(d);
        temp->next = head;
        head = temp;
    }

    void insertAtTail(node* &head, node* &tail, int d) {
        node* t = new node(d);
        t->next = NULL;
        if (head == NULL) {
            head = tail = t;
        } else {
            tail->next = t;
            tail = t;
        }
    }

    void insertAtPos(node* head, int d, int pos) {
        node* newnode = new node(d);
        node* p = head;

        if (pos == 1) {
            insertAtHead(head, d);
        }

        for (int i = 1; i < pos - 1; i++) {
            p = p->next;
        }

        newnode->next = p->next;
        p->next = newnode;
    }
//counting number of nodes
    void count(node* &head){
        int count=0;
        node* cptr=head;
        while(cptr!=NULL){
            cout<<"\n"<<cptr->data<<" ";
            count++;
            cptr=cptr->next;
        }
        cout<<"\nTotal Nodes: "<<count;
    }

//summing the data of all nodes
void sum(node* &head){
    node* s=head;//assigning a new ptr that has the same address as of head
    int sum=0;
    while(s!=NULL){
       sum=sum+s->data;
       s=s->next;
}
cout<<"Total sum: "<<sum;
}
    void print(node* &head) {
        node* p = head;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }
};

int main() {
    node* node1 = new node(10);

    node* head = node1;
    node* tail = node1;

    node1->insertAtHead(head, 5);
    node1->insertAtTail(head, tail, 15);
    node1->insertAtPos(head, 13, 3);
    node1->print(head);
    cout<<"\nCount Function Called";
    node1->count(head);
    cout<<endl;
    node1->sum(head);
}
