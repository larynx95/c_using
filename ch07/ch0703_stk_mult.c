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
7.6 Multiple stacks (Program example 3)
*/

/*
Programming Example
3. Write a program to implement multiple stacks.

* Visualization
  (1)
  stack A --->     ...    <--- stack B
            top A      top B
  (2)
  stack A --->     ...    stack B --->
            top A                   top B
  (3)
     <---  stack A  ...    <----  stack B
  top A                  top B

  TODO: Implement these multi-stacks later.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int stack[MAX], topA = -1, topB = MAX;
/* stack A grows rightward, stack b grows leftward */

void pushA(int val);
int popA();
void display_stackA();
void pushB(int val);
int popB();
void display_stackB();

/**********************************************************
 * main function
 **********************************************************/

void main() {
  int option, val;
  system("clear");
  do {
    printf("*****MENU*****");
    printf("1. PUSH IN STACK A");
    printf("2. PUSH IN STACK B");
    printf("3. POP FROM STACK A");
    printf("4. POP FROM STACK B");
    printf("5. DISPLAY STACK A");
    printf("6. DISPLAY STACK B");
    printf("7. EXIT");
    printf("Enter your choice");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter the value to push on Stack A : ");
        scanf("%d", &val);
        pushA(val);
        break;
      case 2:
        printf("Enter the value to push on Stack B : ");
        scanf("%d", &val);
        pushB(val);
        break;
      case 3:
        val = popA();
        if (val != -999) printf("The value popped from Stack A = %d", val);
        break;
      case 4:
        val = popB();
        if (val != -999) printf("The value popped from Stack B = %d", val);
        break;
      case 5:
        printf("The contents of Stack A are : \n");
        display_stackA();
        break;
      case 6:
        printf("The contents of Stack B are : \n");
        display_stackB();
        break;
    }
  } while (option != 7);
}

/**********************************************************
 * pushA
 **********************************************************/

void pushA(int val) {
  if (topA == topB - 1) /* when two tops meet at a one index */
    printf("overflow");
  else {
    topA += 1;
    stack[topA] = val;
  }
}

/**********************************************************
 * popA
 **********************************************************/

int popA() {
  int val;
  if (topA == -1) {
    printf("underflow");
    val = -999; /* TODO: What is this? */
  } else {
    val = stack[topA];
    topA--;
  }
  return val;
}

/**********************************************************
 * display_stack
 **********************************************************/

void display_stackA() {
  int i;
  if (topA == -1)
    printf("Stack A is Empty");
  else {
    for (i = topA; i >= 0; i--) printf("\t %d", stack[i]);
    /* TODO: Is this right? */
  }
}

/**********************************************************
 * pushB
 **********************************************************/

void pushB(int val) {
  if (topB - 1 == topA)
    printf("OVERFLOW");
  else {
    topB -= 1;
    stack[topB] = val;
  }
}

/**********************************************************
 * popB
 **********************************************************/

int popB() {
  int val;
  if (topB == MAX) {
    printf("UNDERFLOW");
    val = -999;
  } else {
    val = stack[topB];
    topB++;
  }
}

/**********************************************************
 * display_stackB
 **********************************************************/

void display_stackB() {
  int i;
  if (topB == MAX)
    printf("Stack B is Empty");
  else {
    for (i = topB; i < MAX; i++) printf("\t %d", stack[i]);
  }
}