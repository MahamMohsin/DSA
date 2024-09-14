#include <iostream>
using namespace std;

class dates{
public:
int day,month,year;

void input(dates arr[],int n){
    cout<<"Enter the dates in format dd/mm/yyyy:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].day>>arr[i].month>>arr[i].year;
        }
    }

void display(dates arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i].day<10)cout<<"0"<<arr[i].day;
        else cout<<arr[i].day;

        if(arr[i].month<10)cout<<"/0"<<arr[i].month;
        else cout<<"/"<<arr[i].month;

        cout<<"/"<<arr[i].year<<endl;
    }
}

void selectionsort(dates arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j].year<arr[min].year){
            min=j;
        }
    }
    if(i!=min){
        int tempyear=arr[i].year;
        arr[i].year=arr[min].year;
        arr[min].year=tempyear;

        int tempmonth=arr[i].month;
        arr[i].month=arr[min].month;
        arr[min].month=tempmonth;

        int tempday=arr[i].day;
        arr[i].day=arr[min].day;
        arr[min].day=tempday;
    }
    }
}
};

int main(){
    int n;
    cout<<"Enter number of dates to insert: ";
    cin>>n;

    dates arr[n];
    dates d;

    d.input(arr,n);
    cout<<"\nDISPLAYING DATES BEFORE SORTING"<<endl;
    d.display(arr,n);

    d.selectionsort(arr,n);
    cout<<"\nDISPLAYING AFTER SORTING"<<endl;
    d.display(arr,n);

return 0;
}