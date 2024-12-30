#include <iostream>
using namespace std;

class linearqueue{
    public:
    int size;//size of queue
    int* arr;//dynamic arr
    int rear,front;//front used for pop rear for push

    linearqueue(int s){
        size=s;
        arr=new int[size];
        rear=front=-1;//making both point in same position and before array's 1 index
    }

    bool isfull(){
        if(rear==size-1){//reached last element
            return true;
        }
        return false;
    }

    bool isempty(){
        //or front/top -1 hai means popping hoye hee nahi and queue has elements
        //front exceeds rear
        if(front==-1||front>rear){
            return true;
        }
        return false;
    }

    //basically pushing/insertion
    void enqueue(int x){
        if(isfull()){
            cout<<"QUEUE IS FULL!"<<endl;
        }
        else if(isempty()){
            rear=front=0;//bring both on first array index for insertion
        }
        else{
            rear++;
        }
         arr[rear]=x;//value inserted after satifying conditions
    }

    //basically popping using front
    int dequeue(){
        if(isempty()){
            cout<<"NOTHING IN QUEUE TO DELETE!"<<endl;
        }
        //when only one element left in array to restart
        else if(front==rear){
            front=rear=-1;
        }
        else{
            front++;// warna front ko agy barha dia 
        }
            return arr[front];//returns the value curently at top     
    }

    void display(){
        if(isempty()){
            cout<<"QUEUE IS EMPTY NOTHING TO DISPLAY"<<endl;
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
};

int main(){
    linearqueue q(6);

    cout<<"is empty? "<<q.isempty()<<endl;

    q.enqueue(6);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);

    //should display 6 5 4 3 2 1
    q.display();

    cout<<"\nis full? "<<q.isfull()<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<endl;
    q.display();//4 3 2 1

}