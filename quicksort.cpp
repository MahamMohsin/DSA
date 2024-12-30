#include <iostream>
using namespace std;

//backbone of quicksort
int partitioning(int arr[],int low,int high){
    int start=low;
    int end=high;
    int pivot=arr[start];//taking starting el as pivot

    //keep running loop till end if greater than start
    while(start<end){
        //while loop used so you keep doing it and swapping until s>e
        while(arr[start]<=pivot){
            start++;//if starting index less than or equal to pivot element increment start
        }
        while(arr[end]>pivot){
            end--;//simultaneously decrement end if its greater than pivot 
        }
        //now swap the currently found end and start as to bring smaller el before pivot pos and bigger after
        if(start<end){
            int temp=arr[end];
            arr[end]=arr[start];
            arr[start]=temp;
        }
    }
    //the swapping stops when s>e then finally the pivot element pos is swapped with the element where end is pointed
    int temp=arr[end];
    arr[end]=arr[low];
    arr[low]=temp;
    
    //now pivot element is same but its loc changed to new end pos
    return end;
}

int quicksort(int arr[],int low,int high){
    //simply functions calls sent isme
    //kinda same as mid
    if(low<high){
    int loc=partitioning(arr,low,high);

    //now dividing into sub arrays
    quicksort(arr,low,loc-1);   
    quicksort(arr,loc+1,high);
}
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={4,3,6,8,2,1,9,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    //right i.e end would be size-1
    //while left i.e start would be zero

    //before sorting
    print(arr,size);
    cout<<endl<<endl;

    //only call sent to quicksort bec partioning call will be made within quicksort
    quicksort(arr,0,size-1);

    //after sorting
    print(arr,size);
}