/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 6.
Write a program to read a floating point number.
Display the rightmost digit of the integral part of the number.

TODO: Is it possible to get the last digit of the "FLOAT" number?
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  float x;
  printf("Enter float number: ");
  scanf("%f", &x);

  int res = (int)x;
  printf("Answer: %d\n", res % 10);

  return 0;
}
