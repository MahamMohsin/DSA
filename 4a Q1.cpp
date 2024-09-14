#include <iostream>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool isSwapped=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;

                isSwapped=1;
            }
        }
        if(isSwapped==0){break;}
    }
}

void display(int arr[],int n){
    cout<<"\nPRINTING ARRAY IN DESCENDING ORDER\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter number of elements to insert in array: ";
    cin>>n;

    int array[n];
    cout<<"\nEnter array elements: ";
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    cout<<"\nPRINTING ORIGINAL ARRAY\n";
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }

    bubblesort(array,n);
    display(array,n);

return 0;
}