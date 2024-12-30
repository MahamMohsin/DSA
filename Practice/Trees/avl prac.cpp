#include <iostream>
using namespace std;

class node{
    public:
    int key;
    int height;
    node* left;
    node* right;

    node(int k){
        key=k;
        left=right=NULL;
        height=1;
    }
};

class avl{
public:
node* root=NULL;

node* insert(node* root,int key){
    if(root==NULL){
        return new node(key);
    }

    if(root->key>key){
        root->left=insert(root->left,key);
    }
    else if(root->key<key){
        root->right=insert(root->right,key);
    }

    root->height=nodeHeight(root);
    return balance(root);
}

int nodeHeight(node* ptr){
    int hl,hr;

    hl=ptr && ptr->left?ptr->left->height:0;
    hr=ptr && ptr->right? ptr->right->height:0;

    return 1+max(hr,hl);
}

node* balance(node* root){

}

node* remove(node* root,int key){
    if(root==NULL)return NULL;

    if(root->key>key){
        root->left=remove(root->left,key);
    }

    if(root->key<key){
        root->right=remove(root->right,key);
    }

    if(root->left==NULL){
        node* temp=root->right;
        delete root;
        root=temp;
    }
    if(root->right==NULL){
        node* temp=root->left;
        delete root;
        root=temp;
    }

    node* temp=inorderS(root->right);
    root->key=temp->key;
    root->right=remove(root->right,temp->key);

    root->height=nodeHeight(root);
    return balance(root);

}

node* inorderS(node* root){
    if(root!=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}
};