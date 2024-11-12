#include <iostream>
#include <queue> 
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

    void insertByLevels(int key){
        if(root==NULL){
            root=new node(key);
            return;
        }

        queue<node*>q;
        q.push(root);

        while(!q.empty()){
            node* ptr=q.front();
            q.pop();

            if(ptr->left==NULL){
                ptr->left=new node(key);
                return;
            }
            else{
                q.push(ptr->left);
            }

            if(ptr->right==NULL){
                ptr->right=new node(key);
                return;
            }
            else{
                q.push(ptr->right);
            }
        }
    }

    

    void arrToBst(int arr[],int size){
        for(int i=0;i<size;i++){
            insertByLevels(arr[i]);
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

    bool completeTree(){
        if(root==NULL){
            return false;
        }
        queue<node*>q;
        q.push(root);

        bool leaf=false;//indicates all subsequent nodes are leaf nodes
        while(!q.empty()){
            node* ptr=q.front();
            q.pop();

            if(ptr->left!=NULL){
                if(leaf==true){
                    delete ptr;
                    return false;
                }
                q.push(ptr->left);
            }
            else{
                leaf=true;
            }

            if(ptr->right!=NULL){
                if(leaf==true){
                    delete ptr;
                    return false;
                }
                q.push(ptr->right);
            }
            else{
                leaf=true;
            }
        }
        return true;
    }

};

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);

    bst tree;
    tree.arrToBst(arr,size);

    cout<<"Displaying Binary Tree: "<<endl;
    tree.display();

    if(tree.completeTree()){
        cout<<"\nTree is Complete Binary Tree!"<<endl;
    }
    else{
        cout<<"\nNot Complete Binary Tree!"<<endl;
    }

return 0;
}
