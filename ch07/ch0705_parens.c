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
7.7 Applications of stacks
  7.7.1 Reversing a list (Program example 4)
  7.7.2 Implementing parentheses checker (Program example 5)
*/

/*
Programming Example
5. Write a program to check nesting of parentheses using a stack.

# Algorithm
- Checking pairing of symbols
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
int top = -1;
int stk[MAX];
void push(char);
char pop();

void main() {
  char exp[MAX], temp;
  int i, flag = 1;
  printf("Enter an expression: ");
  gets(exp);

  for (i = 0; i < strlen(exp); i++) {
    /* push symbols to stack array */
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') push(exp[i]);

    if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
      if (top == -1)
        flag = 0;
      else {
        temp = pop();
        if (exp[i] == ')' && (temp == '{' || temp == '[')) flag = 0;
        if (exp[i] == '}' && (temp == '(' || temp == '[')) flag = 0;
        if (exp[i] == ']' && (temp == '(' || temp == '{')) flag = 0;
      }
  }
  if (top >= 0) flag = 0;
  if (flag == 1)
    printf("Valid expression\n");
  else
    printf("Invalid expression\n");
}

void push(char c) {
  if (top == (MAX - 1))
    printf("Stack Overflow\n");
  else {
    top = top + 1;
    stk[top] = c;
  }
}

char pop() {
  if (top == -1)
    printf("Stack Underflow\n");
  else
    return (stk[top--]);
}