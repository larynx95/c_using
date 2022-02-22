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
*/

/*
Programming Example
1. Write a program to create a linked list and perform insertions and deletions
of all cases. Write functions to sort and finally delete the entire list at
once.
TODO: Implement these function as void return type.
*/

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);     /* create a new linked list */
struct node *display(struct node *);       /* display linked list */
struct node *insert_beg(struct node *);    /* insert at the beginning */
struct node *insert_end(struct node *);    /* insert at the end */
struct node *insert_before(struct node *); /* insert before a given node */
struct node *insert_after(struct node *);  /* insert after a given node */
struct node *delete_beg(struct node *);    /* delete at the beginning */
struct node *delete_end(struct node *);    /* delete at the end */
struct node *delete_node(struct node *);   /* delete a node */
struct node *delete_after(struct node *);  /* delete all after a given node */
struct node *delete_list(struct node *);   /* delete list of nodes */
struct node *sort_list(struct node *);     /* sort linked list */

int main(int argc, char *argv[]) {
  int option;
  do {
    printf("* ****MAIN MENU * ****\n");
    printf("1 : Create a list\n");
    printf("2 : Display the list\n");
    printf("3 : Add a node at the beginning\n");
    printf("4 : Add a node at the end\n");
    printf("5 : Add a node before a given node\n");
    printf("6 : Add a node after a given node\n");
    printf("7 : Delete a node from the beginning\n");
    printf("8 : Delete a node from the end\n");
    printf("9 : Delete a given node\n");
    printf("10 : Delete a node after a given node\n");
    printf("11 : Delete the entire list\n");
    printf("12 : Sort the list\n");
    printf("13 : EXIT\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        start = create_ll(start);
        printf("LINKED LIST CREATED\n");
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
        start = delete_node(start);
        break;
      case 10:
        start = delete_after(start);
        break;
      case 11:
        start = delete_list(start);
        printf("LINKED LIST DELETED\n");
        break;
      case 12:
        start = sort_list(start);
        break;
    }
  } while (option != 13);

  return 0;
}
/**********************************************************
 * Create linked list
 *
 * if start is NULL pointer, a new node is the only node
 * else start is not NULL pointer, link a new node to the end of linked list
 **********************************************************/

struct node *create_ll(struct node *start) {
  struct node *new_node, *ptr;
  int num;
  printf("Enter -1 to end\n");

  printf("Enter the data: ");
  scanf("%d", &num);

  while (num != -1) {
    /* create a new node and assign value to node->data
       (But the new node is not linked yet.)
    */
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    /* if no elems or no linked list */
    if (start == NULL) {
      start = new_node;
    }
    /* if one more elems in linked list */
    else {
      ptr = start;  // using temporary pointer for traversal
      while (ptr->next != NULL) ptr = ptr->next;  // got to the end
      ptr->next = new_node;  // add a new node at the end of linked list
    }

    printf("Enter the data : ");
    scanf("%d", &num);
  }
  return start;
}

/**********************************************************
 * Display all
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

/**********************************************************
 * Insert a new node at the beginning of linked list
 **********************************************************/

struct node *insert_beg(struct node *start) {
  /* data to be inserted */
  int num;
  printf("Enter the data: ");
  scanf("%d", &num);

  /* create a memory space for the new node */
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));

  /* add the new node at the beginning of linked list
    i) assign a value to node's data
    ii) link a new node at the end of the linked list
    iii) move 'start' pointer
  */
  new_node->data = num;
  new_node->next = start;
  start = new_node;

  return start;
}

/**********************************************************
 * Insert a new node at the end of linked list
 **********************************************************/

struct node *insert_end(struct node *start) {
  int num;
  printf("Enter the data: ");
  scanf("%d", &num);

  /* initializing a new node with data */
  struct node *ptr, *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  new_node->next = NULL;

  /* searching for the end
    - 'ptr' is a pointer for traversal
    - move 'ptr' to the node at the end of linked list
    - add a new node there
  */
  ptr = start;
  while (ptr->next != NULL) ptr = ptr->next;
  ptr->next = new_node;

  return start;
}

/**********************************************************
 * Insert a new node before a given node
 - To insert a new node between two nodes,
   we should know pointers pointing both before and after the new node.
 **********************************************************/

