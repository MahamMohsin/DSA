//FINDING K number of drones with largest distance 
#include <iostream>
#include <cmath>
using namespace std;

class drone{
    public:
    int x;
    int y;
    float distance;

    drone(){}
    drone(int x,int y){
        this->x=x;
        this->y=y;
        distance=sqrt(pow(x,2)+pow(y,2));
    }
};

class maxheap{
   public:
   drone* arr;
   int size;
   int cap;

   maxheap(int c){
    size=0;
    cap=c;
    arr=new drone[cap];//allocating space 
   }

   void maxheapify(int i){//used when deleting basically heapify down
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size && arr[largest].distance<arr[left].distance){
        largest=left;
    }

    if(right<size && arr[largest].distance<arr[right].distance){
        largest=right;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxheapify(largest);
    }
   }

   //when inserting
   void heapifyUP(int i){
    int parent=(i-1)/2;

    if(i>0 && arr[i].distance>arr[parent].distance){
        swap(arr[i],arr[parent]);//because maintaining max heap
        heapifyUP(parent);
    }
   }

   void insert(drone data){
    if(size==cap){
        cout<<"Heap is full";
    }
    arr[size]=data;//drone data entered
    heapifyUP(size);
    size++;
   }

   bool isempty(){
    return size==0;
   }

   drone getMaxDistance(){
    if(isempty()){
        cout<<"Heap has no drones!"<<endl;
    }
    //replace top with last for removing and then apply top->bottom heapify i.e max heapify
    
    drone temp=arr[0];
    arr[0]=arr[size-1];
    size--;
    maxheapify(0);  //from top
    return temp;//to get class type ka value you make class type ka func
   }

   void getKdrones(int k){
    for(int i=0;i<k;i++){
        drone d=getMaxDistance();
        cout<<"("<<d.x<<","<<d.y<<")"<<endl;
    }
   }
};

int main(){
    int capacity=10;
    maxheap mh(capacity);

    //else drone d(3,4) if ref sent //mh.insert(d)

    mh.insert(drone(1,3));
    mh.insert(drone(2,-2));
    mh.insert(drone(5, 8));
    mh.insert(drone(0, 1));
    mh.insert(drone(7, 6));

    mh.getKdrones(2);
}
