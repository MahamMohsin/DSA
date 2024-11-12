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

    void RecursiveInsert(node* root,int key,int level){
        if(key<root->key){
            if(root->left==NULL){
                root->left=new node(key);
                cout<<"Inserted "<<key<<" at level "<<level+1<<" as left child of "<<root->key<<endl; 
            }
        else{
            RecursiveInsert(root->left,key,level+1);
        }
        }

        else{
            if(root->right==NULL){
                root->right=new node(key);
                cout<<"Inserted "<<key<<" at level "<<level+1<<" as right child of "<<root->key<<endl;
            }
            else{
                RecursiveInsert(root->right,key,level+1);
            }
        }
    }

   bool RecursiveSearch(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true;
    }
    return key<root->key?RecursiveSearch(root->left,key):RecursiveSearch(root->right, key);
    }

    void insert(int key){
        if(root==NULL){
            root=new node(key);
            cout<<"Inserted "<<key<<" as root"<<endl;
        }
        else{
            RecursiveInsert(root,key,1);
        }
    }

    void searching(int key){
        if(RecursiveSearch(root,key)){
            cout<<key<<" found in tree!"<<endl;
        }
        else{
            cout<<key<<" not found!"<<endl;
            cout<<"Inserting..."<<endl;
            insert(key);
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
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);
    tree.insert(8);

    cout<<"\nDisplaying tree Inorder: "<<endl;
    tree.display();

    int search;
    cout<<"\nEnter a value to search: ";
    cin>>search;

    tree.searching(search);

return 0;
}