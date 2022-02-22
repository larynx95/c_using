/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Insertion Sort
1. https://www.geeksforgeeks.org/insertion-sort/
     12, 11*, 13, 5, 6
  a. Let us loop for i = 1 (second element of the array) to 4
     (last element of the array) i = 1.
     Since 11 is smaller than 12, move 12 and insert 11 before 12
     11, 12, 13*, 5, 6
  b. i = 2. 13 will remain at its position
     as all elements in A[0..I-1] are smaller than 13
     11, 12, 13, 5*, 6
  c. i = 3. 5 will move to the beginning and all other elements
     from 11 to 13 will move one position ahead of their current position.
     5, 11, 12, 13, 6*
  d. i = 4. 6 will move to position after 5, and elements
     from 11 to 13 will move one position ahead of their current position.
     5, 6, 11, 12, 13
2. My plan
  - focus moving from index(1) to index(n-1)
  - comparing arr[i] and arr[0] ~ arr[i-1]
  - change positions of elements
*/

#include <stdio.h>
#include <stdlib.h>

void print_arr(int, int *);
void sort_ins(int sz, int *);
void insertionSort(int n, int arr[]);

int main() {
  int arr[5] = {5, 3, 4, 2, 1};
  sort_ins(5, arr);
  print_arr(5, arr);

  return 0;
}

void print_arr(int sz, int *arr) {
  printf("Your array: ");
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}

/*
  5 3 4 2 1
  3 [5]
    [5 5]
    [3 5]
  4 [3 5]
    [3 5 5]
    [3 4 5]
  2 [3 4 5]
    [3 4 5 5]
    [3 4 4 5]
    [3 3 4 5]
    [2 3 4 5]
  1 [2 3 4 5]
    [2 3 4 5 5]
    [2 3 4 4 5]
    [2 3 3 4 5]
    [2 2 3 4 5]
    [1 2 3 4 5]
*/
void sort_ins(int sz, int *arr) {
  for (int i = 1; i < sz; i++) {
    int cur = arr[i];
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] > cur) {
        arr[j + 1] = arr[j];
        arr[j] = cur;
      } else {
        break;
      }
    }
  }
}

/* https://www.geeksforgeeks.org/insertion-sort/ */
void insertionSort(int n, int arr[]) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    /* Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}