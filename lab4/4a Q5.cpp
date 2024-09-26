#include <iostream>
using namespace std;

void combsort(float prices[],int n){
    float shrinkfactor=1.25;
    int gap=n;
    bool swapped=true;

    while(gap>1 || swapped){
        gap=(int)(gap/shrinkfactor);
        if(gap<1){
            gap=1;
        }
        swapped=false;

        for(int i=0;i+gap<n;i++){
            if(prices[i]>prices[i+gap]){
                float temp=prices[i];
                prices[i]=prices[i+gap];
                prices[i+gap]=temp;
                swapped=true;
            }
        }
    }
}

void display(float prices[],int n){
    for(int i=0;i<n;i++){
        cout<<"$"<<prices[i]<<" ";
    }
    cout<<endl;
}

int main(){
    float prices[]={30.65, 29.95, 200.99, 99.99, 16.50, 35.50};

    int n=sizeof(prices)/sizeof(prices[0]);

    cout<<"PRODUCT PRICES BEFORE SORTING\n";
    display(prices,n);

    combsort(prices,n);
    cout<<"\nPRODUCT PRICES AFTER SORTING\n";
    display(prices,n);
    
return 0;
}