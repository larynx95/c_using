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

# header linked list
- Grounded header linked list
- Circular header linked list

# questions
- TODO: What is the function of the header node?
        What is the headed linked list for?
- We can store frequently-used data into header node.
  ex) the number of elems, sums, ...

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;
struct node *create_hll(struct node *);
struct node *display(struct node *);

int main() {
  int option;
  system("clear");

  do {
    printf("*****MAIN MENU *****\n");
    printf("1: Create a list\n");
    printf("2: Display the list\n");
    printf("3: EXIT\n");
    printf("Enter your option\n: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        start = create_hll(start);
        printf("HEADER LINKED LIST CREATED\n");
        break;
      case 2:
        start = display(start);
        break;
    }
  } while (option != 3);

  return 0;
}

/**********************************************************
 * Create header linked list
 - 'start' is not a pointer in this structure, but header node
 **********************************************************/

struct node *create_hll(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end\n");
  printf("Enter the data : ");
  scanf("%d", &num);

  while (num != -1) {
    new_node = malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    /* empty list */
    if (start == NULL) {
      start = malloc(sizeof(struct node));
      start->next = new_node;
    }
    /* not empty */
    else {
      ptr = start;
      while (ptr->next != NULL) ptr = ptr->next;
      ptr->next = new_node;
    }

    printf("Enter the data : ");
    scanf("%d", &num);
  }

  return start;
}

/**********************************************************
 * Display
 - not a specific purpose, but simpley displaying linked list
 **********************************************************/

struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  return start;
}