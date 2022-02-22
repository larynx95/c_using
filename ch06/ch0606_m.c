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
6.5 Circular doubly linked lists
  6.5.1 Inserting a new node in a circular doubly linked list
    Inserting a node at the beginning of a circular doubly linked list
    Inserting a node at the end of a circular doubly linked list
  6.5.2 Deleting a node from a circular doubly linked list
    Deleting the first node from a circular doubly linked list
    Deleting the last node from a circular doubly linked list
    (Program example 4)
6.6 Header linked lists (Program example 5)
6.7 Multi-linked lists
6.8 Applications of linked lists
  6.8.1 Polynomial representation (Program example 6)
*/

/*
6. Write a program to store a polynomial using linked list. Also, perform
addition and subtraction on two polynomials.
*/

#include <conio.h>
#include <malloc.h>
#include <stdio.h>

struct node {
  int num;
  int coeff;
  struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;
struct node *last3 = NULL;
struct node *create_poly(struct node *);
struct node *display_poly(struct node *);
struct node *add_poly(struct node *, struct node *, struct node *);
struct node *sub_poly(struct node *, struct node *, struct node *);
struct node *add_node(struct node *, int, int);

int main() {
  int option;
  clrscr();
  do {
    printf("\n******* MAIN MENU *******");
    printf("\n 1. Enter the first polynomial");
    printf("\n 2. Display the first polynomial");
    printf("\n 3. Enter the second polynomial");
    printf("\n 4. Display the second polynomial");
    printf("\n 5. Add the polynomials");
    printf("\n 6. Display the result");
    printf("\n 7. Subtract the polynomials");
    printf("\n 8. Display the result");
    printf("\n 9. EXIT");
    printf("\n\n Enter your option : ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        start1 = create_poly(start1);
        break;
      case 2:
        start1 = display_poly(start1);
        break;
      case 3:
        start2 = create_poly(start2);
        break;
      case 4:
        start2 = display_poly(start2);
        break;
      case 5:
        start3 = add_poly(start1, start2, start3);
        break;
      case 6:
        start3 = display_poly(start3);
        break;
      case 7:
        start4 = sub_poly(start1, start2, start4);
        break;
      case 8:
        start4 = display_poly(start4);
        break;
    }
  } while (option != 9);
  getch();
  return 0;
}

struct node *create_poly(struct node *start) {
  struct node *new_node, *ptr;
  int n, c;
  printf("\n Enter the number : ");
  scanf("%d", &n);
  printf("\t Enter its coefficient : ");
  scanf("%d", &c);
  while (n != –1) {
    if (start == NULL) {
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->num = n;
      new_node->coeff = c;
      new_node->next = NULL;
      start = new_node;
    } else {
      ptr = start;
      while (ptr->next != NULL) ptr = ptr->next;
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node->num = n;
      new_node->coeff = c;
      new_node->next = NULL;
      ptr->next = new_node;
    }
    printf("\n Enter the number : ");
    scanf("%d", &n);
    if (n == –1) break;
    printf("\t Enter its coefficient : ");
    scanf("%d", &c);
  }
  return start;
}

struct node *display_poly(struct node *start) {
  struct node *ptr;
  ptr = start;
  while (ptr != NULL) {
    printf("\n%d x %d\t", ptr->num, ptr->coeff);
    ptr = ptr->next;
  }
  return start;
}

struct node *add_poly(struct node *start1, struct node *start2,
                      struct node *start3) {
  struct node *ptr1, *ptr2;
  int sum_num, c;
  ptr1 = start1, ptr2 = start2;
  while (ptr1 != NULL && ptr2 != NULL) {
    if (ptr1->coeff == ptr2->coeff) {
      sum_num = ptr1->num + ptr2->num;
      start3 = add_node(start3, sum_num, ptr1->coeff);
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    } else if (ptr1->coeff > ptr2->coeff) {
      start3 = add_node(start3, ptr1->num, ptr1->coeff);
      ptr1 = ptr1->next;
    } else if (ptr1->coeff < ptr2->coeff) {
      start3 = add_node(start3, ptr2->num, ptr2->coeff);
      ptr2 = ptr2->next;
    }
  }
  if (ptr1 == NULL) {
    while (ptr2 != NULL) {
      start3 = add_node(start3, ptr2->num, ptr2->coeff);
      ptr2 = ptr2->next;
    }
  }
  if (ptr2 == NULL) {
    while (ptr1 != NULL) {
      start3 = add_node(start3, ptr1->num, ptr1->coeff);
      ptr1 = ptr1->next;
    }
  }
  return start3;
}

struct node *sub_poly(struct node *start1, struct node *start2,
                      struct node *start4) {
  struct node *ptr1, *ptr2;
  int sub_num, c;
  ptr1 = start1, ptr2 = start2;
  do {
    if (ptr1->coeff == ptr2->coeff) {
      sub_num = ptr1->num – ptr2->num;
      start4 = add_node(start4, sub_num, ptr1->coeff);
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    } else if (ptr1->coeff > ptr2->coeff) {
      start4 = add_node(start4, ptr1->num, ptr1->coeff);
      ptr1 = ptr1->next;
    } else if (ptr1->coeff < ptr2->coeff) {
      start4 = add_node(start4, ptr2->num, ptr2->coeff);
      ptr2 = ptr2->next;
    }
  } while (ptr1 != NULL || ptr2 != NULL);
  if (ptr1 == NULL) {
    while (ptr2 != NULL) {
      start4 = add_node(start4, ptr2->num, ptr2->coeff);
      ptr2 = ptr2->next;
    }
  }
  if (ptr2 == NULL) {
    while (ptr1 != NULL) {
      start4 = add_node(start4, ptr1->num, ptr1->coeff);
      ptr1 = ptr1->next;
    }
  }
  return start4;
}

struct node *add_node(struct node *start, int n, int c) {
  struct node *ptr, *new_node;
  if (start == NULL) {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->num = n;
    new_node->coeff = c;
    new_node->next = NULL;
    start = new_node;
  } else {
    ptr = start;
    while (ptr->next != NULL) ptr = ptr->next;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->num = n;
    new_node->coeff = c;
    new_node->next = NULL;
    ptr->next = new_node;
  }
  return start;
}
