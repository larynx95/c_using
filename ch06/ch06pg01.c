/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
1. Write a program that removes all nodes that have duplicate information.

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
void free_slkls(ND* start);
ND* del_nd(ND* start, int val);
ND* rem_dupl(ND* start);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  ND* start = NULL;
  int arr[] = {1, 2, 2, 3};
  for (int i = 0; i < SZ(arr); i++) {
    start = create_slkls(start, arr[i]);
  }
  // print(start);
  // start = del_nd(start, 2);
  start = rem_dupl(start);
  print_slkls(start);

  free_slkls(start);

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
 * delete a node from linked list
 **********************************************************/

ND* del_nd(ND* start, int val) {
  ND *preptr, *ptr;
  preptr = ptr = start;

  if (ptr->data == val) {
    start = NULL;
    free(ptr);
    return start;
  } else {
    while (ptr->data != val) {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
  }

  return start;
}

/**********************************************************
 * remove duplicates
 **********************************************************/

ND* rem_dupl(ND* start) {
  ND *preptr, *ptr;
  preptr = ptr = start;
  ptr = ptr->next;
  while (ptr->next != NULL) {
    if (preptr->data == ptr->data) {
      int val = ptr->data;
      ptr = ptr->next;
      del_nd(start, val);
    } else {
      preptr = preptr->next;
      ptr = ptr->next;
    }
  }

  return start;
}