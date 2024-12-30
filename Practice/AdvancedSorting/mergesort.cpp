#include <iostream>
using namespace std;

//merging two subarrays of arr[]
void merge(int arr[],int low,int mid,int high){
int len1=mid-low+1;
int len2=high-mid;

//making 2 arrays to get array divided into 2
int* first=new int[len1];
int* sec=new int[len2];

//copying array elements in new arrays
//should copy starting from zero
for(int i=0;i<len1;i++){
    first[i]=arr[low+i];
}

//copying other half
for(int i=0;i<len2;i++){
    sec[i]=arr[mid+1+i];
}

//merging arrays back to normal array sorting
int i=0;int j=0; int k=low;
while(i<len1 && j<len2){
    if(first[i]<sec[j]){
        arr[k++]=first[i++];
    }
    else{
        arr[k++]=sec[j++];
    }
}

//copying remaining elements of first array
while(i<len1){
    arr[k++]=first[i++];
}
while(j<len2){
    arr[k++]=sec[j++];
}
}

void mergesort(int arr[],int low,int high){
    //base case
    if(low>=high){
        return;
    }

    int mid=(low+high)/2;
    mergesort(arr,low,mid);//first into half
    mergesort(arr,mid+1,high);//then into sec half
    merge(arr,low,mid,high);//then sending the array for merging    
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[]={65,78,99,34,30,22};
    int size=sizeof(arr)/sizeof(arr[0]);

    print(arr,size);
    cout<<endl<<endl;

    mergesort(arr,0,size-1);
    print(arr,size);
}