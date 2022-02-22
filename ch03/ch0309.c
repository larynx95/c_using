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
  3.5.3 Deleting an element from an array (Example 3.4)
    Algorithm to delete an elem from the middle of an array
    (Program example 9 ~ 10)
******************************************************************************/

/*
Prpgram Example 9.
Write a program to delete a number from a given location in an array.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int i, n, pos, arr[10];
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  /* add elements */
  for (i = 0; i < n; i++) {
    printf("arr[%d] = ", i);
    scanf("%d", &arr[i]);
  }

  /* the position of element to be deleted */
  printf("Enter the position from which the number has to be deleted: ");
  scanf("%d", &pos);

  // delete
  // TODO: exceeding the max index?
  //       Is this efficient?
  for (i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
  n--;

  // print result
  printf("The array after deletion is: \n");
  for (i = 0; i < n; i++) printf("arr[%d] = %d\n", i, arr[i]);

  return 0;
}