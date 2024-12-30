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

class BST{
    public:
    node* root=NULL;

    void insert(int key){
        node* n=new node(key);
        n->left=NULL;
        n->right=NULL;
        if(root==NULL){
            root=n;
            return;//we basically add this to ensure that a first root node is inserted and further insertions can be made
        }

//else condition
        node* ptr=root;//for iterations
        node* follower;//follower for insertion

        while(ptr!=NULL){
            follower=ptr;  //continue following
            //means we gotta check right
            if(key>ptr->key){
                ptr=ptr->right;
            }
            //else iterate left as apki key choti and jispe ptr wo bigger value
            else{
                ptr=ptr->left;
            }
        }

        //now we'll leave the loop after getting required pos of insertion
        //we will check if jispr follower akr stop hoa uspr key ki kia value so we can insert accordingly

        if(key>follower->key){
            follower->right=n;//node inserted at right of follower if bigger value
        }
        else{
            follower->left=n;//if smaller than on left
        }
    }

   void displayInorder(node* root){

        if(root!=NULL){
            displayInorder(root->left);
            cout<<root->key<<" ";//printing basically yeh krega
            displayInorder(root->right);
        }
    }

    void displayInorder(){
        displayInorder(root);
    }
};

int main(){
    BST tree;
    tree.insert(17);
    tree.insert(30);
    tree.insert(60);
    tree.insert(55);

    tree.displayInorder();
}