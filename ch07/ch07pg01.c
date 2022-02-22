/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
1. Write a program to implement a stack using a linked list.

TODO: Using typedef

  // error
  typedef struct {
    int data;
    Node *next;
  } Node;

  // working
  typedef struct Node {
    int data;
    Node *next;
  } Node;
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* top = NULL;

struct Node* push(struct Node*, int);
struct Node* pop(struct Node*);
struct Node* display(struct Node*);

int main() {
  top = push(top, 100);
  top = push(top, 200);
  display(top);
  top = pop(top);
  top = pop(top);
  display(top);
  return 0;
}

struct Node* push(struct Node* top, int num) {
  struct Node* ptr;
  ptr = malloc(sizeof(struct Node));
  ptr->data = num;
  if (top == NULL) {
    ptr->next = NULL;
    top = ptr;
  } else {
    ptr->next = top;
    top = ptr;
  }
  return top;
}

/*
TODO: what if return int type?
*/
struct Node* pop(struct Node* top) {
  struct Node* ptr;
  ptr = top;
  int val;
  if (top == NULL) {
    printf("Stack is empty.\n");
    exit(EXIT_FAILURE);
  } else {
    val = top->data;
    top = top->next;
    free(ptr);
  }
  return top;
}

struct Node* display(struct Node* top) {
  struct Node* ptr;
  ptr = top;
  if (top == NULL)
    printf("stack is empty.\n");
  else {
    while (ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
  }
  printf("\n");
  return top;
}
