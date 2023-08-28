#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    Node* root;
    
    Node* insertNode(Node* currentNode, int value) {
        if (currentNode == nullptr) {
            Node* newNode = new Node(value);
            return newNode;
        }
        
        if (value < currentNode->data)
            currentNode->left = insertNode(currentNode->left, value);
        else
            currentNode->right = insertNode(currentNode->right, value);
        
        return currentNode;
    }
    
public:
    BinaryTree() {
        root = nullptr;
    }
    
    void insert(int value) {
        root = insertNode(root, value);
    }
    
    void inorderTraversal(Node* currentNode) {
        if (currentNode == nullptr)
            return;
        
        inorderTraversal(currentNode->left);
        cout << currentNode->data << " ";
        inorderTraversal(currentNode->right);
    }
    
    void inorder() {
        inorderTraversal(root);
    }
};

int main() {
    BinaryTree tree;
    
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    
    cout << "Inorder traversal of binary search tree: ";
    tree.inorder();
    
    return 0;
}