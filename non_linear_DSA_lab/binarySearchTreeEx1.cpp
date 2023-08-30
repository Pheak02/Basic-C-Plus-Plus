#include <iostream>

// Structure for each node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (root == nullptr) 
        return;

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform preorder traversal
void preorderTraversal(Node* root) {
    if (root == nullptr) 
        return;

    std::cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(Node* root) {
    if (root == nullptr) 
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    // Creating the nodes
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    // Creating the tree structure
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;

    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);

    std::cout << "\nPreorder Traversal: ";
    preorderTraversal(root);

    std::cout << "\nPostorder Traversal: ";
    postorderTraversal(root);

    std::cout << std::endl;

    return 0;
}

