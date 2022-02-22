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
Prpgram Example 4.
Write a program to find the second largest of n numbers using an array.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, n, arr[20], largest, second_large;
  system("clear");
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter the elements: ");
    scanf("%d", &arr[i]);
  }

  // finding largest integer
  largest = arr[0];
  for (i = 1; i < n; i++) {
    if (arr[i] > largest) largest = arr[i];
  }

  // finding second largest integer
  second_large = arr[1];
  for (i = 0; i < n; i++) {
    if (arr[i] != largest) {
      if (arr[i] > second_large) second_large = arr[i];
    }
  }
  printf("The numbers you entered are: ");
  for (i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\nThe largest of these numbers is: %d\n", largest);
  printf("The second largest of these numbers is: %d\n", second_large);

  return 0;
}