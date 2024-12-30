#include <iostream>
using namespace std;

class node {
public:
    int key;
    int height;
    node* left;
    node* right;

    node(int k) {
        height = 1;
        key = k;
        left = right = NULL;
    }
};

class avl {
public:
    node* root = NULL;

    node* insert(node* root, int key) {
        if (root == NULL) {
            return new node(key);
        }

        if (key > root->key) {
            root->right = insert(root->right, key);
        } else if (key < root->key) {
            root->left = insert(root->left, key);
        }

        root->height = nodeHeight(root);

        return balance(root);
    }

    node* deleteNode(node* root, int key) {
        if (root == NULL) return NULL;

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL || root->right == NULL) {
                node* temp = root->left ? root->left : root->right;
                delete root;
                root = temp;
            } else {
                node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == NULL) return root;

        root->height = nodeHeight(root);

        return balance(root);//re balancing
    }

    node* minValueNode(node* root) {
        while (root->left != NULL) root = root->left;
        return root;
    }

    int nodeHeight(node* ptr) {
        int hl = ptr && ptr->left ? ptr->left->height : 0;
        int hr = ptr && ptr->right ? ptr->right->height : 0;
        return max(hl, hr) + 1;
    }

    int bf(node* ptr) {
        int hl = ptr && ptr->left ? ptr->left->height : 0;
        int hr = ptr && ptr->right ? ptr->right->height : 0;
        return hl - hr;
    }

    node* balance(node* root) {
        if (bf(root) == 2 && bf(root->left) >= 0) return llrotation(root);
        if (bf(root) == 2 && bf(root->left) < 0) return lrrotation(root);
        if (bf(root) == -2 && bf(root->right) <= 0) return rrrotation(root);
        if (bf(root) == -2 && bf(root->right) > 0) return rlrotation(root);
        return root;
    }

    node* llrotation(node* ptr) {
        node* pl = ptr->left;
        node* plr = pl->right;
        pl->right = ptr;
        ptr->left = plr;
        ptr->height = nodeHeight(ptr);
        pl->height = nodeHeight(pl);
        if (root == ptr) root = pl;
        return pl;
    }

    node* rrrotation(node* ptr) {
        node* pr = ptr->right;
        node* prl = pr->left;
        pr->left = ptr;
        ptr->right = prl;
        ptr->height = nodeHeight(ptr);
        pr->height = nodeHeight(pr);
        if (root == ptr) root = pr;
        return pr;
    }

    node* lrrotation(node* ptr) {
        ptr->left = rrrotation(ptr->left);
        return llrotation(ptr);
    }

    node* rlrotation(node* ptr) {
        ptr->right = llrotation(ptr->right);
        return rrrotation(ptr);
    }

    void display(node* root) {
        if (root == NULL) return;
        display(root->left);
        cout << root->key << " ";
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

    // Display the AVL tree
    cout << "In-order traversal of AVL tree: ";
    tree.display(tree.root);
    cout << endl;

    // Delete a node
    tree.root = tree.deleteNode(tree.root, 20);
    cout << "In-order traversal after deletion: ";
    tree.display(tree.root);
    cout << endl;

    return 0;
}
