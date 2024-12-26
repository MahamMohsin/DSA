#include <iostream>
using namespace std;

class heap{
    int* arr;
    int size;
    int origsize;//storing original size for printing incase of modification

    public:
    heap(int* input,int n){
        arr=input;
        size=n;
        origsize=n;
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

     void rootdeletion(){
        if(size<=0){return;}
        
        arr[0]=arr[size-1];
        size--;
        origsize--;
        minHeapify(0);
    }

    void heapsort(){
        for(int i=size-1;i>0;i--){
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            size--;
            maxHeapify(0);       
        }
    }

    void display(){
        for(int i=0;i<origsize;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    int arr[]={35,33,42,10,14,19,27,44,26,31};
    int n=sizeof(arr)/sizeof(arr[0]);

    heap h(arr,n);

    h.createMinHeap();
    cout<<"MIN HEAP: "<<endl;
    h.display();

    h.rootdeletion();
    cout<<"\nAfter deletion: "<<endl;
    h.display();

    h.createMaxHeap();
    cout<<"\nMAX HEAP: "<<endl;
    h.display();

    h.heapsort();
    cout<<"\nSORTED OUTPUT: "<<endl;
    h.display();

return 0;
}