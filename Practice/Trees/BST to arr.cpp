#include <iostream>
using namespace std;

// Definition of a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Helper function to insert a node in the BST
Node* insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform inorder traversal and store nodes in an array
void inorderTraversal(Node* root, int arr[], int &index) {
    if (root == nullptr) return;
    
    // Traverse the left subtree
    inorderTraversal(root->left, arr, index);
    
    // Visit the root node
    arr[index++] = root->data;
    
    // Traverse the right subtree
    inorderTraversal(root->right, arr, index);
}

// Wrapper function to copy BST to an array
void copyBSTToArray(Node* root, int arr[]) {
    int index = 0;
    inorderTraversal(root, arr, index);
}

int main() {
    // Create the BST
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    
    // Define an array to hold the BST elements
    int size = 7;
    int arr[size];
    
    // Copy BST elements to the array
    copyBSTToArray(root, arr);
    
    // Print the array
    cout << "BST elements in array (Inorder): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
