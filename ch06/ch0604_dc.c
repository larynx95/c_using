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
*/

/*
Programming Example
4. Write a program to create a circular doubly linked list
and perform insertions and deletions at the beginning and end of the list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next;
  int data;
  struct node *prev;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main() {
  int option;
  system("clear");
  do {
    printf("*****MAIN MENU *****\n");
    printf("1: Create a list\n");
    printf("2: Display the list\n");
    printf("3: Add a node at the beginning\n");
    printf("4: Add a node at the end\n");
    printf("5: Delete a node from the beginning\n");
    printf("6: Delete a node from the end\n");
    printf("7: Delete a given node\n");
    printf("8: Delete the entire list\n");
    printf("9: EXIT\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        start = create_ll(start);
        printf("CIRCULAR DOUBLY LINKED LIST CREATED\n");
        break;
      case 2:
        start = display(start);
        break;
      case 3:
        start = insert_beg(start);
        break;
      case 4:
        start = insert_end(start);
        break;
      case 5:
        start = delete_beg(start);
        break;
      case 6:
        start = delete_end(start);
        break;
      case 7:
        start = delete_node(start);
        break;
      case 8:
        start = delete_list(start);
        printf("CIRCULAR DOUBLY LINKED LIST DELETED\n");
        break;
    }
  } while (option != 9);

  return 0;
}

/**********************************************************
 * Create list
 **********************************************************/

struct node *create_ll(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end\n");
  printf("Enter the data: ");
  scanf("%d", &num);

  while (num != -1) {
    if (start == NULL) {
      /* no preexisting list */
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->prev = NULL;  // TODO: start???
      new_node->data = num;
      new_node->next = start;
      start = new_node;
    } else {
      /* There's preexisting list */
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->data = num;
      ptr = start;
      while (ptr->next != start) ptr = ptr->next;
      new_node->prev = ptr;
      ptr->next = new_node;
      new_node->next = start;
      start->prev = new_node;
    }

    printf("Enter the data: ");
    scanf("%d", &num);
  }

  return start;
}

/**********************************************************
 * Display
 **********************************************************/

struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next != start) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("%d \n", ptr->data);

  return start;
}

/**********************************************************
 * Insert a node at the beginning
 **********************************************************/

struct node *insert_beg(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter the data: ");
  scanf("%d", &num);

  /* initializing new node */
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* find the end */
  ptr = start;
  while (ptr->next != start) ptr = ptr->next;

  /* linking */
  new_node->prev = ptr;
  ptr->next = new_node;
  new_node->next = start;
  start->prev = new_node;

  /* reset start pointer */
  start = new_node;

  return start;
}

/**********************************************************
 * Insert a node at the end
 **********************************************************/

struct node *insert_end(struct node *start) {
  struct node *ptr, *new_node;
  int num;
  printf("Enter the data: ");
  scanf("%d", &num);

  /* initializing new node */
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* find the end */
  ptr = start;
  while (ptr->next != start) ptr = ptr->next;

  /* linking */
  ptr->next = new_node;
  new_node->prev = ptr;
  new_node->next = start;
  start->prev = new_node;

  return start;
}

/**********************************************************
 * Delete the first node
 **********************************************************/

struct node *delete_beg(struct node *start) {
  struct node *ptr, *temp;

  /* find the end */
  ptr = start;
  while (ptr->next != start) ptr = ptr->next;

  /* linking */
  ptr->next = start->next;
  temp = start;  // temp pointer for deallocation
  start = start->next;
  start->prev = ptr;
  free(temp);

  return start;
}

/**********************************************************
 * Delete the last node
 **********************************************************/

struct node *delete_end(struct node *start) {
  struct node *ptr;

  /* find the end */
  ptr = start;
  while (ptr->next != start) ptr = ptr->next;

  /* linking */
  ptr->prev->next = start;
  start->prev = ptr->prev;
  free(ptr);

  return start;
}

/**********************************************************
 * Delete a node
 **********************************************************/

struct node *delete_node(struct node *start) {
  struct node *ptr;
  int val;
  printf("Enter the value of the node which has to be deleted : ");
  scanf("%d", &val);

  ptr = start;
  if (ptr->data == val) {
    start = delete_beg(start);
    return start;
  } else {
    while (ptr->data != val) ptr = ptr->next;
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);

    return start;
  }
}

/**********************************************************
 * Delete all
 **********************************************************/

struct node *delete_list(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next != start) start = delete_end(start);
  free(start);

  return start;
}