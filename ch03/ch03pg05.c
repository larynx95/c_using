/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises5.
Write a program to compute the sum and mean of
the elements of a two-dimensional array.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define NROW 3
#define NCOL 3

void print_2d_arr(int rows, int cols, int arr[rows][cols]);
void create_2d_arr(int rows, int cols, int arr[rows][cols]);
int sum_2d_arr(int rows, int cols, int arr[rows][cols]);
float mean_2d_arr(int rows, int cols, int arr[rows][cols]);

int main() {
  int arr[NROW][NCOL];

  create_2d_arr(NROW, NCOL, arr);
  print_2d_arr(NROW, NCOL, arr);

  printf("sum of array: %d\n", sum_2d_arr(NROW, NCOL, arr));
  printf("mean of array: %.2f\n", mean_2d_arr(NROW, NCOL, arr));

  return 0;
}

void create_2d_arr(int rows, int cols, int arr[rows][cols]) {
  printf("Enter the elements of the matrix: \n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("Enter [%d][%d]: ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
  printf("\n");
}

void print_2d_arr(int rows, int cols, int arr[rows][cols]) {
  printf("Your 2D array is: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int sum_2d_arr(int rows, int cols, int arr[rows][cols]) {
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      sum += arr[i][j];
    }
  }
  return sum;
}

float mean_2d_arr(int rows, int cols, int arr[rows][cols]) {
  int sum = sum_2d_arr(rows, cols, arr);
  return sum / (rows * cols * 1.0);  // TODO: type conversions
}