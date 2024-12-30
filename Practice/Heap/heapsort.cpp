#include <iostream>
using namespace std;

class heap{
    public:
    int* arr;
    int size;
    int cap;

    heap(int c){
        cap=c;
        size=0;
        arr=new int[cap+1];
        arr[0]=0;
    }

    void heapify(int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;

        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[right]>arr[largest]){
            largest=right;
        }

        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(n,largest);
        }
    }

    void resize(){
        int* newarr=new int[cap*2];
        for(int i=1;i<=size;i++){
            arr[i]=newarr[i];
        }
        delete[] arr;
        arr=newarr;
        cap*=2;
    }

    void insert(int val){
        if(size==cap){
            resize();
        }

        size++;
        arr[size]=val;
        int i=size;

        while(i>1 && arr[i]>arr[i/2]){//basically heapify up
            swap(arr[i],arr[i/2]);
            i=i/2;
        }
    }

    void heapsort(){
        for(int i=size/2;i>1;i--){
            heapify(size,i);//parent se heapify
        }

        for(int i=size;i>=2;i--){
            swap(arr[i],arr[1]);
            heapify(i-1,1);//ek kam
        }
    }

    void display(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    heap p(10);

    p.insert(10);
    p.insert(20);
    p.insert(30);
    p.insert(40);
    p.insert(50);

    p.display();//max heap

    p.heapsort();
    cout<<endl;
    p.display();

}