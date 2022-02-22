/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 10.
Write a program to count the total number of non-zero elements
in a two-dimensional array.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void create_2d_arr(int, int, int (*)[LEN]);
void print_2d_arr(int, int, int (*)[LEN]);
int count_2d_nonzero(int, int, int (*)[LEN]);

int main() {
  int arr[LEN][LEN];
  create_2d_arr(LEN, LEN, arr);
  int result = count_2d_nonzero(LEN, LEN, arr);
  printf("The number of non-zero elems is %d\n", result);

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

int count_2d_nonzero(int rows, int cols, int (*arr)[LEN]) {
  int cnt = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int elem = *(*(arr + i) + j);
      if (elem != 0) cnt++;
    }
  }
  return cnt;
}
