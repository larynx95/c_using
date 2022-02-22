/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 8.
Write a program to add two 3 * 3 matrix using pointers.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void create_2d_arr(int, int, int (*)[LEN]);
void print_2d_arr(int, int, int (*)[LEN]);
void add_2d_arr(int, int, int (*)[LEN], int (*)[LEN], int (*)[LEN]);

int main() {
  int arr[LEN][LEN];
  create_2d_arr(LEN, LEN, arr);

  int brr[LEN][LEN];
  create_2d_arr(LEN, LEN, brr);

  int crr[LEN][LEN];
  add_2d_arr(LEN, LEN, arr, brr, crr);

  print_2d_arr(LEN, LEN, crr);

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

void add_2d_arr(int rows, int cols, int (*arr)[LEN], int (*brr)[LEN],
                int (*crr)[LEN]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      *(*(crr + i) + j) = *(*(arr + i) + j) + *(*(brr + i) + j);
    }
  }
}
