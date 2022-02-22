/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 2.
Write a program that reads an array of 100 integers.
Display all the pairs of elements whose sum is 50.

TODO: How can I improve this?
      BigO(n^2) - nested for loops
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 5
#define SUM 50

int main() {
  int arr[LEN];
  for (int i = 0; i < LEN; i++) {
    printf("Enter integer number %d: ", i);
    scanf("%d", &arr[i]);
  }

  printf("Your array is: \n");
  for (int i = 0; i < LEN; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      if (i == j) continue;
      if (arr[i] + arr[j] == SUM) {
        printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
      }
    }
  }

  return 0;
}
