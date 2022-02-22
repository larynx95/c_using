/* Data Structures Using C, 2Nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
8. Write a program to sort the values stored in a doubly circular linked list.
  (dclkls)

# Two approaches for traversal in doubly circular linked list
- forward and backward
- The result is the same on both cases.
- However, the displayed result depends on how you traverse.

*/

#include <stdio.h>
#include <stdlib.h>
#define SZ(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct Nd {
  int data;
  struct Nd* prev;
  struct Nd* next;
} Nd;

Nd* create_dclkls_forward(Nd* start, int val);
Nd* create_dclkls_backward(Nd* start, int val);
Nd* print_dclkls_forward(Nd* start);
Nd* print_dclkls_backward(Nd* start);
Nd* sort_dclkls_forward(Nd* start);
Nd* sort_dclkls_backward(Nd* start);

int main() {
  int arr[] = {5, 2, 1, 4, 3};
  Nd* start = NULL;

  int opt;
  do {
    printf("1. View forward sorting\n");
    printf("2. View backward sorting\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);

    switch (opt) {
      case 1:
        start = NULL;  // initialized to NULL
        for (int i = 0; i < SZ(arr); i++) {
          start = create_dclkls_forward(start, arr[i]);
        }
        print_dclkls_forward(start);
        start = sort_dclkls_forward(start);
        print_dclkls_forward(start);
        break;
      case 2:
        start = NULL;  // initialized to NULL
        for (int i = 0; i < SZ(arr); i++) {
          start = create_dclkls_backward(start, arr[i]);
        }
        print_dclkls_backward(start);
        start = sort_dclkls_backward(start);
        print_dclkls_backward(start);
        break;
      default:
        printf("\n");
        break;
    }
  } while (opt != 9);

  return 0;
}

/*
create a doubly circular linked list, forward
*/
Nd* create_dclkls_forward(Nd* start, int val) {
  Nd *ptr, *new;
  ptr = start;
  new = malloc(sizeof(Nd));
  new->data = val;

  /* if NULL */
  if (start == NULL) {
    new->prev = new;
    new->next = new;
    start = new;
  }
  /* if not empty */
  else {
    while (ptr->next != start) ptr = ptr->next;
    ptr->next = new;
    new->prev = ptr;
    new->next = start;
    start->prev = new;
  }
  return start;
}

/*
create a doubly circular linked list, backward
*/
Nd* create_dclkls_backward(Nd* start, int val) {
  Nd *ptr, *new;
  ptr = start;
  new = malloc(sizeof(Nd));
  new->data = val;

  /* if NULL */
  if (start == NULL) {
    new->prev = new;
    new->next = new;
    start = new;
  }
  /* if not NULL */
  else {
    while (ptr->prev != start) ptr = ptr->prev;
    ptr->prev = new;
    new->next = ptr;
    start->next = new;
    new->prev = start;
  }

  return start;
}

Nd* print_dclkls_forward(Nd* start) {
  Nd* ptr = start;
  while (ptr->next != start) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  /* print the last node */
  printf("%d\n", ptr->data);

  return start;
}

Nd* print_dclkls_backward(Nd* start) {
  Nd* ptr = start;
  while (ptr->prev != start) {
    printf("%d ", ptr->data);
    ptr = ptr->prev;
  }
  printf("%d\n", ptr->data);
  return start;
}

/**/
Nd* sort_dclkls_forward(Nd* start) {
  Nd* ptr = start;
  while (ptr->next != start) {
    for (Nd* cur = ptr->next; cur != start; cur = cur->next) {
      if (ptr->data > cur->data) {
        int temp = ptr->data;
        ptr->data = cur->data;
        cur->data = temp;
      }
    }
    ptr = ptr->next;
  }
  return start;
}

Nd* sort_dclkls_backward(Nd* start) {
  Nd* ptr = start;
  while (ptr->prev != start) {
    for (Nd* cur = ptr->prev; cur != start; cur = cur->prev) {
      if (ptr->data > cur->data) {
        int temp = ptr->data;
        ptr->data = cur->data;
        cur->data = temp;
      }
    }
    ptr = ptr->prev;
  }
  return start;
}

// TODO: Improve sorting algorithm.