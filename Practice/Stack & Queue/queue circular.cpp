#include <iostream>
using namespace std;

//in circular queue basically jab rear reaches size-1 then it should go back to start of array

class circularqueue{
    public:
    int size=4;
    int* arr=new int[size];
    int rear=-1;
    int front=-1;//initially front and rear both at -1

    bool isfull(){
        //when rear comes just behind front then circular mein full
        if((rear+1)%size==front){
            return true;
        }
        return false;
    }

    bool isempty(){
        if(rear==-1&&front==-1){
            return true;
        }
        return false;
    }

    void enqueue(int x){
        if(isfull()){
            cout<<"NO SPACE IN QUEUE"<<endl;
        }
        else if(isempty()){
            rear=front=0;//bring rear to first index again
        }
        else{
            rear=(rear+1)%size;
        }
         arr[rear]=x;//jo bhi condition matched then uspe inserted
    }

    int dequeue(){
        int value= arr[front];
        if(isempty()){
            cout<<"CANT DEQUEUE ARRAY IS EMPTY"<<endl;
        }
        else if(front==rear){//means single element in queue tou restart
            front=rear=-1;
        }
        else{
            front=(front+1)%size;
        }
       return value;
    }

    void display(){
        if(isempty()){
            cout<<"QUEUE IS EMPTY"<<endl;
            return;
        }
        //same as ptr=head
        int i=front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%size;//move circularly
        }
        cout<<arr[rear]<<" ";

    }
};

int main(){
    circularqueue q;
    cout<<"is empty? "<<q.isempty()<<endl;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.display();//1 2 3 4

    cout<<endl<<endl;

    cout<<q.dequeue()<<" ";//1
    cout<<q.dequeue();//2

    cout<<endl;
    q.display();//should show 3 4

    q.enqueue(10);
    q.enqueue(20);

    cout<<endl;
    q.display();//10 20 3 4

}
