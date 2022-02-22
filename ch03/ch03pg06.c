/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 6.
Write a program to read and display a square
(using functions).
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define N 3

void create_2d_arr(int rows, int cols, int arr[rows][cols]);
void print_2d_arr(int rows, int cols, int arr[rows][cols]);

int main() {
  int arr[N][N];
  create_2d_arr(N, N, arr);
  print_2d_arr(N, N, arr);

  return 0;
}

void create_2d_arr(int rows, int cols, int arr[rows][cols]) {
  printf("Enter the elements of the matrix: ");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
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