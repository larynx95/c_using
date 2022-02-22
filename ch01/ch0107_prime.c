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
*/

/*
Programming Example 7.
Write a program to determine whether a given number is a prime or a composite
number.

TODO: Are there more efficient algorithms?
*/

#include <stdio.h>

void get_primes(int limit);

int main() {
  /* simple algorithm */
  int flag = 0, i, num;
  system("clear");
  printf("Enter any number : ");
  scanf("%d", &num);
  for (i = 2; i < num / 2; i++) {
    if (num % i == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    printf("%d is a composite number", num);
  else
    printf("%d is a prime number", num);

  /* Sieve of Eratosthenes */
  get_primes(100);

  return 0;
}

/* Sieve of Eratosthenes
   https://www.sanfoundry.com/c-program-implement-sieve-eratosthenes-generate-prime-numbers/
*/
void get_primes(int limit) {
  unsigned long long int i, j;
  int *primes;
  int z = 1;

  primes = malloc(sizeof(int) * limit);

  for (i = 2; i < limit; i++) primes[i] = 1;

  for (i = 2; i < limit; i++)
    if (primes[i])
      for (j = i; i * j < limit; j++) primes[i * j] = 0;

  printf("\nPrime numbers in range 1 to 100 are: \n");
  for (i = 2; i < limit; i++)
    if (primes[i]) printf("%d ", i);
  printf("\n");

  free(primes);
}