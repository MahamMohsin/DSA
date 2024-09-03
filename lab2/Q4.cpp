#include <iostream>
using namespace std;

int main(){
    float** gpa=new float*[4];

    gpa[0]=new float[3];//SE
    gpa[1]=new float[4];//AI
    gpa[2]=new float[2];//CS
    gpa[3]=new float[1];//DS

    cout<<"Enter GPAs for 3 courses of SE: "<<endl;
    for(int i=0;i<3;i++){
        cin>>gpa[0][i];
    }

    cout<<"Enter GPAs for 4 courses of AI: "<<endl;
    for(int j=0;j<4;j++){
        cin>>gpa[1][j];
    }

    cout<<"Enter GPAs for 2 courses of CS: "<<endl;
    for(int k=0;k<2;k++){
        cin>>gpa[2][k];
    }

    cout<<"Enter GPA for the course of DS: "<<endl;
    cin>>gpa[3][0];

    cout<<"\nDISPLAYING GPAs"<<endl;

    cout<<"GPAs for SE courses: "<<endl;
    for(int i=0;i<3;i++){
        cout<<gpa[0][i]<<" ";
    }
    cout<<endl;

    cout<<"GPAs for AI courses: "<<endl;
    for(int j=0;j<4;j++){
        cout<<gpa[1][j]<<" ";
    }
    cout<<endl;

    cout<<"GPAs for CS courses: "<<endl;
    for(int k=0;k<2;k++){
        cout<<gpa[2][k]<<" ";
    }
    cout<<endl;

    cout<<"GPA for DS course: "<<endl;
    cout<<gpa[3][0];

return 0;
}