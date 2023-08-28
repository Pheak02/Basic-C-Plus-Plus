#include <iostream>
using namespace std;

// Definition for singly-linked list
struct Node {
  int data;
  Node *next;

  // Constructor
  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

// Function to insert a new node at the end of the list
void insert(Node *&head, int data) {
  Node *newNode = new Node(data);

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = newNode;
}

// Function to find the tail of a linked list
Node *getTail(Node *head) {
  if (head == NULL)
    return NULL;
  while (head->next != NULL) {
    head = head->next;
  }
  return head;
}

// Function to print the linked list
void printList(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

// Function to swap two nodes in a linked list
void swapNodes(Node *prev1, Node *curr1, Node *prev2, Node *curr2) {
  if (prev1 == NULL) {
    prev2->next = curr1;
    Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
  } else if (prev2 == NULL) {
    prev1->next = curr2;
    Node *temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
  } else {
    prev1->next = curr2;
    prev2->next = curr1;
    Node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
  }
}

// Partition function for quicksort
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd) {
  Node *pivot = end;
  Node *prev = NULL;
  Node *curr = head;
  Node *tail = pivot;

  while (curr != pivot) {
    if (curr->data < pivot->data) {
      if (*newHead == NULL)
        *newHead = curr;
      prev = curr;
      curr = curr->next;
    } else {
      if (prev)
        prev->next = curr->next;
      Node *temp = curr->next;
      curr->next = NULL;
      tail->next = curr;
      tail = curr;
      curr = temp;
    }
  }

  if (*newHead == NULL)
    *newHead = pivot;
  *newEnd = tail;
  return pivot;
}

// Quicksort function for linked list
Node *quicksort(Node *head, Node *end) {
  if (!head || head == end)
    return head;

  Node *newHead = NULL;
  Node *newEnd = NULL;
  Node *pivot = partition(head, end, &newHead, &newEnd);

  if (newHead != pivot) {
    Node *temp = newHead;
    while (temp->next != pivot)
      temp = temp->next;
    temp->next = NULL;
    newHead = quicksort(newHead, temp);
    temp = getTail(newHead);
    temp->next = pivot;
  }

  if (pivot != newEnd)
    pivot->next = quicksort(pivot->next, newEnd);
  return newHead;
}

int main() {
  Node *head = NULL;

  // Insert sample elements into the linked list
  insert(head, 5);
  insert(head, 3);
  insert(head, 8);
  insert(head, 6);
  insert(head, 2);
  insert(head, 9);

  cout << "Linked List before Sorting: ";
  printList(head);

  Node *newHead = quicksort(head, getTail(head));

  cout << "Linked List after Sorting on Singly Link List: ";
  printList(newHead);

  return 0;
}