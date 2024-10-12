#include <iostream>
using namespace std;

void countsortDescending(int arr[],int n,int pos){
    int count[10]={0};

    for(int i=0;i<n;i++){
        ++count[(arr[i]/pos)%10];
    }
    for(int i=8;i>=0;i--){
        count[i]=count[i]+count[i+1];
    }
    int *newarr=new int[n];
    for(int i=n-1;i>=0;i--){
        newarr[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=newarr[i];
    }

    delete[] newarr;
}

void countsortAscending(int arr[],int n,int pos){
    int count[10]={0};

    for(int i=0;i<n;i++){
        ++count[(arr[i]/pos)%10];
    }
    for(int i=1;i<=9;i++){
        count[i]=count[i]+count[i-1];
    }
    int *newarr=new int[n];
    for(int i=n-1;i>=0;i--){
        newarr[--count[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=newarr[i];
    }

    delete[] newarr;
}

void radixsort(int arr[],int n,bool isAscending){
    int maxVal=arr[0];

    for(int i=0;i<n;i++){
        if(arr[i]>maxVal){
            maxVal=arr[i];
        }
    }

if(isAscending){
    for(int pos=1;maxVal/pos>0;pos*=10){
        countsortAscending(arr,n,pos);
    }
}
else{
    for(int pos=1;maxVal/pos>0;pos*=10){
        countsortDescending(arr,n,pos);
    }
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
    cout<<"Enter elements of array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"\nArray Before Sorting: "<<endl;
    display(arr,n);

    radixsort(arr,n,true);
    cout<<"\nArray After Sorting(Ascending): "<<endl;
    display(arr,n);

    radixsort(arr,n,false);
    cout<<"\nArray After Sorting(Descending): "<<endl;
    display(arr,n);

    delete[] arr;

return 0;
}