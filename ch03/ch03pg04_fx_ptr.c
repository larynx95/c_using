/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 4.
Write a program that calculates the sum of squares of the elements.

TODO: Use higher-order function (function pointer in C)
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int square(int);
void make_arr(int, int *);
void change_array(int n, int arr[n], int (*fptr)(int));
void print_arr(int n, int *arr);

int main() {
  int arr[LEN];
  make_arr(LEN, arr);

  int (*fptr)(int) = &square;
  change_array(LEN, arr, fptr);

  print_arr(LEN, arr);

  return 0;
}

int square(int n) { return n * n; }

void make_arr(int n, int arr[n]) {
  for (int i = 0; i < n; i++) {
    printf("Enter integer value: ");
    int temp;
    scanf("%d", &temp);
    arr[i] = temp;
  }
}

void change_array(int n, int arr[n], int (*fptr)(int)) {
  for (int i = 0; i < n; i++) {
    arr[i] = fptr(arr[i]);
  }
}

void print_arr(int n, int *arr) {
  printf("Entered array is: \n");
  for (int i = 0; i < LEN; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}