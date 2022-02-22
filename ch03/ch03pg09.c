/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 9.
Write a program that computes the product of the elements
that are stored on the diagonal above the main diagonal.

        0 1 2 3 4 5 6 7 8 9
    0  *
    1    *
    2      *
    3        *
    4          *
    5            *
    6              *
    7                *
    8                  *
    9                    *


******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void create_2d_arr(int, int, int (*)[LEN]);
void print_2d_arr(int, int, int (*)[LEN]);
int product_diagonal(int, int, int (*)[LEN]);

int main() {
  int arr[LEN][LEN];
  create_2d_arr(LEN, LEN, arr);
  printf("Product of diagonal is %d\n", product_diagonal(LEN, LEN, arr));

  return 0;
}

void create_2d_arr(int rows, int cols, int (*pta)[LEN]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter elements of 2D-array[%d][%d]: ", i, j);
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

int product_diagonal(int rows, int cols, int (*arr)[LEN]) {
  int prod = 1;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == j) prod *= *(*(arr + i) + j);
    }
  }
  return prod;
}