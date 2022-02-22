/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 19.
Write a program that reads a square matrix of size n * n.
Write a function int isLowerTriangular (int a[][], int n)
that returns 1 if the matrix is lower triangular.
(Hint: Array A is lower triangular if A ij = 0 and i<j )
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void create2d_arr(int rows, int cols, int arr[rows][cols]);
void display2d_arr(int rows, int cols, int arr[rows][cols]);
int isUpperTriangular(int sz, int arr[sz][sz]);

int main() {
  int ar[3][3];
  create2d_arr(3, 3, ar);
  display2d_arr(3, 3, ar);

  printf("%d\n", isUpperTriangular(3, ar));

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

int isUpperTriangular(int sz, int arr[sz][sz]) {
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      if (i < j && arr[i][j] != 0) {
        return 0;
      }
    }
  }
  return 1;
}