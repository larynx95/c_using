/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
3. Write a program to multiply every element of the linked list with 10.

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
ND* mult_slkls(ND* start);
ND* print_slkls(ND* start);

int main() {
  ND* start = NULL;
  int arr[] = {1, 2, 2, 3};
  for (int i = 0; i < SZ(arr); i++) {
    start = create_slkls(start, arr[i]);
  }
  start = mult_slkls(start);
  print_slkls(start);

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

ND* mult_slkls(ND* start) {
  ND* ptr = start;
  while (ptr != NULL) {
    ptr->data *= 2;
    ptr = ptr->next;
  }
  return start;
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