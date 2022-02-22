/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 11.
Write a program to input the elements of a two-dimensional array.
Then from this array, make two arrays
(1) one that stores all odd elements of the two-dimensional array
(2) and the other that stores all even elements of the array.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void create_2d_arr(int, int, int (*)[LEN]);
void print_2d_arr(int, int, int (*)[LEN]);
void odd_2d_arr(int, int, int (*)[LEN]);
void even_2d_arr(int, int, int (*)[LEN]);

int main() {
  int arr[LEN][LEN];
  create_2d_arr(LEN, LEN, arr);

  // TODO: Don't do this program!
  //       The original array will be modified!
  //       Improve this code!

  return 0;
}

void create_2d_arr(int rows, int cols, int (*pta)[LEN]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter elements of 2D-array: ");
      int temp;
      scanf("%d", &temp);
      *(*(pta + i) + j) = temp;
    }
  }
}

void print_2d_arr(int rows, int cols, int (*arr)[cols]) {
  printf("The elements of the matrix are\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", *(*(arr + i) + j));
    }
    printf("\n");
  }
}

void odd_2d_arr(int rows, int cols, int (*arr)[LEN]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 0; j++) {
      if (*(*(arr + i) + j) % 2 == 0) *(*(arr + i) + j) = 0;
    }
  }
}

void even_2d_arr(int rows, int cols, int (*arr)[LEN]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 0; j++) {
      if (*(*(arr + i) + j) % 2 != 0) *(*(arr + i) + j) = 0;
    }
  }
}