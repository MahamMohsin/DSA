#include <iostream>
#include <cstring>
using namespace std;
/*
 * Program: Book Collection Sorting
 
 * Description:
 * This C++ program stores and sorts a student's collection of book titles using Shell sort.
 * The user inputs the number of books and each title. Titles are stored in a dynamic array 
 * and sorted in ascending order.
 * 
 * FOLLOW RULE OF 3
 */

class booksorting{
    string* arr;//for books
    int n;//size
    public:
    booksorting(int size){
        n=size;
        arr=new string[n];
    }

    void shellsort(){
        for(int gap=n/2;gap>0;gap/=2){
            for(int j=gap;j<n;j++){
                for(int i=j-gap;i>=0;i-=gap){
                    //i+gap is j jo ke agy hoga
                    if(arr[i+gap]>arr[i]){
                        break;//when arranging in ascending no need of this
                    }
                    else{//if j wala chota then swap
                        string temp=arr[i+gap];
                        arr[i+gap]=arr[i];
                        arr[i]=temp;
                    }
                }
            }
        }
    }

//destructor
    ~booksorting(){
        delete[] arr;
    }

//copy constructor
    booksorting(booksorting &bs){
        n=bs.n;
        arr=new string[n];
        for(int i=0;i<n;i++){
            arr[i]=bs.arr[i];
        }
    }

//assignment operator
    booksorting &operator=(booksorting &bs){
        if(this!=&bs){
           delete[] arr;
           n=bs.n;
           arr=new string[n];
           for(int i=0;i<n;i++){
            arr[i]=bs.arr[i];
           }
        }
        return *this;
    }

    void input(){
        cin.ignore();
        for(int i=0;i<n;i++){
        cout<<"Enter name of book"<<i+1<<": ";
        getline(cin,arr[i]);//for efficient insertion of names
    }
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }
};

int main(){
    int size;
    cout<<"Enter number of books you want to add: ";
    cin>>size;

    booksorting b(size);
    
    b.input();

    cout<<"\nBooks before sorting: "<<endl;
    b.display();

    b.shellsort();
    cout<<"\n\nBooks after sorting: "<<endl;
    b.display();

}