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
*/

/*
Programming Example
3. Write a program to create a doubly linked list
and perform insertions and deletions in all cases.

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
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
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
    printf("5: Add a node before a given node\n");
    printf("6: Add a node after a given node\n");
    printf("7: Delete a node from the beginning\n");
    printf("8: Delete a node from the end\n");
    printf("9: Delete a node before a given node\n");
    printf("10: Delete a node after a given node\n");
    printf("11: Delete the entire list\n");
    printf("12: EXIT\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        start = create_ll(start);
        printf("DOUBLY LINKED LIST CREATED\n");
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
        start = insert_before(start);
        break;
      case 6:
        start = insert_after(start);
        break;
      case 7:
        start = delete_beg(start);
        break;
      case 8:
        start = delete_end(start);
        break;
      case 9:
        start = delete_before(start);
        break;
      case 10:
        start = delete_after(start);
        break;
      case 11:
        start = delete_list(start);
        printf("DOUBLY LINKED LIST DELETED\n");
        break;
    }
  } while (option != 12);

  return 0;
}

/**********************************************************
 * Create doubly linked list
 * TODO: Creating and sorting simultaneously
 - Actually, this fx is both creating and adding new node simultaneously
 - This fx needs to be slimmer
 **********************************************************/

struct node *create_ll(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end\n");
  printf("Enter the data: ");
  scanf("%d", &num);

  while (num != -1) {
    /* if there's no preexisting list */
    if (start == NULL) {
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->prev = NULL;
      new_node->data = num;
      new_node->next = NULL;
      start = new_node;
    }
    /* if there's preexisting list */
    else {
      ptr = start;
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->data = num;
      /* go to the end */
      while (ptr->next != NULL) ptr = ptr->next;
      /* linking */
      ptr->next = new_node;
      new_node->prev = ptr;
      new_node->next = NULL;
    }
    /* add new node */
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
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
  return start;
}

/**********************************************************
 * Insert new node at the beginning (prepend)
 **********************************************************/

struct node *insert_beg(struct node *start) {
  int num;
  printf("Enter the data: ");
  scanf("%d", &num);

  /* memory assignment for a new node */
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* link a new node to the beginning of the linked list */
  start->prev = new_node;  // prepend
  new_node->next = start;  // connect new & start node
  new_node->prev = NULL;   // no node before new node
  start = new_node;        // move start pointer to the left-most node

  return start;
}

/**********************************************************
 * Insert new node at the end
 **********************************************************/

struct node *insert_end(struct node *start) {
  int num;
  printf("Enter the data: ");
  scanf("%d", &num);

  /* memory assignment for a new node */
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* traversing lst to the end of it */
  struct node *ptr = start;
  while (ptr->next != NULL) ptr = ptr->next;

  /* linking */
  ptr->next = new_node;
  new_node->prev = ptr;
  new_node->next = NULL;

  return start;
}

/**********************************************************
 * Insert new node before a given node
 **********************************************************/

struct node *insert_before(struct node *start) {
  /* get data from stdin */
  int num, val;
  printf("Enter the data: ");
  scanf("%d", &num);
  printf("Enter the value before which the data has to be inserted: ");
  scanf("%d", &val);

  /* memeory assignment for a new node */
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* traverse list to find target node */
  struct node *ptr;
  ptr = start;
  while (ptr->data != val) ptr = ptr->next;

  /* linking, consider both direction */
  new_node->prev = ptr->prev;
  ptr->prev->next = new_node;  // TODO: apply this concept to other linked lists
  ptr->prev = new_node;
  new_node->next = ptr;

  return start;
}

/**********************************************************
 * Insert new node after a given node
 **********************************************************/

struct node *insert_after(struct node *start) {
  struct node *new_node, *ptr;
  int num, val;
  printf("Enter the data: ");
  scanf("%d", &num);
  printf("Enter the value after which the data has to be inserted: ");
  scanf("%d", &val);

  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  ptr = start;
  while (ptr->data != val) ptr = ptr->next;

  new_node->prev = ptr;
  new_node->next = ptr->next;
  ptr->next->prev = new_node;
  ptr->next = new_node;

  return start;
}

/**********************************************************
 * Delete the first node
 **********************************************************/

struct node *delete_beg(struct node *start) {
  struct node *ptr;
  ptr = start;
  start = start->next;
  start->prev = NULL;
  free(ptr);
  return start;
}

/**********************************************************
 * Delete a last node
 **********************************************************/

struct node *delete_end(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr->next != NULL) ptr = ptr->next;
  ptr->prev->next = NULL;
  free(ptr);
  return start;
}

/**********************************************************
 * Delete a node after a given node
 **********************************************************/

struct node *delete_after(struct node *start) {
  struct node *ptr, *temp;
  int val;
  printf("Enter the value after which the node has to deleted: ");
  scanf("%d", &val);

  ptr = start;
  while (ptr->data != val) ptr = ptr->next;

  temp = ptr->next;
  ptr->next = temp->next;
  temp->next->prev = ptr;
  free(temp);

  return start;
}

/**********************************************************
 * Delete a node before a given node
 **********************************************************/

struct node *delete_before(struct node *start) {
  struct node *ptr, *temp;
  int val;
  printf("Enter the value before which the node has to deleted: ");
  scanf("%d", &val);

  ptr = start;
  while (ptr->data != val) ptr = ptr->next;

  temp = ptr->prev;
  if (temp == start)
    start = delete_beg(start);
  else {
    ptr->prev = temp->prev;
    temp->prev->next = ptr;
  }
  free(temp);

  return start;
}

/**********************************************************
 * Delete all
 **********************************************************/

struct node *delete_list(struct node *start) {
  while (start != NULL) start = delete_beg(start);
  return start;
}