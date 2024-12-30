#include <iostream>
using namespace std;


void func(int arrM[],int arrN[],int n,int m){
    int size=m+n;
    int* arrMN=new int[size];

    for(int i=0;i<size;i++){
        arrMN[i]=arrN[i];
    }
    for(int i=0;i<m;i++){
        arrMN[n+i]=arrM[i];
    }

    cout<<"Printing Array\n";
    for(int i=0;i<size;i++){
        cout<<arrMN[i]<<" ";
    }

    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arrMN[j]<arrMN[min]){
                min=j;
            }
        }
        if(i!=min){
            int temp=arrMN[min];
            arrMN[min]=arrMN[i];
            arrMN[i]=temp;
        }
    }

    cout<<"\nPrinting Array after Swapping\n";
    for(int i=0;i<size;i++){
        cout<<arrMN[i]<<" ";
    }
}


int main(){
   
    int arrM[]={1,2,3,4};
    int arrN[]={10,9,8,7};

    int n=sizeof(arrN)/sizeof(arrN[0]);
    int m=sizeof(arrM)/sizeof(arrM[0]);

    func(arrM,arrN,m,n);
}