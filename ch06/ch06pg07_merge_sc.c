/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
7. Write a program to merge two linked lists.

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
ND* merge_simple_sclkls(ND* ast, ND* bst);

int main() {
  ND *lst1, *lst2, *merged;
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

ND* merge_simple_sclkls(ND* ast, ND* bst) {
  /* if one of them is NULL */
  if (ast == NULL) return bst;
  if (bst == NULL) return ast;

  ND *result, *ptr, *cur;
  ptr = ast;
  while (ptr != NULL) {
  }

  return result;
}