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

    node* minValueNode(node* root){
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
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
        rightHeight=ptr&& ptr->right?ptr->right->height:0;

        return leftHeight-rightHeight;
    }

    node* balance(node* root){
        if (balancefactor(root) == 2 && balancefactor(root->left) >= 0) return LLrotation(root);
        if (balancefactor(root) == 2 && balancefactor(root->left) < 0) return LRrotation(root);
        if (balancefactor(root) == -2 && balancefactor(root->right) <= 0) return RRrotation(root);
        if (balancefactor(root) == -2 && balancefactor(root->right) > 0) return RLrotation(root);
        return root;
    }

    node* deleteNode(node* root, int key){
        if(root==NULL){
		return NULL;
		}

        if(key<root->key){
            root->left=deleteNode(root->left,key);
        } 
		else if(key>root->key){
            root->right=deleteNode(root->right,key);
        } 
		else{
            if(root->left==NULL||root->right==NULL){
                node* temp=root->left?root->left:root->right;
                delete root;
                root = temp;
            } 
			else{
                node* temp=minValueNode(root->right);
                root->key=temp->key;
                root->right=deleteNode(root->right, temp->key);
            }
        }

        if(root==NULL){
		return root;
	}

        root->height=getHeight(root);

        return balance(root);
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

    void deleteNode(int key){
        root=deleteNode(root,key);
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

    cout<<"Displaying AVL tree before deletion: "<<endl;
    tree.display();

    tree.deleteNode(3);
    cout<<"\n\nDisplaying tree after deleting value 3: "<<endl;
    tree.display();
    
return 0;
}