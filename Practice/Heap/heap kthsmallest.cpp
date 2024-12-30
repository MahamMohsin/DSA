#include <iostream>
using namespace std;
//using max heap to find kth smallest element
//the approach is to insert elements till the kth-1 index of arr
//then comparing the max element at top with the elements from k->n-1
//if top()>element pop the element at top and push the element that is smaller than top
//then return the value at top that will be your answer(kth smallest value)
//time complexity O(klogn) where k is num of elements and n is heap/priority queue size

class maxheap{
    public:
    int* arr;
    int size;
    int cap;

    maxheap(int c){
        size=0;
        cap=c;
        arr=new int[cap];
    }

    //heapifying upwards incase of insertion
    void heapifyUp(int i){
        int parent=(i-1)/2;//zero based indexing

        if(i>0 && arr[i]>arr[parent]){
            //swapping because i cant be bigger than parent
            swap(arr[i],arr[parent]);
            //then recursive call from parent to check further upwards
            heapifyUp(parent);
        }
    }

    //same as normal heapify function made when creating a heap from scratch/root
    //starts from root so used for deletion case
    void heapifyDown(int i){
        int largest=i;//for max heap
        int right=2*i+2;
        int left=2*i+1;

        if(left<size && arr[largest]<arr[left]){
            largest=left;
        }

        if(right<size && arr[largest]<arr[right]){
            largest=right;
        }

        if(largest != i){
            swap(arr[largest],arr[i]);
            heapifyDown(largest);//start from top to bottom
        }
    }

    //resizing heap if heap filled
    void resize(){
        cap*=2;

        int* newarr=new int[cap];
        for(int i=0;i<size;i++){
            arr[i]=newarr[i];
        }
        delete[] arr;
        arr=newarr;
    }

    //inserting in maxheap
    void push(int value){
        if(size==cap){
            resize();
        }
        else{
            arr[size]=value;
            heapifyUp(size);//heapifying upwards from the index from insertion
            size++;
        }
    }

    //getting topmost element
    int top(){
        if(size==0){
            cout<<"HEAP IS EMPTY!"<<endl;
            return -1;//error
        }
        return arr[0];
    }

    void pop(){
        if(size==0){
            cout<<"Heap is empty!"<<endl;
            return;
        }
        //deleting done from top and top element replaced with last
        arr[0]=arr[size-1];
        size--;
        heapifyDown(0);//heapifying from top to bottom
    }

    bool isempty(){
        return size==0;
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    maxheap m(10);
    int arr[]={7,8,10,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;

    cout<<"Enter the kth value for finding kth smallest value: ";
    cin>>k;

    //1.inserting elements till k-1 in max heap
    for(int i=0;i<=k-1;i++){
        m.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]<m.top()){
            m.pop();
            m.push(arr[i]);
        }
    }

    cout<<k<<"th smallest element is: "<<m.top();

return 0;
}