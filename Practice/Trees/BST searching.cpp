#include <iostream>
using namespace std;

//in this insertion will be thro recursion

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
            //same as node* n=new node(key);
            //n->left=n->right=NULL;
            //return n;
        }
        else{
            if(root->key>key){
                root->left=insert(root->left,key);
            }
            else{
                root->right=insert(root->right,key);
            }
        }
        return root;
    }

    //without recursion
    node* search(node* root,int key){
        while(root!=NULL){
            if(root->key==key){
                return root;
            }
            else{
                if(root->key>key){
                    root=root->left;
                    //return search(root->left,key); for rec
                }
                else{
                    root=root->right;
                    //return search(root->right,key);
                }
            }
        }
         return NULL;//if not found
    }

    void display(node* root){//pre order display
        if(root!=NULL){
            cout<<root->key<<" ";
            display(root->left);
            display(root->right);
        }
    }

};

int main(){
    bst t;

//we'll keep updating root
    t.root=t.insert(t.root,20);
    t.root=t.insert(t.root,21);
    t.root=t.insert(t.root,14);

    t.display(t.root);//pre: 20 14 21 //Inor:14 20 21 //post:14 21 20

    cout<<endl;
    int search=14;

    node* result=t.search(t.root,search);

    if(result!=NULL){
        cout<<"Node found!"<<endl;
    }
    else{
        cout<<"Not found!"<<endl;
    }
}