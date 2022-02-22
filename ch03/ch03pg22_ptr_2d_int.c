/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 22.
Write a program to illustrate the use of a pointer
that points to a 2D array.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define R 2
#define C 2

int main() {
  /*
  int arr[R][C];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf(" %d", &arr[i][j]);
    }
  }
  */

  int arr[2][2] = {{0, 1}, {2, 3}};

  /* 1. single pointer */
  int *atr = &arr[0][0];

  printf("Print 2D array in a single line: \n");
  for (int i = 0; i < 2 * 2; i++) {
    printf("%d ", *(atr + i));
  }
  printf("\n\n");

  /* 2. array of pointers */
  int *btr[2];
  btr[0] = arr[0];  // TODO: Is this correct or not?
  btr[1] = arr[1];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", *(btr[i] + j));
    }
    printf("\n");
  }
  printf("\n");

  /* 3. pointer to array */
  int(*ctr)[2] = &arr[0];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%d ", *(*(ctr + i) + j));
    }
  }

  /* TODO: Is there any other approach? */

  return 0;
}
