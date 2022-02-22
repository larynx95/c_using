/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 21.
Write a program to calculate XA + YB
where A and B are matrices and X = 2 and Y = 3
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void create2d_arr(int rows, int cols, int arr[rows][cols]);
void display2d_arr(int rows, int cols, int arr[rows][cols]);
void mult2d_scalar(int rows, int cols, int ar[rows][cols], int out[rows][cols],
                   int scal);
void sum2d(int rows, int cols, int ar[rows][cols], int br[rows][cols],
           int out[rows][cols]);

int main() {
  int ar[3][3];
  create2d_arr(3, 3, ar);
  display2d_arr(3, 3, ar);

  int br[3][3];
  create2d_arr(3, 3, br);
  display2d_arr(3, 3, br);

  int ar_out[3][3];
  int br_out[3][3];
  int sum_out[3][3];
  int X = 2;
  int Y = 3;

  mult2d_scalar(3, 3, ar, ar_out, X);
  mult2d_scalar(3, 3, br, br_out, Y);
  sum2d(3, 3, ar_out, br_out, sum_out);

  display2d_arr(3, 3, sum_out);

  return 0;
}

/* creating a 2-D array */
void create2d_arr(int rows, int cols, int arr[rows][cols]) {
  printf("Enter the elements of the matrix: \n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter arr[%d][%d]: ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
  printf("\n");
}

/* display 2D array */
void display2d_arr(int rows, int cols, int arr[rows][cols]) {
  printf("Your %d * %d matrix is: \n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* void, 2D sum of two matrices */
void sum2d(int rows, int cols, int ar[rows][cols], int br[rows][cols],
           int out[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      out[i][j] = ar[i][j] + br[i][j];
    }
  }
}

/* void, 2D scalar multiplication */
void mult2d_scalar(int rows, int cols, int ar[rows][cols], int out[rows][cols],
                   int scal) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      out[i][j] = scal * ar[i][j];
    }
  }
}