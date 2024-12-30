#include <iostream>
using namespace std;

void insertion(int arr[],int n){
    int i=n;//assigning the index of newly inserted element
    int temp;
    temp=arr[i];//value of new insert stored at temp

    //comparisons done until we reach the first element of array and the value at temp is greater than its parents
    //cause max heap warna condition changed
    while(i>1 && temp>arr[i/2]){
        arr[i]=arr[i/2];//if value at parent smaller than i mein parent dedo like make bigger value i

        i=i/2;//keep halfing i to check parents
    }
    arr[i]=temp;//i would have reached the pos of insertion 
}

//deletion done from root
int deletion(int arr[],int n){
    int x,i,j;

    x=arr[1];//storing root element to be deleted
    arr[1]=arr[n];//replacing last element with root

    i=1;//starting heap from root
    j=2*i;//and on left child

    while(j<n-1){
    //now when last el brought to root do comparisons
        if(arr[j+1]>arr[j]){
            j=j+1;//selection of larger
        }

        if(arr[i]<arr[j]){
    //if j(ahead) found to be greater than i(behind) do swapping
    //i.e heap property violated
        int temporary=arr[i];
        arr[i]=arr[j];
        arr[j]=temporary;

        i=j;//move i ahead for further comparisons
        j=2*j;
        }
        else{
            break;
        }
    }
    return x;//to check value deleted
}

int main(){
    int arr[]={0,10,20,30,25,5,40,35};

    int n=sizeof(arr)/sizeof(arr[0])-1;//minus 1 done to ignore zero

    for(int i=2;i<=n;i++){
        //insertion starts from 2 as first el alr considered to be in heap
        insertion(arr,i);
    }

    cout<<"Heap after insertion: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //deletion done in reverse bec top to bottom approach
    for(int i=n;i>1;i--){
        int deleted=deletion(arr,i);
        //printing each deleted el in sorted order
        //should go from desc to asc
        cout<<"\nDeleted: "<<deleted<<" ";
    }
    cout<<endl;

return 0;
}
