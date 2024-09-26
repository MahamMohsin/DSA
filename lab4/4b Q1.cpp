#include <iostream>
using namespace std;

int binarysearch(int empIDs[],int n,int rollno){
    int left=0;
    int right=n-1;

    while(left<=right){
        int mid=(left+right)/2;

        if(empIDs[mid]==rollno){
            return mid;
        }
        else if(empIDs[mid]>rollno){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
        //incase employee ID didnt matched we take left's value to insert at appropriate pos
        for(int i=n;i>left;i--){
            empIDs[i]=empIDs[i-1];
        }
        empIDs[left]=rollno;
        n++;
        return left;
    
}

void display(int empIDs[],int n){
    for(int i=0;i<n;i++){
        cout<<empIDs[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int numofEmployees;

    cout<<"Enter number of Employees: ";
    cin>>numofEmployees;

    int empIDs[numofEmployees+1];
    cout<<"Enter the IDs of of employees: "<<endl;
    for(int i=0;i<numofEmployees;i++){
        cin>>empIDs[i];
    }

    cout<<"DISPLAYING ARRAY OF EMPLOYEE IDs"<<endl;
    display(empIDs,numofEmployees);

    int position=binarysearch(empIDs,numofEmployees,94);//23K-0594

    cout<<"EMPLOYEE ID MATCHED (0R) INSERTED AT POSITION: "<<position<<endl<<endl;

    cout<<"PRINTING (IF) INSERTION DONE"<<endl;
    display(empIDs,numofEmployees+1);

return 0;
}