struct node *insert_before(struct node *start) {
  int num, val;
  printf("Enter the data: ");
  scanf("%d", &num);
  printf("Enter the value before which the data has to be inserted: ");
  scanf("%d", &val);

  /* initializing a new node with a value */
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* searching for the given node (for example, 40)

              node   node   node   node   node
              10     20     30     40     50
    start --> *  --> *  --> *  --> *  --> *  --> NULL
                           preptr  ptr
  */
  struct node *ptr, *preptr;
  ptr = start;
  preptr = ptr;
  while (ptr->data != val) {
    preptr = ptr;
    ptr = ptr->next;  // ptr points the given node
  }

  /* linking */
  preptr->next = new_node;
  new_node->next = ptr;

  return start;
}

/**********************************************************
 * Insert after a given node (for example, 30)

              node   node   node   node   node
              10     20     30     40     50
    start --> *  --> *  --> *  --> *  --> *  --> NULL
                           preptr  ptr
 **********************************************************/

struct node *insert_after(struct node *start) {
  int num, val;
  printf("Enter the data: ");
  scanf("%d", &num);
  printf("Enter the value after which the data has to be inserted: ");
  scanf("%d", &val);

  /* initializing a new node */
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  /* searching for the given node */
  struct node *ptr, *preptr;
  ptr = start;
  preptr = ptr;                  // TODO: this for 1-element linked list
  while (preptr->data != val) {  // This is the key
    preptr = ptr;                // preptr points the given node
    ptr = ptr->next;
  }

  preptr->next = new_node;
  new_node->next = ptr;
  return start;
}

/**********************************************************
 * Delete a node at the beginning
  - TODO: Where would the data be moved to?
 **********************************************************/

struct node *delete_beg(struct node *start) {
  struct node *ptr;
  ptr = start;  // ptr is needed for freeing memory space
  start = start->next;
  free(ptr);  // required for preventing memory loss
  return start;
}

/**********************************************************
 * Delete a node at the end
 **********************************************************/

struct node *delete_end(struct node *start) {
  struct node *ptr, *preptr;
  /* find */
  ptr = start;
  while (ptr->next != NULL) {
    preptr = ptr;
    ptr = ptr->next;  // ptr points the end node
  }

  preptr->next = NULL;
  free(ptr);

  return start;
}

/**********************************************************
 * Delete a specific node
 * - at the beginning
 * - at the end
 * - inbetween
 **********************************************************/

struct node *delete_node(struct node *start) {
  int val;
  printf("Enter the value of the node which has to be deleted: ");
  scanf("%d", &val);

  struct node *ptr, *preptr;
  ptr = start;

  /* TODO: if no elem in linked list */
  if (ptr == NULL) printf("Empty!\n");

  /* if only one node */
  if (ptr->data == val) {
    start = delete_beg(start);
    return start;
  }
  /* if two more nodes */
  else {
    while (ptr->data != val) {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
  }
}

/**********************************************************
 * Delete a node after a given node
 **********************************************************/

struct node *delete_after(struct node *start) {
  struct node *ptr, *preptr;
  int val;
  printf("Enter the value after which the node has to deleted: ");
  scanf("%d", &val);

  /* searching for preptr */
  ptr = start;
  preptr = ptr;
  while (preptr->data != val) {
    preptr = ptr;
    ptr = ptr->next;
  }

  /* excising, linking, and freeing */
  preptr->next = ptr->next;
  free(ptr);
  return start;
}

/**********************************************************
 * Delete whole linked list
 **********************************************************/

struct node *delete_list(struct node *start) {
  struct node *ptr;
  if (start != NULL) {
    ptr = start;
    while (ptr != NULL) {
      printf("%d is to be deleted next", ptr->data);
      start = delete_beg(ptr);
      ptr = start;
    }
  }
  return start;
}

/**********************************************************
 * Sorting list
 * TODO: Which sorting algorithm is this?
 *       Is this algorithm efficient?
 *
 * index     0  1  2  3  4  5  7  8  9  10 ...
 * smallest  *
 *              *
 *                 * ---> proceeds with nested loop
 **********************************************************/

struct node *sort_list(struct node *start) {
  struct node *ptr1, *ptr2;
  int temp;

  ptr1 = start;
  while (ptr1->next != NULL) {
    ptr2 = ptr1->next;
    while (ptr2 != NULL) {
      if (ptr1->data > ptr2->data) {
        temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
      }
      ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
  return start;  // Had to be added
}