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
  Bitwise operator (TODO: very interesting!)
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
*/

/*
Bit Twiddling Hacks
http://graphics.stanford.edu/~seander/bithacks.html

What USEFUL bitwise operator code tricks should a developer know about? [closed]
https://stackoverflow.com/questions/1533131/what-useful-bitwise-operator-code-tricks-should-a-developer-know-about

TODO: Check this again later!!
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("cls");

  /* convert letter to lowercase
     OR by space => (x | ' ')
  */
  printf("%c %c\n", 'a' | ' ', 'A' | ' ');

  /* convert letter to uppercase
     AND by underline => (x & '_')
  */
  printf("%c %c\n", 'a' & '_', 'A' & '_');

  /* invert letter's case
     XOR by space => (x ^ ' ')
  */
  printf("%c %c\n", 'a' ^ ' ', 'A' ^ ' ');

  /* get letter's position in alphabet (uppercase only)
     AND by ? => (x & '?')
     XOR by @ => (x ^ '@')
  */
  printf("%d %d\n", 'C' & '?', 'Z' ^ '@');

  /* get letter's position in alphabet (lowercase only)
     XOR by backtick char(96), 0b1100000, 0x60 => (x ^ '`')
  */
  printf("%d %d\n", 'd' ^ '`', 'x' ^ '`');

  /* get the maximum integer */
  printf("%d %d %d\n", ~(1 << 31), (1 << 31) - 1, (1 << -1) - 1);

  /* get the minimum integer */
  printf("%d %d\n", 1 << 31, 1 << -1);

  /* get the maximum long */
  printf("%ld\n", ((long)1 << 127) - 1);

  /* multiplied by 2: n << 1 */
  int n = 2;
  printf("%d\n", n << 1);

  /* divided by 2: n >> 1 */
  n = 2;
  printf("%d\n", n >> 1);

  /* multiplied by the m-th power of 2: n << m */
  int m = 3;
  n = 2;
  printf("%d\n", n << m);

  /* divided by the m-th power of 2: n >> m */
  n = 8, m = 3;
  printf("%d\n", n >> m);

  /* check odd number: (n & 1) == 1 */
  n = 3;
  printf("%d\n", (n & 1) == 1);

  /* exchange two values */
  int a = 1;
  int b = 2;
  a ^= b;
  b ^= a;
  a ^= b;
  printf("a=%d b=%d\n", a, b);

  /* get absolute value: (n ^ (n >> 31)) - (n >> 31) */
  printf("%d\n", (-10 ^ (-10 >> 31)) - (-10 >> 31));

  /* get the max of two values: b & ((a-b) >> 31) | a & (~(a-b) >> 31); */
  a = 5, b = 15;
  printf("%d\n", b & ((a - b) >> 31) | a & (~(a - b) >> 31));

  /* get the min of two values */
  a = 5, b = 15;
  printf("%d\n", a & ((a - b) >> 31) | b & (~(a - b) >> 31));

  /* check whether both have the same sign: (x ^ y) >= 0 */
  int x = 10, y = -20;
  printf("%d\n", (x ^ y) >= 0);

  /* calculate 2^n: 2 << (n-1); */
  n = 2;
  printf("%d\n", 2 << (n - 1));

  /* modulo 2^n against m: m & (n - 1) */
  m = 15, n = 6;
  printf("%d\n", m & (n - 1));

  /* whether is factorial of 2: n > 0 ? (n & (n - 1)) == 0 : false */
  n = 100;
  printf("%d\n", n > 0 ? (n & (n - 1)) == 0 : 0);

  /* get the average: (x + y) >> 1 or ((x ^ y) >> 1) + (x & y) */
  x = 100, y = 200;
  printf("%d\n", ((x ^ y) >> 1) + (x & y));

  /* get the m-th bit of n (from low to high): (n >> (m-1)) & 1 */
  n = 0b001110, m = 2;  // from 1 not zero
  printf("%d\n", (n >> (m - 1)) & 1);

  /* set the m-th bit of n to 0 (from low to high): n & ~(1 << (m-1)) */
  n = 0b1100, m = 3;
  printf("%d\n", n & ~(1 << (m - 1)));

  /* n + 1: -~n */
  n = 100;
  printf("%d\n", -~n);

  /* n - 1: ~-n */
  n = 100;
  printf("%d\n", ~-n);

  return 0;
}
