#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// new node created
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// TRAVERSE INORDER
void traverseInOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
}
// TRAVERSE PREORDER
void traversePreOrder(struct node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data; // data refers to the NODE
        traverseInOrder(temp->left);
        traversePreOrder(temp->right);
    }
}
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}
int main()
{
    int option;
    cout << " Enter option to choose traversal";
    cout << " 1. Inorder Traversal";
    cout << " 2. Preorder Traversal";
    cout << " 3. Postorder Traversal";
    cin >> option;
    switch (option)
    {
    case 1:
        traverseInOrder(struct node * temp);
        break;
    }
}