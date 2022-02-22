/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C
1.1 Introduction
  structure of a C program
1.2 Identifieres and keywords
  identifiers
  keywords
1.3 Basic data types
1.4 Variables and constants
  Numeric variables
  Character variables
  Declaring variables
  Initilaizing variables
  Constants
  Declaring constants
1.5 Writing the first C program
  Escape
  Using comments
  Standard header files
1.6 Input and output functions
  scanf(): width, modifier, type
  printf(): flag, width, precision, modifier, type
1.7 Operators and expressions
  Arithmetic operators
  Relational operators
  Equality operators
  Logical operators
    Logical AND(&&)
    Logical OR(||)
    Logical NOT(!)
  Unary operators
  Unary minus(-)
  Incremental operator(++) and decremental operator(--)
  Conditional operator
  Bitwise operator
    bitwise AND
    bitwise OR
    bitwise XOR(^)
    bitwise NOT(~)
    Shift operators(>>,<<)
  Assignment operators
  Comma operator
  `sizeof` operator
  Operator precedence chart
    Example of expressions using the precedence chart (Program example 1)
1.8 Type conversion and typecasting
  Type conversion
  Type casting (Program example 2)
1.9 Control statements
  1.9.1 Decision control statements
    if statement
    if-else statement (Program example 3)
    if-else-if statement
    switch-case statement
      Advantages of using a switch-case statement (Program example 4)
  1.9.2 Iterative statements
    while loop (Program example 5)
*/

/*
Programming Example 5.
Write a program to calculate the sum of numbers from m to n .
*/

#include <stdio.h>
#include <stdlib.h>

int sum_rec(int m, int n);

int main() {
  int n, m, i, sum = 0;
  printf("Enter the value of m : ");
  scanf("%d", &m);
  i = m;
  printf("Enter the value of n : ");
  scanf("%d", &n);

  while (i <= n) {
    sum = sum + i;
    i = i + 1;
  }
  printf("The sum of numbers from %d to %d = %d\n", m, n, sum);

  /* recursive sum */
  printf("Recursive sum: %d\n", sum_rec(10, 15));

  return 0;
}

int sum_rec(int from, int to) {
  if (from >= to) return from;
  return from + sum_rec(from + 1, to);
}