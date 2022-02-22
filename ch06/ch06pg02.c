/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
2. Write a program to print the total number of occurrences of a given item in
the linked list.

TODO: Implement this with headed linked list

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
int count_slkls(ND* start);

int main() {
  ND* start = NULL;
  int arr[] = {1, 2, 2, 3};
  for (int i = 0; i < SZ(arr); i++) {
    start = create_slkls(start, arr[i]);
  }
  printf("The number of nodes in lkls: %d\n", count_slkls(start));
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

int count_slkls(ND* start) {
  int acc = 0;
  ND* ptr = start;

  while (ptr != NULL) {
    acc++;
    ptr = ptr->next;
  }

  return acc;
}