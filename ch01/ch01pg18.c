/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 18.
Write a program to add three floating point numbers.
The result should contain only two digits after the decimal.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  float arr[3];
  float total = 0;
  for (int i = 0; i < sizeof(arr) / sizeof(float); i++) {
    printf("Enter float number (%d): ", i);
    scanf(" %f", &arr[i]);
    total += arr[i];
  }

  printf("Total: %.2f\n", total);

  return 0;
}
