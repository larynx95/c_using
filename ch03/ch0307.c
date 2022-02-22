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
Prpgram Example 7.
Write a program to insert a number at a given location in an array.
(not change the value of arr[i], but add new element)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int i, n, num, pos, arr[10];

  // the number of elements in the array
  printf("Enter the number of elements in the array : ");
  scanf("%d", &n);

  // get elements from user input
  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  // value and index
  printf("Enter the number to be inserted : ");
  scanf("%d", &num);
  printf("Enter the position at which the number has to be added : ");
  scanf("%d", &pos);

  // TODO: Can the size of array be changed?
  for (i = n - 1; i >= pos; i--) arr[i + 1] = arr[i];
  arr[pos] = num;
  n = n + 1;

  printf("The array after insertion of %d is : ", num);
  for (i = 0; i < n; i++) printf("\narr[%d] = %d", i, arr[i]);

  return 0;
}