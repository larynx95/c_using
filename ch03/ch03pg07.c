/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 7.
Write a program that computes the sum of the elements
that are stored on the main diagonal of a matrix using pointers.

The main diagonal of a matrix consists of those elements that lie on the
diagonal that runs from top left to bottom right.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void create_2d_arr(int, int, int (*)[LEN]);
void print_2d_arr(int, int, int (*)[LEN]);
int sum_diagonal(int, int, int (*)[LEN]);

int main() {
  int arr[LEN][LEN];
  create_2d_arr(LEN, LEN, arr);
  print_2d_arr(LEN, LEN, arr);

  printf("diagonal sum is %d\n", sum_diagonal(LEN, LEN, arr));

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

int sum_diagonal(int rows, int cols, int (*arr)[cols]) {
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == j) {
        sum += *(*(arr + i) + j);
      }
    }
  }
  return sum;
}