/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 24.
Write a program to delete all the duplicate entries from an array of n integers.

TODO: Find more efficient algorithm!
******************************************************************************/

// https://codeforwin.org/2015/07/c-program-to-delete-duplicate-elements-from-array.html
#include <stdio.h>

#define MAX_SIZE 5  // Maximum size of the array

int main() {
  int arr[MAX_SIZE];  // Declares an array of size 100
  int size;           // Total number of elements in array
  int i, j, k;        // Loop control variables

  /* Input size of the array */
  printf("Enter size of the array: ");
  scanf("%d", &size);

  /* Input elements in the array */
  printf("Enter elements in array: ");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  /*
   * Find duplicate elements in array
   */
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      /* If any duplicate found */
      if (arr[i] == arr[j]) {
        /* Delete the current duplicate element */
        for (k = j; k < size; k++) {
          arr[k] = arr[k + 1];
        }

        /* Decrement size after removing duplicate element */
        size--;

        /* If shifting of elements occur then don't increment j */
        j--;
      }
    }
  }

  /*
   * Print array after deleting duplicate elements
   */
  printf("\nArray elements after deleting duplicates : ");
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}