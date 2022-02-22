/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 5.
Write a program to read two floating point numbers.
Add these numbers and assign the result to an integer.
Finally, display the value of all the three variables.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  float x, y;
  int result;
  printf("Enter two float numbers: ");
  scanf(" %f %f", &x, &y);
  result = x + y;
  printf("x: %.2f, y: %.2f, result: %d\n", x, y, result);

  return 0;
}
