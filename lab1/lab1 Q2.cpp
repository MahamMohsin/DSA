#include <iostream>
using namespace std;

class Exam{
    string studentname;
    string examdate;
    int *score;

public:
Exam(string n,string d,int s):studentname(n),examdate(d){
    score=new int(s);
}

~Exam(){
    delete score;
}

void setdetails(string n,string d,int s){
    studentname=n;
    examdate=d;
    *score=s;
}

void display(){
    cout<<"Student Name: "<<studentname<<endl;
    cout<<"Exam Date: "<<examdate<<endl;
    cout<<"Score: "<<*score<<endl;
}
};

int main(){
    Exam e1("Amna","21-8-24",87);
    Exam e2=e1;

    cout<<"Exam 1 details: "<<endl;
    e1.display();
    cout<<"Exam 2 details: "<<endl;
    e2.display();

    //checking for problem in shallow copy
    e1.setdetails("Haider","19-7-24",80);

    cout<<"\nExam 1 details(after modification): "<<endl;
    e1.display();
    cout<<"Exam 2 details(after modification): "<<endl;
    e2.display();

return 0;
}

