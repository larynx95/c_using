/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
7. Write a program to merge two linked lists. (singly linked list)

TODO: Review this code later.
*/

#include <stdio.h>
#include <stdlib.h>
#define SZ(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct ND {
  int data;
  struct ND* next;
} ND;

ND* create_slkls(ND* start, int val);
ND* print_slkls(ND* start);
ND* copy_slkls(ND* orig);
ND* merge_slkls(ND* ast, ND* bst);
void free_slkls(ND* start);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  ND* ast = NULL;
  int arr[] = {1, 2};
  for (int i = 0; i < SZ(arr); i++) {
    ast = create_slkls(ast, arr[i]);
  }
  print_slkls(ast);

  ND* bst = NULL;
  int brr[] = {3, 4};
  for (int i = 0; i < SZ(brr); i++) {
    bst = create_slkls(bst, brr[i]);
  }
  print_slkls(bst);

  ND* merged = merge_slkls(ast, bst);
  print_slkls(merged);

  return 0;
}

/**********************************************************
 * create (or append) linked list
 **********************************************************/

ND* create_slkls(ND* start, int val) {
  ND* new, *ptr;

  new = malloc(sizeof(ND));
  new->data = val;
  new->next = NULL;

  if (start == NULL) {
    start = new;
  } else {
    ptr = start;
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->next = new;
  }
  return start;
}

/**********************************************************
 * print linked list
 **********************************************************/

ND* print_slkls(ND* start) {
  ND* ptr;
  ptr = start;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
  return start;
}

/**********************************************************
 * free memory space
 **********************************************************/

void free_slkls(ND* start) {
  ND *ptr, *preptr;
  ptr = preptr = start;
  while (ptr->next != NULL) {
    ptr = ptr->next;
    free(preptr);
    preptr = ptr;
  }
}

/**********************************************************
 * merge two singly linked list
 * - this function can be improved (TODO: sort, reverse, filter)
 **********************************************************/

ND* merge_slkls(ND* ast, ND* bst) {
  ND *ptr, *new, *cur;
  new = NULL;

  if (ast == NULL) return bst;
  if (bst == NULL) return ast;

  ptr = ast;
  while (ptr != NULL) {
    if (new == NULL) {
      new = malloc(sizeof(ND));
      new->data = ptr->data;
      new->next = NULL;
      cur = new;
    } else {
      cur->next = malloc(sizeof(ND));
      cur = cur->next;
      cur->data = ptr->data;
    }
    ptr = ptr->next;
  }

  ptr = bst;
  while (ptr != NULL) {
    cur->next = malloc(sizeof(ND));
    cur = cur->next;
    cur->data = ptr->data;
    ptr = ptr->next;
  }

  cur->next = NULL;

  return new;
}
