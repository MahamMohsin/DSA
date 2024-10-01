#include <iostream>
using namespace std;

int recurrsiveArraySum(int* arr[],int sizes[],int dim){
    if(dim==0){        
    int sum=0; 
    for(int i=0;i<sizes[dim];i++){
        sum+=arr[0][i];
    }
    return sum;
}
     int sum=0;
     for(int i=0;i<sizes[dim];i++){
        sum+=recurrsiveArraySum(arr+i,sizes,dim-1);
     }
     return sum;
}

int main(){
    int** arr=new int* [4];

    arr[0]=new int[4]{1,2,3,4};
    arr[1]=new int[4]{5,6,7,8};
    arr[2]=new int[4]{9,10,11,12};
    arr[3]=new int[4]{13,14,15,16};

    int sizes[]={4,4};//size of both row and columns in jagged array

    int sum=recurrsiveArraySum(arr,sizes,1);
    cout<<"The sum of the multi-dimensional array: "<<sum;

    for(int i=0;i<4;i++){
        delete arr[i];
    }
    delete[] arr;

return 0;
}