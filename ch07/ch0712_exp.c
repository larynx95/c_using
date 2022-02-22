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
    Evaluation of a postfix expression (Program example 7)
    Conversion of an infix expression into a prefix expression
    (Program example 8)
    Evaluation of a prefix expression (Program example 9)
  7.7.4 Recursion (Program example 10)
    Greatest common divisor (Program example 11)
    Find exponents (Program example 12)
*/

/*
Programming Example
12. Write a program to calculate exp(x,y) using recursive functions.

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int exp_rec(int, int);

int main() {
  int num1, num2, res;
  printf("Enter the two numbers: ");
  scanf("%d %d", &num1, &num2);
  res = exp_rec(num1, num2);
  printf("RESULT = %d\n", res);
  return 0;
}

int exp_rec(int x, int y) {
  if (y == 0)
    return 1;
  else
    return (x * exp_rec(x, y - 1));
}