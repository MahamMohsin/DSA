#include <iostream>
using namespace std;

class heap{
    int* arr;
    int size;
    public:
    heap(int* input,int n){
        size=n;
        arr=new int[size];
        for(int i=0;i<size;i++){
            arr[i]=input[i];
        }
    }

    void maxHeapify(int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<size && arr[left]>arr[largest]){
            largest=left;
        }

        if(right<size && arr[right]>arr[largest]){
            largest=right;
        }

        if(largest!=i){
            int temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            maxHeapify(largest);
        }
    }

    void minHeapify(int i){
        int smallest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<size && arr[left]<arr[smallest]){
            smallest=left;
        }

        if(right<size && arr[right]<arr[smallest]){
            smallest=right;
        }

        if(i!=smallest){
            int temp=arr[i];
            arr[i]=arr[smallest];
            arr[smallest]=temp;
            minHeapify(smallest);
        }
    }

    void createMaxHeap(){
        for(int i=size/2-1;i>=0;i--){
            maxHeapify(i);
        }
    }

    void createMinHeap(){
        for(int i=size/2-1;i>=0;i--){
            minHeapify(i);
        }
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    int tree[]={7,1,6,2,5,9,10,2};
    int n=sizeof(tree)/sizeof(tree[0]);

    cout<<"MAX HEAP: "<<endl;
    heap maxHeap(tree,n);
    maxHeap.createMaxHeap();
    maxHeap.display();

    cout<<"\nMIN HEAP: "<<endl;
    heap minHeap(tree,n);
    minHeap.createMinHeap();
    minHeap.display();

return 0;
}
