/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
5. Write a program to input two stacks and compare their contents.

# How can they be compared?
- size (the number of elements)?
- order of elements?


TODO: array stack, linked stack
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int stkA[MAX];
int topA = -1;
int stkB[MAX];
int topB = -1;

void push(int *, int *, int);
void pop(int *, int *);
void peek(int *, int);

int compare_stack(int *, int *, int *, int *);

int main() {
  push(stkA, &topA, 10);
  push(stkA, &topA, 20);
  push(stkB, &topB, 10);
  push(stkB, &topB, 20);
  int res = compare_stack(stkA, &topA, stkB, &topB);
  printf("res: %d \n", res);

  return 0;
}

// TODO: What is stack comparing?
int compare_stack(int *stkA, int *topA, int *stkB, int *topB) {
  /* compare sizes */
  if (*topA != *topB) {
    printf("Sizes are different.\n");
    exit(EXIT_FAILURE);
  }

  /* compare each element */
  while (*topA != -1) {
    if (stkA[*topA--] != stkB[*topB--]) return 1;
  }
  return 0;
}

void push(int *stk, int *top, int val) {
  if (*top == MAX - 1) {
    printf("stack is full.\n");
    exit(EXIT_FAILURE);
  } else {
    stk[++(*top)] = val;
    printf("value is pushed successfully.\n");
  }
}

void pop(int *stk, int *top) {
  if (*top == -1) {
    printf("Stack is empty.\n");
    exit(EXIT_FAILURE);
  } else {
    *top--;
  }
}

void peek(int *stk, int top) {
  if (top == -1) {
    printf("Stack is empty.\n");
    exit(EXIT_FAILURE);
  } else {
    printf("peek: %d\n", stk[top]);
  }
}