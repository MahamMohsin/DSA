#include <iostream>
using namespace std;

class stack{
    int size;
    char* arr;
    int top;

public:
    stack(int s){
        size=s;
        arr=new char[size];
        top=-1;
    }

    bool isfull(){
        if(top==size-1){
            return true;
        }
        return false;
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    void push(char value){
        if(isfull()){
            cout<<"No more space in stack!"<<endl;
        }
        else{
            top++;
            arr[top]=value;
        }
    }

    char pop(){
        if(isempty()){
            cout<<"No element in stack to pop!"<<endl;
        }
        return arr[top--];
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }

    bool checkPalindrome(){
        stack tempStack(size);

        for(int i=0;i<=top;i++){
            tempStack.push(arr[i]);
        }

        for(int i=0;i<=top;i++){
            if(arr[i]!=tempStack.pop()){
                return false;
            }
        }
        return true;
    }

    ~stack(){
        delete[] arr;
    }
};

int main(){
    int size;
    char chars;
    cout<<"Enter size of the stack: ";
    cin>>size;

    stack A(size);

    cout<<"Enter elements of the stack: ";
    for(int i=0;i<size;i++){
        cin>>chars;
        A.push(chars);
    }

    cout<<"\nDisplaying the stack: "<<endl;
    A.display();

    if(A.checkPalindrome()){
        cout<<"\nSTACK IS PALINDROME!"<<endl;
    }
    else{
        cout<<"\nNOT PALINDROME!"<<endl;
    }

return 0;
}
