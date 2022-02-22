/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 12.
Write a program to read two floating point number arrays.
Merge the two arrays and display the resultant array in reverse order.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void create_arr(int, float *);
void print_rev(int, float *);
void merge_arr(int, float *, int, float *, float *);

int main() {
  float ar[2] = {1.0, 2.0};
  float br[2] = {3.0, 4.0};
  float cr[4];
  merge_arr(2, ar, 2, br, cr);
  print_rev(4, cr);

  return 0;
}

void create_arr(int sz, float *arr) {
  for (int i = 0; i < sz; i++) {
    float temp;
    printf("Enter float number: ");
    scanf("%f", &temp);
    *arr++ = temp;
  }
}

void print_rev(int sz, float *arr) {
  printf("The array is: \n");
  for (int i = sz - 1; i >= 0; i--) {
    printf("%f ", arr[i]);
  }
}

void merge_arr(int sz1, float *ar, int sz2, float *br, float *res) {
  int i;
  for (i = 0; i < sz1; i++) {
    res[i] = ar[i];
  }
  for (int j = 0; j < sz2; j++) {
    res[i + j] = br[j];
  }
}