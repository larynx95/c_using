/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure
7.1 Introduction
7.2 Array refresentation of stacks
7.3 Operations on a stack
  7.3.1 Push operation
  7.3.2 pop operation
  7.3.3 Peek operation (Program example 1)
*/

/*
Programming Example
1. Write a program to perform Push, Pop, and Peek operations on a stack.

* stack
  - We can't access to each elem by index-based approach in stack.
  - Stack is not index-based database.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3           // Altering this value changes size of stack created
int st[MAX], top = -1;  // top is global variable

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

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
        printf("Enter the number to be pushed on stack: \n");
        scanf("%d", &val);
        push(st, val);
        break;
      case 2:
        val = pop(st);
        if (val != -1) printf("The value deleted from stack is: %d\n", val);
        break;
      case 3:
        val = peek(st);
        if (val != -1) printf("The value stored at top of stack is: %d\n", val);
        break;
      case 4:
        display(st);
        break;
    }
  } while (option != 5);

  return 0;
}

/**********************************************************
 * push
 **********************************************************/

void push(int st[], int val) {
  if (top == MAX - 1) {
    /* top == the last index of stack (array) */
    printf("stack overflow\n");
  } else {
    /* there's some free space, so we can push more */
    top++;
    st[top] = val;
  }
}

/**********************************************************
 * pop
 **********************************************************/

int pop(int st[]) {
  int val;
  if (top == -1) {
    /* stack is empty */
    printf("stack underflow\n");
    return EXIT_FAILURE;  // -1
  } else {
    val = st[top];
    top--;
    return val;
  }
}

/**********************************************************
 * display: display all data in stack (array)
 **********************************************************/

void display(int st[]) {
  int i;
  if (top == -1)
    printf("STACK IS EMPTY\n");
  else {
    for (i = top; i >= 0; i--) printf("%d ", st[i]);
    printf("\n");  // Added for pretty format
  }
}

/**********************************************************
 * peek: returns the top element in stack (array)
 **********************************************************/

int peek(int st[]) {
  if (top == -1) {
    printf("STACK IS EMPTY\n");
    return -1;
  } else
    return (st[top]);
}