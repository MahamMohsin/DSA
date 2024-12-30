#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isLeftSkewed(Node* root) {
    while (root) {
        if (root->right) // If there's a right child, it's not left-skewed
            return false;
        root = root->left; // Move to the left child
    }
    return true;
}

bool isRightSkewed(Node* root) {
    while (root) {
        if (root->left) // If there's a left child, it's not right-skewed
            return false;
        root = root->right; // Move to the right child
    }
    return true;
}

int main() {
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    
    if (isLeftSkewed(root)) {
        cout << "The tree is left-skewed.\n";
    } else if (isRightSkewed(root)) {
        cout << "The tree is right-skewed.\n";
    } else {
        cout << "The tree is not skewed.\n";
    }
    
    return 0;
}