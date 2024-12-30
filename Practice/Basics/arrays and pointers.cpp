#include <iostream>
using namespace std;

int main(){
    int* arr=new int[3];//declaring an array with cap of 3 integers

   cout<<"enter values for array: ";
   for(int i=0;i<3;i++){
    cin>>arr[i];
   }

   cout<<"Printing Array values: ";
   for(int i=0;i<3;i++){
    cout<<arr[i]<<" ";
   }

   //reallocating more space
   int size;
   cout<<"\nEnter size to reallocate: ";
   cin>>size;
   int* newarr=new int[size];

   //bringing old array values into new one
   for(int i=0;i<size;i++){
    newarr[i]=arr[i];
    }

   //now for adding new values into the array
   cout<<"Enter more elements: ";
   for(int i=3;i<size;i++){
    cin>>newarr[i];
   }

   //printing reallocated array
   cout<<"Reallocated Array: ";
   for(int i=0;i<size;i++){
    cout<<*(newarr+i);//displaying array using deref pointers
   }

   //now we delete the prev array in order to avoid memory leaks
   delete[] arr;

}
