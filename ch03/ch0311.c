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
  3.5.4 Merging two arrays (Program example 11 ~ 12)
******************************************************************************/

/*
Prpgram Example 11.
Write a program to merge two unsorted arrays. (not sorted)

# Plan
arr1:         {1,4}
arr2:         {2,0}
merged array: {1,4,2,0}
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int arr1[10], arr2[10], arr3[20];
  int i, n1, n2, m, index = 0;

  // first array
  printf("Enter the number of elements in array1: ");
  scanf("%d", &n1);

  printf("Enter the elements of the first array\n");
  for (i = 0; i < n1; i++) {
    printf("arr1[%d] = ", i);
    scanf("%d", &arr1[i]);
  }

  // second array
  printf("Enter the number of elements in array2: ");
  scanf("%d", &n2);

  printf("Enter the elements of the second array\n");
  for (i = 0; i < n2; i++) {
    printf("arr2[%d] = ", i);
    scanf("%d", &arr2[i]);
  }

  // merging
  m = n1 + n2;
  for (i = 0; i < n1; i++) {
    arr3[index] = arr1[i];
    index++;
  }
  for (i = 0; i < n2; i++) {
    arr3[index] = arr2[i];
    index++;
  }

  // printing the result
  printf("The merged array is");
  for (i = 0; i < m; i++) printf("\narr[%d] = %d", i, arr3[i]);

  return 0;
}