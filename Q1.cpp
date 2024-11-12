#include <iostream>
using namespace std;

class node{
public:
int key;
node* left;
node* right;

node(int k){
    key=k;
    this->left=NULL;
    this->right=NULL;
}
};

class bst{
    public:
    node* root=NULL;

    node* insert(node* root,int key){
        if(root==NULL){
            return new node(key);
        }

        if(key>root->key){
            root->right=insert(root->right,key);
        }
        else if(key<root->key){
            root->left=insert(root->left,key);
        }
        return root;
    }

    void arrToBst(int arr[],int size){
        for(int i=0;i<size;i++){
            root=insert(root,arr[i]);
        }
    }

    void display(node* root){//inorder
        if(root==NULL){
            return;
        }
        display(root->left);
        cout<<root->key<<" ";
        display(root->right);
    }

    void display(){
        display(root);
    }
};

int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);

    bst tree;
    tree.arrToBst(arr,size);

    cout<<"Displaying Binary Tree: "<<endl;
    tree.display();

return 0;
}