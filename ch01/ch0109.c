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
  1.10.3 Passing parameters to functions
    Call by value
    Call by reference
1.11 Pointers
  1.11.1 Declaring pointer variables
  1.11.2 Pointer expressions and pointer arithmetic
  1.11.3 Null pointers
  1.11.4 Generic pointers (Program example 9)
  1.11.5 Pointer to Pointers
  1.11.6 Drawbacks of pointers
*/

/*
Programming Example 9.
Write a program to add two integers using pointers and functions.
*/

#include <stdio.h>

void sum(int *, int *, int *);
int cbv_change_arg(int arg);

int main() {
  /* call by value */
  int a = 100;  // a is not changed by cbv_change_arg() fx.
  printf("a: %d, cbv_change_arg(a): %d\n", a, cbv_change_arg(a));

  /* void (generic) pointer */
  int x = 10;
  char ch = 'A';
  void *gp;
  gp = &x;
  printf("Generic pointer points to the integer value = %d\n", *(int *)gp);
  gp = &ch;
  printf("Generic pointer now points to the character= %c\n", *(char *)gp);

  /* sum by pointer */
  int num1, num2, total;
  printf("Enter the first number : ");
  scanf("%d", &num1);
  printf("Enter the second number : ");
  scanf("%d", &num2);
  sum(&num1, &num2, &total);
  printf("Total = %d", total);

  return 0;
}

void sum(int *a, int *b, int *t) { *t = *a + *b; }

int cbv_change_arg(int arg) { return arg + 2; }