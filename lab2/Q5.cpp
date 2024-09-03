#include <iostream>
using namespace std;

int main(){
    int rows;
    cout<<"Enter the total number of rows in hall: ";
    cin>>rows;

    string** seating=new string*[rows];
    int seatsInrow[rows];

    for(int i=0;i<rows;i++){
        cout<<"Enter the number of seats in Row "<<i+1<<": ";
        cin>>seatsInrow[i];
        seating[i]=new string[seatsInrow[i]];

    for(int j=0;j<seatsInrow[i];j++){
        cout<<"Enter names of attendendees in Row "<<i+1<<": "<<endl;
        cout<<"Attendee on seat "<<j+1<<": ";
        cin>>seating[i][j];
    }    
    }

    cout<<"\nSEATING CHART\n";
    for(int i=0;i<rows;i++){
        cout<<"Row "<<i+1<<": ";
        for(int j=0;j<seatsInrow[i];j++){
        cout<<seating[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<rows;i++){
        delete[] seating[i];
    }
    delete[] seating;

return 0;    
}