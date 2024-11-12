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
        height=1;
        this->left=NULL;
        this->right=NULL;
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

        root->height=getHeight(root);
        return balance(root);
    }

    int getHeight(node* ptr){
        if(ptr==NULL){
            return 0;
        }
       int rightHeight,leftHeight;

       rightHeight=ptr && ptr->right?ptr->right->height:0;
       leftHeight=ptr && ptr->left?ptr->left->height:0;

       return rightHeight>leftHeight?rightHeight+1:leftHeight+1;
    }

    int balancefactor(node* ptr){
        if(ptr==NULL){
            return 0;
        }
        int rightHeight,leftHeight;

        leftHeight=ptr && ptr->left?ptr->left->height:0;
        rightHeight=ptr && ptr->right?ptr->right->height:0;

        return leftHeight-rightHeight;
    }

    node* balance(node* root){
        if (balancefactor(root) == 2 && balancefactor(root->left) >= 0) return LLrotation(root);
        if (balancefactor(root) == 2 && balancefactor(root->left) < 0) return LRrotation(root);
        if (balancefactor(root) == -2 && balancefactor(root->right) <= 0) return RRrotation(root);
        if (balancefactor(root) == -2 && balancefactor(root->right) > 0) return RLrotation(root);
        return root;
    }

    node* LLrotation(node* ptr){
        node* pl=ptr->left;
        node* plr=pl->right;

        pl->right=ptr;
        ptr->left=plr;

        ptr->height=getHeight(ptr);
        pl->height=getHeight(pl);

        if(root==ptr){
            root=pl;
        }

        return pl;
    }

    node* RRrotation(node* ptr){
        node* pr=ptr->right;
        node* prl=pr->left;

        pr->left=ptr;
        ptr->right=prl;

        ptr->height=getHeight(ptr);
        pr->height=getHeight(pr);

        if(ptr==root){
            root=pr;
        }
        return pr;
    }

    node* LRrotation(node* ptr){
        ptr->left=RRrotation(ptr->left);
        return LLrotation(ptr);
    }

    node* RLrotation(node* ptr){
        ptr->right=LLrotation(ptr->right);
        return RRrotation(ptr);
    }

    //inorder traversal to find kthsmallest
    void Kthsmallest(node* root,int& k,int& value){
        if(root==NULL){
            return;
        }

        Kthsmallest(root->left,k,value);
        if(--k==0){
            value=root->key;
            return;
        }
        Kthsmallest(root->right,k,value);
    }

    //inorder traversal in reverse to find kthlargest
    void Kthlargest(node* root,int& k,int& value){
        if(root==NULL){
            return;
        }

        Kthlargest(root->right,k,value);
        if(--k==0){
            value=root->key;
            return;
        }
        Kthlargest(root->left,k,value);
    }

    void subtreeHeight(){
        int leftHeight=root->left?root->left->height:0;
        int rightHeight=root->right?root->right->height:0;
        cout<<"Left Height from Root: "<<leftHeight<<endl;
        cout<<"Right Height from Root: "<<rightHeight<<endl;
    }

    void display(node* root){
        if(root==NULL){
            return;
        }
        display(root->left);
        cout<<root->key<<" ";
        display(root->right);
    }

    void insert(int key){
        root=insert(root,key);
    }

    void display(){
        display(root);
    }
};

int main(){
    avl tree;
    int KthSmallestVal=-1;
    int KthLargestVal=-1;
    int k;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);

    cout<<"Displaying AVL tree: "<<endl;
    tree.display();
    cout<<endl;

    cout<<"Enter value for k: ";
    cin>>k;

    int Kth=k;//to store k value
    int ktemp=k;

    tree.Kthlargest(tree.root,ktemp,KthLargestVal);
    if(KthLargestVal!=-1){
        cout<<"The "<<Kth<<"-th largest value is: "<<KthLargestVal<<endl;
    }
    else{
        cout<<Kth<<"-th largest value doesn't exist!"<<endl;
    }

    ktemp=k;
    tree.Kthsmallest(tree.root,ktemp,KthSmallestVal);
    if(KthSmallestVal!=-1){
        cout<<"The "<<Kth<<"-th smallest value is: "<<KthSmallestVal<<endl;
    }
    else{
        cout<<Kth<<"-th smallest value doesnt exist!"<<endl;
    }

    cout<<"\nDisplaying subtree heights: "<<endl;
    tree.subtreeHeight();

return 0;
}