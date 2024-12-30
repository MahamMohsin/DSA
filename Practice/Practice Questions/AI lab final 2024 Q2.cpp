//INSERT TRANSACTIONS THEN A RANGE GET SUM OF TRANSACTION WITHIN THAT RANGE
#include <iostream>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int height;
    int key;

    node(int k){
        key=k;
        left=right=NULL;
        height=1;
    }
};

class AVLtransactions{
    public:
    node* root=NULL;

    node* insert(node* root,int key){
        if(root==NULL){
            return new node(key);
        }

        if(root->key<key){
            root->right=insert(root->right,key);
        }

        if(root->key>key){
            root->left=insert(root->left,key);
        }

        //after insertion done update height of node and balance everytime
        root->height=nodeHeight(root);//updating height from root
        return balance(root);//balancing of root done
    }

    int nodeHeight(node* ptr){
        int hl,hr;

        hl=ptr!=NULL && ptr->left?ptr->left->height:0;
        hr=ptr && ptr->right?ptr->right->height:0;

        return max(hr,hl)+1;
    }

    int bf(node* ptr){
        int hl,hr;

        hl=ptr!=NULL && ptr->left?ptr->left->height:0;
        hr=ptr && ptr->right?ptr->right->height:0;

        return hl-hr;//leftsubtree-rightsubtree
    }

    node* balance(node* root){
        if(bf(root)==2 && bf(root->left)>=0)return LLrotation(root);
        if(bf(root)==-2 && bf(root->right)<=0)return RRrotation(root);
        if(bf(root)==2 && bf(root->left)<0)return LRrotation(root);
        if(bf(root)==-2 && bf(root->right)>0)return RLrotation(root);

        return root;
    }

    node* LLrotation(node* ptr){
        node* pl=ptr->left;
        node* plr=pl->right;

        pl->right=ptr;
        ptr->left=plr;

        //update height of both
        pl->height=nodeHeight(pl);
        ptr->height=nodeHeight(ptr);

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

        //updating height
        ptr->height=nodeHeight(ptr);
        pr->height=nodeHeight(pr);

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

    //function to gets range and finds the sum of transactions within that sum
    //range:[L,R]
    int RangeSum(node* root,int L,int R){
        if(root==NULL)return 0;
        int sum=0;//initially sum zero

        if(root->key>=L && root->key<=R){
            sum+=root->key;
        }

        //else we will search for our key get sum
        if(L<root->key){
        //if root->key more than left range means L is small so we check left side of tree
        sum+=RangeSum(root->left,L,R);
        }
        
        if(R>root->key){
        //if right range greater than root->key check right side for some
        sum+=RangeSum(root->right,L,R);
        }

        return sum;
    }

    void displayTransactions(node* root){
        //inorder display of transactions made

        if(root==NULL)return;
        displayTransactions(root->left);
        cout<<root->key<<" ";
        displayTransactions(root->right);
    }

    void displayTransactions(){
        displayTransactions(root);
    }

    void insert(int key){
        root=insert(root,key);
    }

    int RangeSum(int L,int R){
       return RangeSum(root,L,R);
    }
};

int main(){
    AVLtransactions tree;
    //transactions made
    int transactions[]={200,50,300,400,700,150};
    int size=sizeof(transactions)/sizeof(transactions[0]);

    for(int i=0;i<size;i++){
        tree.insert(transactions[i]);
    }

    cout<<"Displaying transactions tree: "<<endl;
    tree.displayTransactions();

    //sum for L and R given
    int L=100;
    int R=500;

    int output=tree.RangeSum(L,R);

    cout<<"\nSum for Range is: "<<output<<endl;  
}