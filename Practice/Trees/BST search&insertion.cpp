#include <iostream>
using namespace std;

class node{
    public:
    int key;//same as datain LL
    node* left;//left child
    node* right;//right child

    node(int k){
        key=k;
        this->left=NULL;
        this->right=NULL;
    }
};

class bst{
    public:
    node* root=NULL;
  
void insertion(int key){
    node* current=root;
    node* follower=NULL; //ptr that will folow root for insertion at loc where it will end

//firstly we are checking if the given key exists or not basically searching
    while(current!=NULL){
        follower=current;//for following

        //when key found after traversing
        if(key==current->key){
            return;
        }
        //if current->data is greater than key then we will check left(smaller side)
        else if(key<current->key){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
//now after searching insert if key node not found
        node *n=new node(key);
        
        if(follower==NULL){
            root=n;
            return;
        }
            //we'll check which side's data is bigger and smaller than insert acc
            //follower current pospe hoga
            if(n->key>follower->key){
                follower->right=n;//insert at bigger/right side of follower
            }
            else{
                follower->left=n;//insert at smaller/left of follower
            }
}

//printing recursively using inorder left node right format
void display(node* current){//we'll be sending root in this node* current=root;

if(current!=NULL){
    display(current->left);
    cout<<current->key<<" ";
    display(current->right);
}
}

void display(){
    display(root);
}
};

int main(){
    bst tree;

    tree.insertion(30);
    tree.insertion(4);
    tree.insertion(70);
    tree.insertion(16);

    tree.display();//should display 4,16,30,70

}