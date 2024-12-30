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

class stackList{
public:
node* top=NULL;//considered as head

//insert from top
void push(int d){
    node* n=new node(d);
    if(top==NULL){
        top=n;
        top->next=NULL;
    }
    else{
        n->next=top;
        top=n;
    }
}

//basically deletion from top
int pop(){
    if(top==NULL){
        return -1;
    }
    else{
        node* ptr=top;
        top=top->next;
        int x=ptr->data;//value lerhy jo top pe thi
        delete ptr;
        return x;
    }
}

bool empty(){
    if(top==NULL){
        return true;
    }
    return false;
}

bool isfull(int d){
    node* n=new node(d);//if unable to allocate mem in heap then is full

    if(n==NULL){
        return true;
    }
    return false;
}

void printing(){
    node* ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

void findAll(){
    int temp;
    int sum=0;
    int min = 2147483647;  // Maximum value for a 32-bit integer INT_MAX
    int max = -2147483648; // Minimum value for a 32-bit integer INT_MIN

    while(top!=NULL){
        temp=pop();
        if(temp>max){
            max=temp;
        }
        if(temp<min){
            min=temp;
        }
        sum=sum+temp;
    }
    cout<<"MIN: "<<min<<endl;
    cout<<"MAX: "<<max<<endl;
    cout<<"SUM: "<<sum<<endl;
   }
};

int main(){
    stackList l;
    l.push(3);
    l.push(2);
    l.push(1);
    //should print 1 2 3
    l.printing();
    cout<<endl;
    l.findAll();
    
}