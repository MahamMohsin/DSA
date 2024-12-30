#include<iostream>
#include<string>
using namespace std;

class Stack{
    int top;
    int size;
    char* array;
   
public:
    Stack(int size){
        top=-1;
        size=size;
        array=new char[size];
    }
    ~Stack(){
        delete[] array;
    }
   
    void push(char element){
        if(top==size-1){
            cout<<"Stack Overflow!";
            return;
        }
        array[++top]=element;
    }
    char pop(){
        if(top==-1){
            cout<<"Stack Underflow!";
            return '\0';
        }
        return array[top--];
    }
    bool isEmpty(){
    return (top==-1);
    }
   
    char peek(){
        if(top==-1){
            return '\0';
        }
        return array[top];
    }
};
int precedence(char op){
    if(op=='+'||op=='-'){
        return 1;
    }
    if(op=='*'||op=='/'){
        return 2;
    }
    if(op=='^'){
        return 3;
    }
}
bool isOperator(char c){
return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
string infixToPostFix(const string& infix){
    Stack stack(infix.length());
    string postfix;
    for(int i=0;i<infix.length();i++){
        char c=infix[i];
       
        if(isalnum(c)){
            postfix+=c;
        }
        else if(c=='('){
            stack.push(c);
        }
        else if(c==')'){
            while(!stack.isEmpty()&&stack.peek()!='('){
                postfix+=stack.pop();
            }
            stack.pop();
        }
        else if(isOperator(c)){
    while(!stack.isEmpty()&&precedence(stack.peek())>=precedence(c)){
        postfix+=stack.pop();
    }
    stack.push(c);    
        }
        }
    while(!stack.isEmpty()){
        postfix+=stack.pop();
    }
        return postfix;
    }



int main(){
string infix="A+B*(C^D-E)";
cout<<"Infix Expression: "<<infix<<"\n";
cout<<"Postfix Expression: "<<infixToPostFix(infix);

return 0;
}