/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 3.
Write a program to interchange the second element
with the second last element.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LEN 5

void array_swap(int, int *);
void print_arr(int, int *);

int main() {
  int arr[LEN];
  for (int i = 0; i < LEN; i++) {
    printf("Enter integer value: ");
    int temp;
    scanf("%d", &temp);
    arr[i] = temp;
  }

  print_arr(LEN, arr);
  array_swap(LEN, arr);
  print_arr(LEN, arr);

  return 0;
}

void array_swap(int n, int *array) {
  int i = 0, temp = 0;
  for (i = 0; i < n / 2; i++) {
    temp = array[i];
    array[i] = array[n - i - 1];
    array[n - i - 1] = temp;
  }
}

void print_arr(int n, int *arr) {
  printf("Entered array is: \n");
  for (int i = 0; i < LEN; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
