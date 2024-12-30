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

    //insertion without recursion
void insert(int key){
    node* n=new node(key);
    n->right=NULL;
    n->left=NULL;

    if(root==NULL){
        root=n;
        return;
    }
    else{
       node* ptr=root;
       node* follower;

       while(ptr!=NULL){
        follower=ptr;
        if(ptr->key>key){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
       }

       if(follower->key>key){
        follower->left=n;
       }
       else{
        follower->right=n;
       }
    }
}

void display(node* root){//inorder
   if (root == NULL) return;//avoids segmentation faults
    display(root->left);
    cout<<root->key<<" ";
    display(root->right);
}

//finding max height/finding height of bst
int maxHeight(node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int leftHeight,rightHeight;

        leftHeight=maxHeight(root->left);
        rightHeight=maxHeight(root->right);

        return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
        //adding one to include current node too
        //return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
    }
}

int minHeight(node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int leftHeight,rightHeight;

        leftHeight=minHeight(root->left);
        rightHeight=minHeight(root->right);

        //return leftHeight>rightHeight?rightHeight+1:leftHeight+1;
        //adding one to include current node too
        return 1+ (leftHeight>rightHeight?rightHeight:leftHeight);
    }
}
};

int main(){
    bst t;
    t.insert(40);
     t.insert(4);
      t.insert(46);
       t.insert(76);
        t.insert(30);
         t.insert(10);

         t.display(t.root);

         cout<<"\nMax Height: "<<t.maxHeight(t.root)<<endl;
         cout<<"\nMin Height: "<<t.minHeight(t.root)<<endl;
         
}