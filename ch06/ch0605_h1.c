/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists
6.1 Introduction
  6.1.1 Basic terminology
  6.1.2 Linked lists versus arrays
  6.1.3 Memory allocation and de-allocation for a linked list
6.2 Singly linked lists
  6.2.1 Traversing a linked list
  6.2.2 Searching fir a value in a linked list
  6.2.3 Inserting a new node in a linked list
    Inserting a node at the beginning of a linked list
    Inserting a node at the end of a linked list
    Inserting a node after a given node in a linked list
    Inserting a node before a given node in a linked list
  6.2.4 Deleting a node from a linked list
    Deleting the first node from a linked list
    Deleting the last node from a linked list
    Deleting the node after a given node in a linked list (Program example 1)
6.3 Circular linked lists
  6.3.1 Inserting a new node in a circular linked list
    Inserting a node at the beginning of a circular linked list
    Inserting a node at the end of a circular linked list
  6.3.2 Deleting a node from a circular linked list
    Deleting the first node from a circular linked list
    Deleting the last node from a circular linked list (Program example 2)
6.4 Doubly linked lists
  6.4.1 Inserting a new node in a doubly linked list
    Inserting a node at the beginning of a doubly linked list
    Inserting a node at the end of a doubly linked list
    Inserting a node after a given node in a doubly linked list
    Inserting a node before a given node in a doubly linked list
  6.4.2 Deleting a node from a doubly linked list
    Deleting the first node from a doubly linked list
    Deleting the last node from a doubly linked list
    Deleting the node after a given node in a doubly linked list
    Deleting the node before a given node in a doubly linked list
    (Program example 3)
6.5 Circular doubly linked lists
  6.5.1 Inserting a new node in a circular doubly linked list
    Inserting a node at the beginning of a circular doubly linked list
    Inserting a node at the end of a circular doubly linked list
  6.5.2 Deleting a node from a circular doubly linked list
    Deleting the first node from a circular doubly linked list
    Deleting the last node from a circular doubly linked list
    (Program example 4)
6.6 Header linked lists (Program example 5)
*/

/*
Programming Example
5. Write a program to implement a header linked list.

https://www.geeksforgeeks.org/header-linked-list-in-c/

*/

#include <stdio.h>
#include <stdlib.h>

struct link {
  int info;
  struct link* next;
};

struct link* start = NULL;

struct link* create_header_list(int data);
struct link* display();

int main() {
  // Create the list
  create_header_list(11);
  create_header_list(12);
  create_header_list(13);

  // Print the list
  display();
  create_header_list(14);
  create_header_list(15);

  // Print the list
  display();

  return 0;
}

struct link* create_header_list(int data) {
  // Create a new node
  struct link *new_node, *node;
  new_node = (struct link*)malloc(sizeof(struct link));
  new_node->info = data;
  new_node->next = NULL;

  // If it is the first node
  if (start == NULL) {
    // Initialize the start
    start = (struct link*)malloc(sizeof(struct link));
    start->next = new_node;
  } else {
    // Insert the node in the end
    node = start;
    while (node->next != NULL) {
      node = node->next;
    }
    node->next = new_node;
  }
  return start;
}

struct link* display() {
  struct link* node;
  node = start;
  node = node->next;  // cuz start node doesn't have meaningful value
  while (node != NULL) {
    printf("%d ", node->info);
    node = node->next;
  }
  printf("\n");
  return start;
}
