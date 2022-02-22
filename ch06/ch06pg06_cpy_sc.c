/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
6. Write a program that copies a circular linked list.

# copying algorithms
- To which place do you can copy it to?
- Was the place mem-allocated?

*/

#include <stdio.h>
#include <stdlib.h>
#define SZ(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct ND {
  int data;
  struct ND* next;
} ND;

ND* create_sclkls(ND* start, int val);
ND* print_sclkls(ND* start);
ND* copy_sclkls(ND* orig);

int main() {
  /* creating a sclkls and print it */
  int arr[] = {1, 2, 3};
  ND* start = NULL;
  for (int i = 0; i < SZ(arr); i++) {
    start = create_sclkls(start, arr[i]);
  }
  // print_sclkls(start);

  /* test copying sclkls */
  ND* copied = copy_sclkls(start);
  print_sclkls(copied);

  return 0;
}

ND* create_sclkls(ND* start, int val) {
  ND* new = malloc(sizeof(ND));
  new->data = val;

  if (start == NULL) {
    new->next = new;
    start = new;
  } else {
    ND* ptr = start;
    while (ptr->next != start) ptr = ptr->next;
    ptr->next = new;
    new->next = start;
  }

  return start;
}

ND* print_sclkls(ND* start) {
  ND* ptr = start;
  if (ptr == NULL) {
    printf("NULL singly circular linked list.\n");
  } else if (ptr->next == start) {
    printf("%d (only one node)\n", ptr->data);
  } else {
    while (ptr->next != start) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
  }
  return start;
}

/**********************************************************
i. if NULL : return NULL
ii. Only one node : copy one node and return it.
iii. Two more nodes : iterate until origin pointer is NULL
  a. if target is NULL
  b. if target has only one node
  c. if target has two more nodes

TODO: Improve this function
TODO: Implement this function using double pointer
 **********************************************************/
ND* copy_sclkls(ND* from) {
  ND* new, *cur, *ptr;
  ptr = from;
  /* if origin is NULL
   - We don't need anything at all.
   - just return NULL.
  */
  if (ptr == NULL) return NULL;

  /* if origin has only one node
   - We don't have to use iteration.
   - We just need malloc once.
  */
  if (ptr->next == from) {
    new = malloc(sizeof(ND));
    new->data = ptr->data;
    new->next = new;
    return new;
  }

  /* if two more nodes in origin sclkls
   - pointer 'cur': for moving focus
   - pointer 'new': pointer for output sclkls
  */
  cur = new = NULL;
  while (ptr->next != from) {
    /* for the first time, initialize our target */
    if (new == NULL) {
      new = malloc(sizeof(ND));
      new->data = ptr->data;
      cur = new;
    }
    /* cuz there is one more node, we copy one by one
       Notice!
       - We first allocated memory, and then copied.
    */
    else {
      cur->next = malloc(sizeof(ND));
      cur = cur->next;
      cur->data = ptr->data;
    }
    ptr = ptr->next;
  }
  /* the last node is not copied
     so, we have to copy the last node manually
  */
  cur->next = malloc(sizeof(ND));
  cur = cur->next;
  cur->data = ptr->data;

  /* Finally, make our list circular */
  cur->next = new;

  return new;
}