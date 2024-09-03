#include <iostream>
using namespace std;

int main(){

    int** jaggedArr=new int*[5];
    int size[5];

    for(int i=0,c=0;i<5;i++){
        cout<<"Enter size of Row "<<i+1<<": ";
        cin>>size[i];

        jaggedArr[i]=new int[size[i]];

    for(int j=0;j<size[i];j++){
        jaggedArr[i][j]=c++;
}
}

cout<<"\nPrinting Before Resizing"<<endl;
for(int i=0;i<5;i++){
    cout<<"Row "<<i+1<<": ";
for(int j=0;j<size[i];j++){
    cout<<jaggedArr[i][j]<<" ";
}
cout<<endl;
}

//now resizing
for(int i=0;i<5;i++){
    int* newrow=new int[10];

for(int j=0;j<size[i];j++){
    newrow[j]=jaggedArr[i][j];
}
for(int j=size[i];j<10;j++){
    newrow[j]=0;//assigning zero to rest indexes
}

delete jaggedArr[i];
jaggedArr[i] = newrow;
}

cout<<"\nPrinting After Resizing"<<endl;
for(int i=0;i<5;i++){
    cout<<"Row "<<i+1<<": ";
for(int j=0;j<10;j++){
        cout<<jaggedArr[i][j]<<" ";
    }
    cout<<endl;
}

for(int i=0;i<5;i++){
    delete[] jaggedArr[i];
}
    delete[] jaggedArr;

return 0;
}