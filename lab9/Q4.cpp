#include <iostream>
#include <queue>
using namespace std;

class node{
public:
    int key;
    int height;
    node* left;
    node* right;

    node(int k){
        key = k;
        height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

class avl{
public:
    node* root=NULL;

    node* insert(node* root, int key){
        if (root==NULL){
            return new node(key);
        }

        if (root->key>key){
            root->left=insert(root->left, key);
        }

        else if (root->key<key){
            root->right=insert(root->right, key);
        }

        root->height=getHeight(root);
        return balance(root);
    }

    node* search(node* root, int key){
        int index = 0;
        queue<node *> qt;
        qt.push(root);
        while (!qt.empty()){
            node *ptr=qt.front();
            qt.pop();

            if (key==ptr->key){
                cout <<"Found key: "<<key<<" at index "<< index<<endl;
                return ptr;
            }

            if (ptr->left){
                qt.push(ptr->left);
                index++;
            }

            if (ptr->right){
                qt.push(ptr->right);
                index++;
            }
        }

        cout<<"Key not found! Inserting and balancing "<< endl;
        return insert(root,key);
    }

    int getHeight(node* ptr){
        if (ptr==NULL){
            return 0;
        }
        int rightHeight,leftHeight;

        rightHeight=ptr && ptr->right?ptr->right->height:0;
        leftHeight=ptr && ptr->left?ptr->left->height:0;

        return rightHeight>leftHeight?rightHeight+1:leftHeight+1;
    }

    int balancefactor(node* ptr){
        if (ptr == NULL){
            return 0;
        }
        int rightHeight, leftHeight;

        leftHeight = ptr && ptr->left ? ptr->left->height : 0;
        rightHeight = ptr && ptr->right ? ptr->right->height : 0;

        return leftHeight - rightHeight;
    }

    node* balance(node* root){
        if (balancefactor(root) == 2 && balancefactor(root->left) >= 0)
            return LLrotation(root);
        if (balancefactor(root) == 2 && balancefactor(root->left) < 0)
            return LRrotation(root);
        if (balancefactor(root) == -2 && balancefactor(root->right) <= 0)
            return RRrotation(root);
        if (balancefactor(root) == -2 && balancefactor(root->right) > 0)
            return RLrotation(root);
        return root;
    }

    node* LLrotation(node* ptr){
        node *pl = ptr->left;
        node *plr = pl->right;

        pl->right = ptr;
        ptr->left = plr;

        ptr->height = getHeight(ptr);
        pl->height = getHeight(pl);

        if (root==ptr){
            root = pl;
        }
    return pl;
    }

    node* RRrotation(node* ptr){
        node *pr = ptr->right;
        node *prl = pr->left;

        pr->left = ptr;
        ptr->right = prl;

        ptr->height = getHeight(ptr);
        pr->height = getHeight(pr);

        if (ptr == root){
            root = pr;
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

    void display(node* root){
        if (root==NULL){
            return;
        }
        display(root->left);
        cout << root->key << " ";
        display(root->right);
    }

    void insert(int key){
        root=insert(root, key);
    }

    void search(int key){
        root=search(root, key);
    }

    void display(){
        display(root);
    }
};

int main(){
    avl tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    cout <<"Displaying AVL tree: "<<endl;
    tree.display();

    int to_search;
    cout<<"\nEnter key to search: ";
    cin>>to_search;
    cout<<endl;

    tree.search(to_search);

    return 0;
}