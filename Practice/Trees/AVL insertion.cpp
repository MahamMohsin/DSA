#include <iostream>
using namespace std;

class node{
public:
int key;//same as data
int height;//height for balance factor
node* left;
node* right;

node(int k){
    height=1;//height of node created initialized as 1
    key=k;
    this->left=NULL;
    this->right=NULL;
    }
};

class avl{
    public:
    node* root=NULL;

    node* insert(node* root,int key){
        //initially insertion mein bst ka code hoga
        if(root==NULL){
            return new node(key);
        }

        if(key>root->key){
            root->right=insert(root->right,key);
        }
        else if(key<root->key){
            root->left=insert(root->left,key);
        }//bus root not returned here warna bst insertion hojati

        //now when insertion calls over height of node should be equal to max subtree height
        root->height=nodeHeight(root);//a function to calc height of node(max height) at every call height updated

        if(bf(root)==2 && bf(root->left)==1){
            //call ll rot kuike right pe kuch hai hee nahi na matlab
            return llrotation(root);
        }
        else if(bf(root)==-2 && bf(root->right)==-1){
            //call rr rot kiuke right pe hoga aur phir right ke right pe
            return rrrotation(root);
        }
        else if(bf(root)==2 && bf(root->left)==-1){
            //call lr rotation
            return lrrotation(root);
        }
        else if(bf(root)==-2 && bf(root->right)==1){
            return rlrotation(root);
        }

        return root;
    }

    int nodeHeight(node* ptr){
        int hl,hr;
        //if(ptr==NULL)return 0;
        //hl=nodeHeight(ptr->left);
        //hr=nodeHeight(ptr->right);
        hl=ptr && ptr->left?ptr->left->height:0;
        hr=ptr&& ptr->right?ptr->right->height:0;

    return hr>hl?hr+1:hl+1;
    }

//balance factor that is basically 
    int bf(node* ptr){
        int hr,hl;

        //recalculate heights of each subtree then subtract and return
        hl=ptr && ptr->left?ptr->left->height:0;
        hr=ptr&& ptr->right?ptr->right->height:0;

        return hl-hr;//BalanceFactor=HeightofLeftSubtree-HeightofRightSubtree
    }

    //ll rotate function
    node* llrotation(node* ptr){
        node* pl=ptr->left;//left child
        node* plr=pl->right;//ptr->left->right child

        //first update pl jo ke apka head pos lelega
        pl->right=ptr;
        ptr->left=plr;

        //check balancing height again
        ptr->height=nodeHeight(ptr);
        pl->height=nodeHeight(pl);

        if(root==ptr){
            //means root and ptr are at same loc
            root=pl;
        }

        return pl;
    }

    node* rrrotation(node* ptr){
        node* pr=ptr->right;
        node* prl=pr->left;

        pr->left=ptr;//bec right to left rotation
        ptr->right=prl;

        ptr->height=nodeHeight(ptr);
        pr->height=nodeHeight(pr);

        if(pr==root){
            root=pr;
        }
        return pr;
    }

    node* lrrotation(node* ptr){
        node* pl=ptr->left;
        node* plr=pl->right;

        pl->right=plr->left;//childs updated
        ptr->left=plr->right;

        plr->left=pl;
        plr->right=ptr;

        pl->height=nodeHeight(pl);
        ptr->height=nodeHeight(ptr);
        plr->height=nodeHeight(plr);

        if (ptr== root){
        root = plr;
    }
return plr;//new root
    }

    node* rlrotation(node* p){
    node* pr = p->right;
    node* prl = pr->left;
 
    pr->left = prl->right;
    p->right = prl->left;
 
    prl->right= pr;
    prl->left = p;
 
    // Update height
    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
    }

    void display(node* root){
        if(root==NULL){
            return;
        }
        display(root->left);
        cout<<root->key<<" ";
        display(root->right);
    }
};

int main() {
    avl tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 25);
    tree.root = tree.insert(tree.root, 35);
    tree.root = tree.insert(tree.root, 50);

    // Display the AVL tree in sorted order
    cout << "In-order traversal of AVL tree: ";
    tree.display(tree.root);
    cout << endl;

    return 0;
}
