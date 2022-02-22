/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 24.
Write a program to add two floating point numbers using pointers and functions.
*/

#include <stdio.h>
#include <stdlib.h>

float fadd(float *, float *);

int main() {
  printf("Enter two float numbers: ");
  float an, bn;
  scanf(" %f %f", &an, &bn);

  printf("Sum of two float numbers: %.2f\n", fadd(&an, &bn));

  return 0;
}

float fadd(float *an, float *bn) {
  // dereferencing
  return *an + *bn;
}