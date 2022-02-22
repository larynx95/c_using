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
*/

/*
Programming Example 2. (p. 16)
Write a program to convert an integer into the corresponding floating point
number.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  float f_num;
  int i_num;
  system("clear");
  printf("Enter any integer: ");
  scanf("%d", &i_num);
  f_num = (float)i_num;
  printf("The floating point variant of %d is = %f\n", i_num, f_num);

  return 0;
}
