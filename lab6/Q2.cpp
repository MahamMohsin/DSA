#include <iostream>
using namespace std;

class queue{
    int size;
    int* customersqueue;
    int rear;
    int front;
    public:
    queue(int s){
        size=s;
        customersqueue=new int[size];
        rear=-1;
        front=-1;
    }

    bool isempty(){
        if(front==-1||front>rear){
            return true;
        }
        return false;
    }

    void enqueue(int ID){
        if(rear==size-1){
            cout<<"QUEUE IS FULL!"<<endl;
        }
        else if(isempty()){
            front=rear=0;
        }
        else{
            rear++;
        }
        customersqueue[rear]=ID;
    }

    int dequeue(){
        if(isempty()){
            cout<<"No customer in queue for checking out!"<<endl;
        }
        //to keep track of the customer that has checked out 
        int customer=customersqueue[front];
        if(front==rear){
            rear=front=-1;
        }
        else{
            front++;
        }
        return customer;       
    }

    void display(){
        if(isempty()){
            cout<<"No customer in queue currently!"<<endl;
        }
        else{
        cout<<"Customers in Queue: "<<endl;        
        for(int i=front;i<=rear;i++){
            cout<<customersqueue[i]<<" ";
        }
    }
    }
};

int main(){
    int customerarr[]={13,7,4,1,6,8,10};
    int size=sizeof(customerarr)/sizeof(customerarr[0]);

    queue q(size);
    for(int i=0;i<size;i++){
        q.enqueue(customerarr[i]);
    }
    q.display();

    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<"Checking out Customer ID: "<<q.dequeue()<<endl;
    }
    cout<<endl;

return 0;
}
