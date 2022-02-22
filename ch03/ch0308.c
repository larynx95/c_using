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
  3.5.2 Onserting an element in an array (Example 3.3)
    Algorithm to insert an elem in the middle of an arr (Program example 7 ~ 8)
******************************************************************************/

/*
Prpgram Example 8.
Write a program to insert a number in an array that is already sorted in
ascending order.

TODO: There are many sorting algorithms.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int i, n, j, num, arr[10];
  printf("Enter the number of elements in the array (less than 10): ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }
  printf("Enter the number to be inserted : ");
  scanf("%d", &num);
  for (i = 0; i < n; i++) {
    if (arr[i] > num) {
      for (j = n - 1; j >= i; j--) arr[j + 1] = arr[j];
      arr[i] = num;
      break;
    }
  }
  n = n + 1;
  printf("The array after insertion of %d is : ", num);
  for (i = 0; i < n; i++) printf("\narr[%d] = %d", i, arr[i]);

  return 0;
}