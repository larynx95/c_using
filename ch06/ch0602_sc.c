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
*/

/*
Programming Example
2. Write a program to create a circular linked list.
Perform insertion and deletion at the beginning and end of the list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
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
    printf("7: Delete a node after a given node\n");
    printf("8: Delete the entire list\n");
    printf("9: EXIT\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        start = create_cll(start);
        printf("CIRCULAR LINKED LIST CREATED\n");
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
        start = delete_after(start);
        break;
      case 8:
        start = delete_list(start);
        printf("CIRCULAR LINKED LIST DELETED\n");
        break;
    }
  } while (option != 9);
  getch();
  return 0;
}

/**********************************************************
 * Creating circular linked list
 **********************************************************/

struct node *create_cll(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end\n");
  printf("Enter the data: ");
  scanf("%d", &num);

  while (num != -1) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    /* if there's no preexisting clklst... */
    if (start == NULL) {
      new_node->next = new_node;  // TODO: pointing itself??
      start = new_node;
    }
    /* if there's preexisting node */
    else {
      ptr = start;
      while (ptr->next != start) ptr = ptr->next;
      ptr->next = new_node;
      new_node->next = start;
    }
    printf("Enter the data: ");
    scanf("%d", &num);
  }
  return start;
}

/**********************************************************
 * Display circular linked list
 **********************************************************/

struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next != start) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  /* last element */
  printf("%d \n", ptr->data);

  return start;
}

/**********************************************************
 * Insert at the beginning
 **********************************************************/

struct node *insert_beg(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter the data : ");
  scanf("%d", &num);

  /* initializing the value of new node */
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* find the end, add, move start pointer */
  ptr = start;
  while (ptr->next != start) ptr = ptr->next;
  ptr->next = new_node;
  new_node->next = start;
  start = new_node;

  return start;
}

/**********************************************************
 * Insert at the end
 * - Exactly the same code as above
 **********************************************************/

struct node *insert_end(struct node *start) {
  struct node *ptr, *new_node;
  int num;
  printf("Enter the data : ");
  scanf("%d", &num);

  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  ptr = start;
  while (ptr->next != start) ptr = ptr->next;
  ptr->next = new_node;
  new_node->next = start;

  return start;
}

/**********************************************************
 * Delete the beginning node
 * - deletes a node which `start` is pointing
 **********************************************************/

struct node *delete_beg(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next != start) ptr = ptr->next;
  ptr->next = start->next;
  free(start);
  start = ptr->next;
  return start;
}

/**********************************************************
 * Delete a node at the end of list
 **********************************************************/

struct node *delete_end(struct node *start) {
  struct node *ptr, *preptr;

  /* find the last(?) node */
  ptr = start;
  while (ptr->next != start) {
    preptr = ptr;
    ptr = ptr->next;
  }

  /* exising, linking, freeing */
  preptr->next = ptr->next;
  free(ptr);

  return start;
}

/**********************************************************
 * Delete a node after a given node
 **********************************************************/

struct node *delete_after(struct node *start) {
  struct node *ptr, *preptr;
  int val;
  printf("Enter the value after which the node has to deleted : ");
  scanf("%d", &val);

  /* find the position */
  ptr = start;
  preptr = ptr;
  while (preptr->data != val) {
    preptr = ptr;
    ptr = ptr->next;
  }
  preptr->next = ptr->next;

  /* if we are deleting the start node */
  if (ptr == start) start = preptr->next;
  free(ptr);

  return start;
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