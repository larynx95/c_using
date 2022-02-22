/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Selection Sort
https://www.geeksforgeeks.org/selection-sort/

  arr[] = 64 25 12 22 11

  // Find the minimum element in arr[0...4]
  // and place it at beginning
  11* 25 12 22 64

  // Find the minimum element in arr[1...4]
  // and place it at beginning of arr[1...4]
  11 12* 25 22 64

  // Find the minimum element in arr[2...4]
  // and place it at beginning of arr[2...4]
  11 12 22* 25 64

  // Find the minimum element in arr[3...4]
  // and place it at beginning of arr[3...4]
  11 12 22 25* 64

*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 5

int find_minval(int, int *);
int find_minidx(int, int *);
void sort_sel(int, int *);
void print_arr(int, int *);

int main() {
  int arr[5] = {5, 3, 4, 2, 1};
  sort_sel(5, arr);
  print_arr(5, arr);

  return 0;
}

void print_arr(int sz, int *arr) {
  printf("Your array: ");
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}

int find_minval(int sz, int arr[sz]) {
  int minval = *arr;
  arr++;
  for (int i = 1; i < sz; i++) {
    if (*arr < minval) {
      minval = *arr;
    }
    arr++;
  }
  return minval;
}

int find_minidx(int sz, int arr[sz]) {
  int minidx = 0;
  int minval = arr[0];
  for (int i = 1; i < sz; i++) {
    if (arr[i] < minval) {
      minval = arr[i];
      minidx = i;
    }
  }
  return minidx;
}

void sort_sel(int sz, int arr[sz]) {
  for (int i = 0; i < sz; i++) {
    int temp = arr[i];
    int minidx = find_minidx(sz - i, arr + i) + i;
    if (arr[i] != arr[minidx]) {
      arr[i] = arr[minidx];
      arr[minidx] = temp;
    }
  }
}