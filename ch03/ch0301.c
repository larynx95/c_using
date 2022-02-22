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
  3.5.1 Traversing an array (Program example 1)
******************************************************************************/

/*
Prpgram Example 1.
Write a program to read and display n numbers using an array.
*/

#include <stdio.h>

int main() {
  /* declaration, then initialization */
  int i, n, arr[20];
  system("clear");
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  printf("The array elements: ");
  for (i = 0; i < n; i++) printf("\%d ", arr[i]);
  printf("\n");

  /* initialization during declaration */
  int iarr[5] = {1, 2, 3, 4, 5};
  printf("The array literal: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", iarr[i]);
  }

  return 0;
}

/*
* ARRAY DECAY
  - when passing array to a function as function argument,
    only the address of the array is passed
* array name and pointer
  - array name is not a pointer
  - two are not the same
* pointer arithmetics and array
* character/string array
*/