/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays
3.1 Introduction
3.2 Declaration of arrays
3.3 Accessing the elements of an array
  3.3.1 Calculating the address of array elements (Example 3.1)
  3.3.2 Calculating the length of an array (Example 3.2)
3.4 Storing values in arrays
  Initializing arrays during declaration
  Inputting values from the keyboard
  Assigning values to individual elements
3.5 Operations on arrays
  3.5.1 Traversing an array (Program example 1 ~ 6)
******************************************************************************/

/*
Program Example 2.
Write a program to find the mean of n numbers using arrays.
*/

#include <stdio.h>

int main() {
  /* int array */
  int i, n, arr[20], sum = 0;
  float mean = 0.0;
  system("clear");

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  for (i = 0; i < n; i++) sum += arr[i];
  mean = (float)sum / n;
  printf("The sum of the array elements = %d\n", sum);
  printf("The mean of the array elements = %.2f\n", mean);

  /* character array */
  char carr[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

  // printf() with %s type specifier
  printf("%s\n", carr);

  // printf() with for-loop
  for (int i = 0; i < 6; i++) {
    printf("%c", carr[i]);
  }
  printf("\n");

  // printf() with pointer
  char* ptr = carr;
  while (*ptr) {
    printf("%c", *ptr);
    ptr++;
  }

  return 0;
}