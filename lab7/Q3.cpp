#include <iostream>
using namespace std;

void mergeAscending(int arr[],int low,int mid,int high){
    int len1=mid-low+1;
    int len2=high-mid;

    int* first=new int[len1];
    int* sec=new int[len2];

    for(int i=0;i<len1;i++){
        first[i]=arr[low+i];
    }
    for(int i=0;i<len2;i++){
        sec[i]=arr[mid+1+i];
    }

    int i=0; int j=0; int k=low;
    while(i<len1 && j<len2){
        if(first[i]<sec[j]){
            arr[k++]=first[i++];
        }
        else{
            arr[k++]=sec[j++];
        }
    }

    while(i<len1){
        arr[k++]=first[i++];
    }
    while(j<len2){
        arr[k++]=sec[j++];
    }

    delete[] first;
    delete[] sec;
}

void mergeDescending(int arr[],int low,int mid,int high){
    int len1=mid-low+1;
    int len2=high-mid;

    int* first=new int[len1];
    int* sec=new int[len2];

    for(int i=0;i<len1;i++){
        first[i]=arr[low+i];
    } 
    for(int i=0;i<len2;i++){
        sec[i]=arr[mid+i+1];
    }

    int i=0;int j=0;int k=low;
    while(i<len1 && j<len2){
        if(first[i]>sec[j]){
            arr[k++]=first[i++];
        }
        else{
            arr[k++]=sec[j++];
        }
    }

    while(i<len1){
        arr[k++]=first[i++];
    }

    while(j<len2){
        arr[k++]=sec[j++];
    }

    delete[] first;
    delete[] sec;
}

void mergesort(int arr[],int low,int high,bool isAscending){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;

    mergesort(arr,low,mid,isAscending);
    mergesort(arr,mid+1,high,isAscending);
    
    if(isAscending){
        mergeAscending(arr,low,mid,high);
    }
    else{
        mergeDescending(arr,low,mid,high);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;

    int* arr=new int[n];
    cout<<"\nEnter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"\nDisplaying Before Sorting: "<<endl;
    display(arr,n);

    mergesort(arr,0,n-1,true);
    cout<<"\nDisplaying After Sorting(Ascending): "<<endl;
    display(arr,n);

    mergesort(arr,0,n-1,false);
    cout<<"\nDisplaying After Sorting(Descending): "<<endl;
    display(arr,n);

    delete[] arr;

return 0;
}