/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 17.
Write a program that reads a matrix and displays
the sum of the elements below the main diagonal.
(Hint: Calculate the sum of elements A ij where
i>j )
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void create2d_arr(int rows, int cols, int arr[rows][cols]);
void display2d_arr(int rows, int cols, int arr[rows][cols]);
int sum2d_below_main_diagonal(int rows, int cols, int arr[rows][cols]);

int main() {
  int ar[3][3];
  create2d_arr(3, 3, ar);
  display2d_arr(3, 3, ar);

  printf("%d\n", sum2d_below_main_diagonal(3, 3, ar));

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

int sum2d_below_main_diagonal(int rows, int cols, int arr[rows][cols]) {
  int total = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i > j) {
        total += arr[i][j];
      }
    }
  }
  return total;
}