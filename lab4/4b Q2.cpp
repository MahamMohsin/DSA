#include <iostream>
using namespace std;

int interpolationsearch(float balances[],int n,float target){
    int left=0;//start
    int right=n-1;//end

    while(left<=right && balances[left]<=target && balances[right]>=target){
        
    int pos=left+((target-balances[left])*(right-left))/(balances[right]-balances[left]);

    if(balances[pos]==target){
        return pos;
    }
    if(balances[pos]>target){
        right=pos-1;
    }
    else{
        left=pos+1;
    }
    }
    return -1;
}

bool isuniformlydistributed(float balances[],int n){
   float diff=balances[1]-balances[0];

for(int i=1;i<n-1;i++){
   if(balances[i+1]-balances[i]!=diff){
    return false;
   }
}
   return true;
}

void selectionsort(float balances[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(balances[j]<balances[min]){
                min=j;
            }
        }
        if(i!=min){
            float temp=balances[i];
            balances[i]=balances[min];
            balances[min]=temp;
        }
    }
}

bool issorted(float balances[],int n){
  for(int i=1;i<n;i++){
    if(balances[i]>balances[i-1]){
        return false;
    }
}
    return true;
}

void display(float balances[],int n){
    for(int i=0;i<n;i++){
        cout<<balances[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of account balances: ";
    cin>>n;

    float balances[n];
    cout<<"\nEnter the account balances: "<<endl;
    for(int i=0;i<n;i++){
        cin>>balances[i];
    }

    float target;
    cout<<"\nEnter the target account balance to search: ";
    cin>>target;

    if(!issorted(balances,n)){
        cout<<"Sorting the data..."<<endl;
        selectionsort(balances,n);
    }

    cout<<"\nDISPLAYING AFTER SORTING\n";
    display(balances,n);

    if(!isuniformlydistributed(balances,n)){
        cout<<"Dataset NOT UNIFORMLY DISTRIBUTED target element cant be searched!"<<endl;
        return 1;//exiting code
    }

    int pos=interpolationsearch(balances,n,target);
    if(pos==-1){
        cout<<"\nTarget account balance not found!";
    }
    else{
        cout<<"Target account balance found at index: "<<pos;
    }

return 0;
}