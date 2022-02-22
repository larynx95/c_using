/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
4. Write a program to implement a stack that stores names of students in the
class. (stack for strings, character arrays)

# TODO: Implement this exercise in different ways
  1) 2-d array
  2) array of pointers
  3) pointer array
  4) character pointer
  5) double pointer

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTK 10
#define MAXNAME

char *stk[MAXSTK];
int top = -1;

void push(int sz, char *name);
void pop();
void peek();

int main() {
  char name[3] = "ab";
  push(3, name);
  peek();
  push(3, "zz");
  peek();
  pop();

  peek();
  pop();
  peek();
  return 0;
}

void push(int sz, char *name) {
  if (top == MAXSTK - 1) {
    printf("Stack is full.\n");
  } else {
    char *ptr = malloc(sizeof(char) * sz);
    strcpy(ptr, name);
    stk[++top] = ptr;
  }
}

void pop() {
  if (top == -1) {
    printf("Stack is empty.\n");
    exit(EXIT_FAILURE);
  } else {
    char *ptr = stk[top];  // for deallocation
    top--;
    free(ptr);
  }
}

void peek() {
  if (top == -1) {
    printf("Stack is empty.\n");
    exit(EXIT_FAILURE);
  } else {
    printf("peek: %s\n", stk[top]);
  }
}
