#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node for the doubly linked list
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to display the doubly linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Function to swap two nodes in the doubly linked list
void swapNodes(Node** head, Node* node1, Node* node2) {
    if (node1 == node2) {
        return;
    }
    if (node1->next == node2) {
        node1->next = node2->next;
        if (node2->next != nullptr) {
            node2->next->prev = node1;
        }
        node2->prev = node1->prev;
        node2->next = node1;
        if (node1->prev != nullptr) {
            node1->prev->next = node2;
        }
        node1->prev = node2;
        if (*head == node1) {
            *head = node2;
        }
    } else if (node2->next == node1) {
        node2->next = node1->next;
        if (node1->next != nullptr) {
            node1->next->prev = node2;
        }
        node1->prev = node2->prev;
        node1->next = node2;
        if (node2->prev != nullptr) {
            node2->prev->next = node1;
        }
        node2->prev = node1;
        if (*head == node2) {
            *head = node1;
        }
    } else {
        Node* temp = node1->next;
        node1->next = node2->next;
        if (node2->next != nullptr) {
            node2->next->prev = node1;
        }
        node2->next = temp;
        if (temp != nullptr) {
            temp->prev = node2;
        }
        temp = node1->prev;
        node1->prev = node2->prev;
        if (node2->prev != nullptr) {
            node2->prev->next = node1;
        }
        node2->prev = temp;
        if (temp != nullptr) {
            temp->next = node2;
        }
        if (*head == node1) {
            *head = node2;
        } else if (*head == node2) {
            *head = node1;
        }
    }
}

// Function to partition the doubly linked list using a pivot element
Node* partition(Node** head, Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;
    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swapNodes(head, j, i);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swapNodes(head, high, i);
    return i;
}

// Function to implement Quicksort on the doubly linked list
void quickSort(Node** head, Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(head, low, high);
        quickSort(head, low, pivot->prev);
        quickSort(head, pivot->next, high);
    }
}

int main() {
    Node* head = nullptr;

    // Insert nodes into the doubly linked list
    insertAtBeginning(&head, 25);
    insertAtBeginning(&head, 14);
    insertAtBeginning(&head, 33);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 42);
    insertAtBeginning(&head, 17);
    
    // Display the original list
    cout << "Original list: ";
    displayList(head);
    
    // Perform Quicksort on the doubly linked list
    quickSort(&head, head, nullptr);

    // Display the sorted list
    cout << "Sorted list on Doubly Link List: ";
    displayList(head);

    return 0;
}