#include <iostream>
#include <ctime>
using namespace std;

class task{
    public:
    int id;//task id
    int priority;

    task(){}//default

    task(int id,int p){
        this->id=id;
        priority=p;
    }
};

class heap{
task* arr;//array to store tasks
int size;
int capacity;

public:
heap(int cap){
    size=0;
    capacity=cap;
    arr=new task[cap];
}

void maxHeapify(int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size && arr[left].priority>arr[largest].priority){
        largest=left;
    }

    if(right<size && arr[right].priority>arr[largest].priority){
        largest=right;
    }

    if(largest!=i){
        task temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        maxHeapify(largest);
    }
}

void heapifyUp(int i){
    int parent=(i-1)/2;

    if(i>0 && arr[i].priority>arr[parent].priority){
        task temp=arr[i];
        arr[i]=arr[parent];
        arr[parent]=temp;
        heapifyUp(parent);
    }
}

void insert(const task &tsk){
    if(size==capacity){
        cout<<"Heap is full!"<<endl;
        return;
    }

    arr[size]=tsk;
    heapifyUp(size);
    size++;
}
//getting max priority task
task getMax(){
    if(size==0){
        cout<<"Heap is empty!"<<endl;
    }

    task maxTask=arr[0];
    arr[0]=arr[size-1];
    size--;
    maxHeapify(0);
    return maxTask;
}

bool isempty(){
    if(size==0){
        return true;
    }
    return false;
}
};

int main(){
    int n;
    cout<<"Enter number of tasks: ";
    cin>>n;
    heap scheduler(n);

    srand(time(0));

    for(int i=1;i<=n;i++){
        int priority=rand()%10+1;
        task tsk(i,priority);
        cout<<"Inserting Task: "<<tsk.id<<" with priority: "<<priority<<endl;
        scheduler.insert(tsk);
    }

    cout<<"\nOrder of Execution: "<<endl;
    while(scheduler.isempty()!=true){
        task maX=scheduler.getMax();
        cout<<"Executing Task: "<<maX.id<<" with priority: "<<maX.priority<<endl;
    }

return 0;
}
