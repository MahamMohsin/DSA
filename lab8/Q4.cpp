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
    int level=1;
    bool child=0;//used for telling left or right child

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

    void insert(int key){
        root=insert(root,key);
    }

    bool search(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true;
    }
    level++;
    if(key>root->key){
        child=false;
        return search(root->right,key);
    }
    else{
        child=true;
        return search(root->left,key);
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
    bst tree;
    int value=0;
    int choice;

    tree.insert(10);
    tree.insert(5);
    tree.insert(11);
    tree.insert(4);
    tree.insert(7);
    tree.insert(8);

    cout<<"\nDisplaying Tree Inorder: "<<endl;
    tree.display();

    cout<<"\nEnter the value to search: ";
    cin>>value;

    cout<<"\nMake your choice for the value: "<<endl;
    cout<<"1.Ceil\n2.Floor"<<endl;
    cin>>choice;

    switch(choice){
        case 1: 
        value=value+1;//ceil
        if(tree.search(tree.root,value)){
            cout<<value<<" is at level: "<<tree.level<<endl;
            if(tree.child){
                cout<<"left child"<<endl;
            }
            else{
                cout<<"right child"<<endl;
            }
        }
        else{
            cout<<"Value not found!"<<endl;
        }
        break;

        case 2:
        value=value-1;//floor
        if(tree.search(tree.root,value)){
            cout<<value<<" is at level: "<<tree.level<<endl;
            if(tree.child){
                cout<<"left child"<<endl;
            }
            else{
                cout<<"right child"<<endl;
            }
        }
        else{
            cout<<"Value not found!"<<endl;
        }
        break;

        default:break;
    }

return 0;
}