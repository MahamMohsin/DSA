#include <iostream>
using namespace std;

//supposing values based on priority
// 1. CEO (Chief Executive Officer) - Highest Priority
// 2. CTO (Chief Technology Officer)
// 3. CFO (Chief Financial Officer)
// 4. VP (Vice President)
// 5. MGR (Manager)
// 6. EMP (Employee)

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];

        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cout<<"CEO (Chief Executive Officer)"<<endl;
        }
        if(arr[i]==2){
            cout<<"CTO (Chief Technology Officer)"<<endl;
        }
        if(arr[i]==3){
            cout<<"CFO (Chief Financial Officer)"<<endl;
        }
        if(arr[i]==4){
            cout<<"VP (Vice President)"<<endl;
        }
        if(arr[i]==5){
            cout<<"MGR (Manager)"<<endl;
        }
        if(arr[i]==6){
            cout<<"EMP (Employee)"<<endl;
        }
    }
}

int main(){
    int positions[]={6,3,5,6,4,2,5,1};
    int n=sizeof(positions)/sizeof(positions[0]);

    cout<<"DISPLAYING INITIAL ARRANGEMENT"<<endl;
    display(positions,n);

    insertionsort(positions,n);
    cout<<"\nDISPLAYNG PRIORITY WISE ARRANGEMENT"<<endl;
    display(positions,n);

return 0;
}