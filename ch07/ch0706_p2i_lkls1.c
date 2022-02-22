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
  7.7.3 Evaluation of arithmetic expressions
    Polish notations
    Conversion of an infix expression into a postfix expression (Example 7.3)
    (Program example 6)
*/

/*
Programming Example (optional)
6. Write a program to convert an post expression
   into its equivalent infix notation.

  # https://scanftree.com/Data_Structure/postfix-to-infix
  # algorithm
  1. While there are input symbol left
  2. Read the next symbol from input.
  3. If the symbol is an operand
    Push it onto the stack.
  4. Otherwise,
    the symbol is an operator.
  5. If there are fewer than 2 values on the stack
    Show Error // input not sufficient values in the expression
  6. Else
    Pop the top 2 values from the stack.
    Put the operator, with the values as arguments and form a string.
    Encapsulate the resulted string with parenthesis.
    Push the resulted string back to stack.
  7. If there is only one value in the stack
    That value in the stack is the desired infix string.
  8. If there are more values in the stack
    Show Error // The user input has too many values

  # TODO: space, float
*/

#include <stdio.h>
#include <stdlib.h>

int top = 10;

struct node {
  char ch;
  struct node *next;
  struct node *prev;
} * stack[11];

typedef struct node node;

void push(node *str) {
  if (top <= 0)
    printf("Stack is Full ");
  else {
    stack[top] = str;
    top--;
  }
}

node *pop() {
  node *exp;
  if (top >= 10)
    printf("Stack is Empty ");
  else
    exp = stack[++top];
  return exp;
}

void convert(char exp[]) {
  node *op1, *op2;
  node *temp;
  int i;
  for (i = 0; exp[i] != '\0'; i++)
    if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z') {
      temp = (node *)malloc(sizeof(node));
      temp->ch = exp[i];
      temp->next = NULL;
      temp->prev = NULL;
      push(temp);
    } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' ||
               exp[i] == '/' || exp[i] == '^') {
      op1 = pop();
      op2 = pop();
      temp = (node *)malloc(sizeof(node));
      temp->ch = exp[i];
      temp->next = op1;
      temp->prev = op2;
      push(temp);
    }
}

void display(node *temp) {
  if (temp != NULL) {
    display(temp->prev);
    printf("%c", temp->ch);
    display(temp->next);
  }
}

int main() {
  char exp[50];
  system("clear");
  printf("Enter the postfix expression :");
  scanf("%s", exp);
  convert(exp);
  printf("\nThe Equivalant Infix expression is:");
  display(pop());
  printf("\n\n");

  return 0;
}
