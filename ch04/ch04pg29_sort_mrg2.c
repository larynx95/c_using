/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Merge Sort
https://www.geeksforgeeks.org/merge-sort/
  MergeSort(arr[], l,  r)
  If r > l
    1. Find the middle point to divide the array into two halves:
            middle m = (l+r)/2
    2. Call mergeSort for first half:
            Call mergeSort(arr, l, m)
    3. Call mergeSort for second half:
            Call mergeSort(arr, m+1, r)
    4. Merge the two halves sorted in step 2 and 3:
            Call merge(arr, l, m, r)

# Solution in ...
https://www.geeksforgeeks.org/merge-sort/
*/

#include <stdio.h>
#include <stdlib.h>

void print_arr(int, int *);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main() {
  int arr[6] = {4, 2, 0, 5, 3, 1};

  mergeSort(arr, 0, 5);
  merge(arr, 0, 3, 5);
  print_arr(6, arr);

  return 0;
}

void print_arr(int sz, int *arr) {
  printf("Your array: ");
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}

/* Merges two subarrays of arr[].
   First subarray is arr[l..m]
   Second subarray is arr[m+1..r]
*/

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;  // length of left sub-array
  int n2 = r - m;      // length of right sub-array

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

  /* Merge the temp arrays back into arr[l..r]*/
  i = 0;  // Initial index of first subarray
  j = 0;  // Initial index of second subarray
  k = l;  // Initial index of merged subarray
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there are any */
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there are any */
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Same as (l+r)/2, but avoids overflow for large l and h
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}