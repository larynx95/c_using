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
    do-while loop (Program example 6)
    for loop (Program example 7)
  1.9.3 Break and continue statements
    break statement
    continue statement
1.10 Functions
  1.10.1 Why are functionis needed?
  1.10.2 Using functions
    Function declaration
    Function definition
    Function call (Program example 8)
*/

/*
Programming Example 8.
Write a program to find whether a number is even or odd using functions.
*/

#include <stdio.h>

int evenodd(int);

int main() {
  int num, flag;
  printf("\n Enter the number : ");
  scanf("%d", &num);
  flag = evenodd(num);
  if (flag == 1)
    printf("\n %d is EVEN", num);
  else
    printf("\n %d is ODD", num);
  return 0;
}

int evenodd(int a) {
  if (a % 2 == 0)
    return 1;
  else
    return 0;
}