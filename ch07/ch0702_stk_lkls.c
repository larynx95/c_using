/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure
7.1 Introduction
7.2 Array refresentation of stacks
7.3 Operations on a stack
  7.3.1 Push operation
  7.3.2 pop operation
  7.3.3 Peek operation (Program example 1)
7.4 Linked representation of stacks
7.5 Operations ona linked stack
  7.5.1 Push operation
  7.5.2 Pop operation (Program example 2)
*/

/*
Programming Example
2. Write a program to implement a linked stack.

TODO: Advantage of this linked stack?
      == Advantage of llk over array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
  int data;
  struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

int main(int argc, char *argv[]) {
  int val, option;
  do {
    printf("*****MAIN MENU*****\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PEEK\n");
    printf("4. DISPLAY\n");
    printf("5. EXIT\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter the number to be pushed on stack: ");
        scanf("%d", &val);
        top = push(top, val);
        break;
      case 2:
        top = pop(top);
        break;
      case 3:
        val = peek(top);
        if (val != -1)
          printf("The value at the top of stack is: %d\n", val);
        else
          printf("STACK IS EMPTY\n");
        break;
      case 4:
        top = display(top);
        break;
    }
  } while (option != 5);

  return 0;
}

/**********************************************************
 * push
 **********************************************************/

struct stack *push(struct stack *top, int val) {
  struct stack *new = malloc(sizeof(struct stack));
  new->data = val;
  /* linked list can't be fixed-sized.
     We don't have to check whether it is full.
  if (top == NULL) {
    new->next = NULL;
    top = new;
  } else {  // add node in front of lls
    new->next = top;
    top = new;
  }*/
  new->next = top;
  top = new;

  return top;
}

/**********************************************************
 * display
 **********************************************************/

struct stack *display(struct stack *top) {
  struct stack *ptr;
  ptr = top;
  if (top == NULL)
    printf("STACK IS EMPTY\n");
  else {
    while (ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
    }
  }
  printf("\n");
  return top;
}

/**********************************************************
 * pop
 * - check linked stack is empty (isNULL)
 * - memory deallocation
 **********************************************************/

struct stack *pop(struct stack *top) {
  struct stack *ptr;
  ptr = top;
  if (top == NULL)
    printf("!!WARNING!! STACK UNDERFLOW\n");  // empty
  else {
    top = top->next;
    printf("The value being deleted is: %d\n", ptr->data);
    /* without above line, poped node will vanish in vain */
    free(ptr);  // Don't forget this.
  }
  return top;
}

/**********************************************************
 * peek
 **********************************************************/

int peek(struct stack *top) {
  if (top == NULL)
    return -1;
  else
    return top->data;
}