#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data=d;
        this->next=NULL;
    }
};

class linkedlist{
    public:
    node* head=NULL;

    void insertAttail(int d){
        node* n=new node(d);

        if(head==NULL){
            head=n;
            n->next=NULL;
        }
        else{
            node* ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n;
            n->next=NULL;
        }
}

void displaylist(){
    node* ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}

void copyinglist(int arr[],int n){
    node* ptr=head;
    for(int i=0;i<n && ptr!=NULL;i++){
        arr[i]=ptr->data;
        ptr=ptr->next;
    }
}

void displayarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//index swapping
void selectionsort(int arr[],int n){
    //index last tk
    for(int i=0;i<n-1;i++){
        int min=i;
    //ek agy se compare
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    if(i!=min){
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
}
};

int main(){
    linkedlist l;
    l.insertAttail(2);
    l.insertAttail(4);
    l.insertAttail(3);
    l.insertAttail(1);
    int arr[4];

    l.displaylist();
    l.copyinglist(arr,4);
    cout<<endl;
    l.displayarr(arr,4);
    l.selectionsort(arr,4);
    cout<<endl;
    l.displayarr(arr,4);

}