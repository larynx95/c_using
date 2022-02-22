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
*/

/*
Programming Example
11. Write a program to calculate the gcd of two numbers using recursive
functions.

*/

#include <stdio.h>

int gcd(int, int);

int main() {
  int num1, num2, res;
  printf("Enter the two numbers: ");
  scanf("%d %d", &num1, &num2);
  res = gcd(num1, num2);
  printf("gcd of %d and %d = %d", num1, num2, res);
  return 0;
}

int gcd(int x, int y) {
  int rem;
  rem = x % y;
  if (rem == 0)
    return y;
  else
    return (gcd(y, rem));
}