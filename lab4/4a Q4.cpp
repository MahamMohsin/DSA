#include <iostream>
using namespace std;

void shellsort(float weights[],int n){
    for(int gap=n/4;gap>0;gap/=4){
        for(int i=gap;i<n;i++){
            float temp=weights[i];

            int j;
            for(j=i;j>=gap&&weights[j-gap]>temp;j-=gap){
                weights[j]=weights[j-gap];
            }
            weights[j]=temp;
        }
    }
}

void display(float weights[],int n){
    for(int i=0;i<n;i++){
        cout<<weights[i]<<" ";
    }
    cout<<endl;
}

int main(){
    float weights[]={75.5,65,90,63.5,78.5,80};
    int n=sizeof(weights)/sizeof(weights[0]);

    cout<<"WEIGHTS BEFORE SORTING\n";
    display(weights,n);

    shellsort(weights,n);
    cout<<"\nAFTER SORTING\n";
    display(weights,n);

return 0;    
}