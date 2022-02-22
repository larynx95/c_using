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
3.6 Passing arrays to functions
  3.6.1 Passing individual elements
    Passing data values
    passing addresses
  3.6.2 Passing the entire array (Program example 13)
******************************************************************************/

/*
Prpgram Example 12.
Write a program to merge two sorted arrays.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear");
  int arr1[10], arr2[10], arr3[20];
  int i, n1, n2, m, idx = 0;
  int idx_fst = 0, idx_snd = 0;

  /* the first array */
  printf("Enter the number of elements in array1: ");
  scanf("%d", &n1);
  printf("Enter the elements of the first array\n");
  for (i = 0; i < n1; i++) {
    printf("arr1[%d] = ", i);
    scanf("%d", &arr1[i]);
  }

  /* the second array */
  printf("Enter the number of elements in array2: ");
  scanf("%d", &n2);
  printf("Enter the elements of the second array\n");
  for (i = 0; i < n2; i++) {
    printf("arr2[%d] = ", i);
    scanf("%d", &arr2[i]);
  }

  /* KEY CONCEPT: compare, sort, and merge */
  m = n1 + n2;
  while (idx_fst < n1 && idx_snd < n2) {
    if (arr1[idx_fst] < arr2[idx_snd]) {
      arr3[idx] = arr1[idx_fst];
      idx_fst++;
    } else {
      arr3[idx] = arr2[idx_snd];
      idx_snd++;
    }
    idx++;
  }

  /* if elements of the first array are over and the second array has some
     elements */
  if (idx_fst == n1) {
    while (idx_snd < n2) {
      arr3[idx] = arr2[idx_snd];
      idx_snd++;
      idx++;
    }
  }

  /* if elements of the second array are over and the first array has some
     elements */
  else if (idx_snd == n2) {
    while (idx_fst < n1) {
      arr3[idx] = arr1[idx_fst];
      idx_fst++;
      idx++;
    }
  }

  /* printing the result */
  printf("The merged array is\n");
  for (i = 0; i < m; i++) printf("arr[%d] = %d\n", i, arr3[i]);

  return 0;
}