/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 15.
Write a program that reads a matrix and displays
the sum of its diagonal elements.
******************************************************************************/

/*
# concepts
https://en.wikipedia.org/wiki/Main_diagonal
  1 2 3
  4 5 6
  7 8 9

  1 5 9                    3 5 7
  main diagonal            antidiagonal
  principal diagonal       counter diagonal
  primary diagonal         secondary diagonal
  leading diagonal         trailing diagonal
  major diagonal           minor diagonal
                           bad diagonal
*/

#include <stdio.h>
#include <stdlib.h>

void create2d_arr(int rows, int cols, int arr[rows][cols]);
void display2d_arr(int rows, int cols, int arr[rows][cols]);
int sum2d_maindiagonal(int rows, int cols, int arr[rows][cols]);
int sum2d_antidiagonal(int rows, int cols, int arr[rows][cols]);

int main() {
  int ar[2][2];
  create2d_arr(2, 2, ar);
  display2d_arr(2, 2, ar);

  printf("%d\n", sum2d_maindiagonal(2, 2, ar));
  printf("%d\n", sum2d_antidiagonal(2, 2, ar));

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

/* explicitly, the numbers of both rows and cols are fixed */
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

/* sum of main diagonal in matrix*/
int sum2d_maindiagonal(int rows, int cols, int arr[rows][cols]) {
  int total = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == j) {
        total += arr[i][j];
      }
    }
  }
  return total;
}

/* sum of antidiagonal in matrix */
int sum2d_antidiagonal(int rows, int cols, int arr[rows][cols]) {
  int total = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (cols - 1 - j == i) {
        total += arr[i][j];
      }
    }
  }
  return total;
}