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
    Example of expressions using the precedence chart
*/

/*
* Keywords
  auto double int struct break else long case enum switch typedef char extern
  register return const continue default for float short union unsigned signed
  void goto sizeof do if static volatile while

* types
  Data Type Bytes Range Use
  -------------------------------------------------------------------------
  char      1     -128 to 127 To store characters
  int       2     -32768 to 32767 To store integer numbers
  float     4     3.4E-38 to 3.4E+38 To store floating point numbers
  double    8     1.7E-308 to 1.7E+308 To store big floating point numbers

  Data Type          Bytes Range
  -------------------------------------------------------------------------
  char               1     –128 to 127
  unsigned char      1     0 to 255
  signed char        1     –128 to 127
  int                2     –32768 to 32767
  unsigned int       2     0 to 65535
  signed int         2     –32768 to 32767
  short int          2     –32768 to 32767
  unsigned short int 2     0 to 65535
  signed short int   2     –32768 to 32767
  long int           4     –2147483648 to 2147483647
  unsigned long int  4     0 to 4294967295
  signed long int    4     –2147483648 to 2147483647
  float              4     3.4E–38 to 3.4E+38
  double             8     1.7E–308 to 1.7E+308
  long double       10     3.4E–4932 to 1.1E+4932

  Sequence  Purpose
  -------------------------------
  \a        Audible signal
  \b        Backspace
  \t        Tab
  \n        New line
  \v        Vertical tab
  \f        New page\Clear screen
  \r        Carriage return

  Type            Qualifying Input
  ---------------------------------------------------------
  %c              For single characters
  %d, %i          For integer values
  %e,%E,%f,%g,%G  For floating point numbers
  %o              For octal numbers
  %s              For a sequence of (string of) characters
  %u              For unsigned integer values
  %x,%X           For hexadecimal values

  Flags Description
  ---------------------------------------------------------
  –     Left–justify within the given field width
  +     Displays the data with its numeric sign (either + or –)
  #     Used to provide additional specifiers like o, x, X, 0, 0x, or 0X for
        octal and hexadecimal values respectively for values different than zero
  0     The number is left–padded with zeroes (0) instead of spaces

  Operation   Operator Syntax  Comment Result
  ----------------------------------------------
  Multiply    *        a * b   result = a * b 27
  Divide      /        a / b   result = a / b 3
  Addition    +        a + b   result = a + b 12
  Subtraction –        a – b   result = a – b 6
  Modulus     %        a % b   result = a % b 0   TODO: negative number??

  Operator Meaning                Example
  -----------------------------------------------
  <        Less than              3 < 5 gives 1
  >        Greater than           7 > 9 gives 0
  <=       Less than or equal to  100 <= 100 gives 1
  >=       Greater than equal to  50 >=100 gives 0

  Operator Meaning
  -----------------------------------------
  ==       Returns 1 if both operands are
           equal, 0 otherwise
  !=       Returns 1 if operands do not
           have the same value, 0 otherwise

  A  B  A && B  A || B  A ^ B
  ---------------------------
  0  0  0       0       0
  0  1  0       1       1
  1  0  0       1       1
  1  1  1       1       0

  Operator Example
  ------------------------------------------
  /=       float a=9.0; float b=3.0; a /= b;
  \=       int a= 9; int b = 3; a \= b;
  *=       int a= 9; int b = 3; a *= b;
  +=       int a= 9; int b = 3; a += b;
  –=       int a= 9; int b = 3; a –= b;
  &=       int a = 10; int b = 20; a &= b;
  ^=       int a = 10; int b = 20; a ^= b;
  <<=      int a= 9; int b = 3; a <<= b;
  >>=      int a= 9; int b = 3; a >>= b;

  Operator             Associativity
  ----------------------------------
  () [] . —>           left–to–right
  ----------------------------------
  ++(postfix)          right–to–left
  ––(postfix)
  ----------------------------------
  ++(prefix)           right–to–left
  ––(prefix)
  +(unary) – (unary)
  ! ~
  (type)
  *(indirection)
  &(address)
  sizeof
  ----------------------------------
  * / %                left–to–right
  + –                  left–to–right
  << >>                left–to–right
  < <=                 left–to–right
  > >=
  == !=                left–to–right
  &                    left–to–right
  ^                    left–to–right
  |                    left–to–right
  &&                   left–to–right
  ||                   left–to–right
  ?:                   right–to–left
  ----------------------------------
  =                    right–to–left
  += –=
  *= /=
  %= &=
  ^= |=
  <<= >>=
  ----------------------------------
  ,(comma)             left–to–right
*/

/*
Programming Example 1. (p. 15)
Write a program to calculate the area of a circle.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("cls");
  float radius;
  double area;

  printf("Enter the radius of the circle: ");
  scanf("%f", &radius);
  area = 3.14 * radius * radius;
  printf("Area = %.2lf", area);

  return 0;
}
