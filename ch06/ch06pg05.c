/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
5. Write a program that prints whether the given linked list is sorted (in
ascending order) or not.

TODO: Is there more efficient aogorithm?

*/

#include <stdio.h>
#include <stdlib.h>
#define SZ(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct ND {
  int data;
  struct ND* next;
} ND;

ND* create_slkls(ND* start, int val);
void free_slkls(ND* start);
ND* print_slkls(ND* start);
int issorted(ND* start);

int main() {
  ND* start = NULL;
  int arr[] = {1, 2, 3, 4};
  for (int i = 0; i < SZ(arr); i++) {
    start = create_slkls(start, arr[i]);
  }
  print_slkls(start);
  printf("slkls is sorted? %s\n", issorted(start) ? "true" : "false");

  free_slkls(start);

  return 0;
}

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

void free_slkls(ND* start) {
  ND *ptr, *preptr;
  ptr = preptr = start;
  while (ptr->next != NULL) {
    ptr = ptr->next;
    free(preptr);
    preptr = ptr;
  }
}

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

int issorted(ND* start) {
  ND *ptr, *preptr;
  preptr = ptr = start;
  ptr = ptr->next;
  while (ptr->next != NULL) {
    if (preptr->data > ptr->data) return 0;
    preptr = preptr->next;
    ptr = ptr->next;
  }
  return 1;
}