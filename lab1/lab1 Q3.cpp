#include <iostream>
#include <cstring>
using namespace std;

class Document{
char *content;

public:
Document(const char *c){
    content=new char[strlen(c)+1];
    strcpy(content,c);
}

~Document(){
    delete[] content;
}

Document(Document &d){
    content=new char[strlen(d.content)+1];
    strcpy(content,d.content);
}

Document& operator=(Document &d){
if(this!=&d){
delete[] content;
content=new char[strlen(d.content)+1];
strcpy(content,d.content);
}
return *this;
}

void setcontent(const char* cont){
    content=new char[strlen(cont)+1];
    strcpy(content,cont);
}

void print(){
    cout<<"Document content: "<<content;
}
};

int main(){
    Document d1("Work Hard");
    cout<<"Document 1: "<<endl;
    d1.print();

    Document d2(d1);
    cout<<"\nDocument 2: "<<endl;
    d2.print();

    Document d3("Dream Big");
    d3=d1;

    cout<<"\nDocument 3: "<<endl;
    d3.print();

    d1.setcontent("Stay Focused");

    cout<<"\n\nDocument 1(After modification): "<<endl;
    d1.print();
    cout<<"\nDocument 2(After modification): "<<endl;
    d2.print();
    cout<<"\nDocument 3(After modification): "<<endl;
    d3.print();

return 0;
}