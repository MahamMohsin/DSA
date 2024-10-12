#include <iostream>
using namespace std;

int partitioning(int arr[],int low,int high){
    int mid=(low+high)/2;
    int start=low;
    int end=high;
    int pivot=arr[mid];

    while(start<=end){
        while(arr[start]<pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<=end){
            int temp=arr[end];
            arr[end]=arr[start];
            arr[start]=temp;

            start++;
            end--;
        }
    }
    return start;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int loc=partitioning(arr,low,high);

        quicksort(arr,low,loc-1);
        quicksort(arr,loc,high);
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size];
    cout<<"\nEnter Array Elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"\nDisplaying Original Array: "<<endl;
    display(arr,size);

    quicksort(arr,0,size-1);
    cout<<"\nDisplaying After Sorting: "<<endl;
    display(arr,size);

return 0;
}