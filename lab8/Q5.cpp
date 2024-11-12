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

        if(key<root->key){
            root->left=insert(root->left,key);
        }
        else{
            root->right=insert(root->right,key);
        }
        return root;
    }

    void insert(int key){
        root=insert(root,key);
    }

    void merge(node* root2){
        if(root2==NULL){
            return;
        }

        merge(root2->left);
        merge(root2->right);
        insert(root2->key);
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
    bst tree1,tree2;

    tree1.insert(5);
    tree1.insert(3);
    tree1.insert(6);
    tree1.insert(2);
    tree1.insert(4);
    cout<<"Inorder display of BST 1: "<<endl;
    tree1.display();
    cout<<endl;

    tree2.insert(2);
    tree2.insert(1);
    tree2.insert(3);
    tree2.insert(7);
    tree2.insert(6);
    cout<<"Inorder display of BST 2: "<<endl;
    tree2.display();
    cout<<endl;

    tree1.merge(tree2.root);
    cout<<"BST AFTER MERGING: "<<endl;
    tree1.display();

return 0;
}