#include <iostream>
using namespace std;

//3 cases of deletion
//leaf node
//mid node
//root node

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

    //recursive insertion
    node* insert(node* root,int key){
        if(root==NULL){
            return new node(key);
        }

        else{
            if(key>root->key){
                root->right=insert(root->right,key);
            }
            else{
                root->left=insert(root->left,key);
            }
        }

        return root;
    }

//smallest in the right subtree
    node* InorderSuccessor(node* root){
        while(root!=NULL && root->left!=NULL){
            root=root->left;
        }
        return root;
    }

    //recursive deletion
    node* deletion(node* root,int key){
        if(root==NULL){
            return NULL;
        }

        //traversing the node for deletion thro its ancestors
        if(key<root->key){
            root->left=deletion(root->left,key);
        }
        else if(key>root->key){
            root->right=deletion(root->right,key);
        }
        else{
            //finding of leaf node or with one child
            if(root->right==NULL){
                node* temp=root->left;//storing its left val to be used later
                delete root;
                return temp;//retrieving node val
            }
            else if(root->left==NULL){
                node* temp=root->right;
                delete root;
                return temp;//for insertion at apt place
            }
        

        //for nodes with 2 children
        //successor is leftmost val in right tree
        node* temp=InorderSuccessor(root->right);
        root->key=temp->key;//getting content in the root
        root->right=deletion(root->right,temp->key);//delt inorder successor
        }

        return root;//return updated root
    }

    void insert(int key){
        root=insert(root,key);
    }

    void deletion(int key){
        root=deletion(root,key);
    }

    void display(node* root){
        if(root==NULL){return;}
        display(root->left);
        cout<<root->key<<" ";
        display(root->right);
    }
};

int main(){
    bst t;

    t.insert(50);
    t.insert(30);
    t.insert(20);
    t.insert(40);
    t.insert(70);
    t.insert(60);
    t.insert(80);

    cout << "Inorder traversal before deletion: "<<endl;
    t.display(t.root);

    t.deletion(20);
    cout << "\nInorder traversal after deleting 20: "<<endl;
    t.display(t.root);

    t.deletion(30);
    cout << "\nInorder traversal after deleting 30: "<<endl;
    t.display(t.root);

    t.deletion(50);
    cout << "\nInorder traversal after deleting 50: "<<endl;
    t.display(t.root);

   
}