/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 13.
Write a program using pointers to interchange the second biggest
and the second smallest number in the array.

TODO:
- Implement these functions without <limits.h> header
- Is there any better algorithm? max/min heap?
******************************************************************************/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int find_snd_biggest(int, int *);
int find_snd_biggest1(int, int *);
int find_snd_smallest(int, int *);
int find_snd_smallest1(int, int *);

int main() {
  int ar[5] = {1, 2, 3, 4, 5};

  printf("second largest: %d\n", find_snd_biggest(5, ar));
  printf("second smallest: %d\n", find_snd_smallest(5, ar));

  return 0;
}

int find_snd_biggest(int sz, int *arr) {
  int fst, snd;
  fst = arr[0];
  snd = arr[0];

  for (int i = 1; i < sz; i++) {
    if (arr[i] > fst) {
      snd = fst;  // <----- this is the key!
      fst = arr[i];
    } else if (arr[i] > snd && fst > arr[i]) {
      snd = arr[i];
    }
  }
  return snd;
}

/* https://www.geeksforgeeks.org/find-second-largest-element-array/ */
int find_snd_biggest1(int sz, int *arr) {
  int i, first, second;
  if (sz < 2) {
    printf(" Invalid Input ");
    return (EXIT_FAILURE);
  }

  first = second = INT_MIN;
  for (i = 0; i < sz; i++) {
    if (arr[i] > first) {
      second = first;
      first = arr[i];
    } else if (arr[i] > second && arr[i] != first)
      second = arr[i];
  }
  if (second == INT_MIN) printf("There is no second largest element\n");

  return second;
}

/* https://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/
 */
int find_snd_smallest(int sz, int *ar) {
  int fst, snd;
  fst = snd = INT_MAX;
  for (int i = 0; i < sz; i++) {
    if (ar[i] < fst) {
      snd = fst;
      fst = ar[i];
    } else if (ar[i] < snd && ar[i] != fst) {
      snd = ar[i];
    }
  }
  return snd;
}

int find_snd_smallest1(int sz, int *arr) {
  int i, first, second;
  if (sz < 2) {
    printf(" Invalid Input ");
    return (EXIT_FAILURE);
  }

  first = second = INT_MAX;
  for (i = 0; i < sz; i++) {
    if (arr[i] < first) {
      second = first;
      first = arr[i];
    } else if (arr[i] < second && arr[i] != first)
      second = arr[i];
  }
  if (second == INT_MAX) printf("There is no second smallest element\n");

  return second;
}