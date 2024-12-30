#include <iostream>
using namespace std;

int main(){
    //declaring a integer variable
    int a=10;
    //declaring a ptr and storing a into ptr
    int *ptr=&a;

    cout<<"The value of a is: "<<*ptr<<endl;
    cout<<"The value of a is: "<<a<<endl;

    cout<<"The address of a is: "<<&a<<endl;
    cout<<"The address of a is: "<<ptr<<endl<<endl;

    //we can use new keyword in c++ to directly do the above steps
    int* p=new int(5);//here a ptr with integer value 5 assigned

    cout<<"The value of int is: "<<*p<<endl;
    cout<<"The address of int is: "<<p<<endl<<endl;

    char c;
    cout<<"Enter any character: ";
    cin>>c;
    char* ptr2=new char(c);//memory allocated for c 

    cout<<"Printing character: "<<*ptr2<<endl;
    cout<<"Printing character: "<<c<<endl;
}