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
*/

/*
Programming Example 3.
Write a program to find whether a number is even or odd.
*/

#include <stdio.h>
#include <stdlib.h>

int is_even(int num);
int is_odd(int num);

int main() {
  /* without function */
  int a;
  printf("Enter the value of a: ");
  scanf("%d", &a);
  if (a % 2 == 0)
    printf("%d is even\n", a);
  else
    printf("%d is odd\n", a);

  /* with function */
  printf("10 is even: %d\n", is_even(10));
  printf("11 is odd: %d\n", is_odd(11));

  return 0;
}

int is_even(int num) { return num % 2 == 0; }
int is_odd(int num) { return num % 2 != 0; }
