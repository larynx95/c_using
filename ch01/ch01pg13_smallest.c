/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 13.
Write a program to find the smallest of three integers using functions
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  /* imperative solution */
  int arr[3];
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
    printf("Enter a integer: ");
    scanf(" %d", &arr[i]);
  }

  int smallest = arr[0];
  for (int i = 1; i < sizeof(arr) / sizeof(int); i++) {
    if (smallest > arr[i]) {
      smallest = arr[i];
    }
  }

  printf("smallest: %d\n", smallest);

  return 0;
}

/*

TODO:
1. What is the nest sorting algorithm?
2. How can we find the smallest and largest number in a array?
  - sorting first, then select the first element
  - any other algorithm?
*/