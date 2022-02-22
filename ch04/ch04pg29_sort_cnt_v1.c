/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Count Sort
https://www.geeksforgeeks.org/counting-sort/

  For simplicity, consider the data in the range 0 to 9.
  Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0  1  1  0  1  0  0

  2) Modify the count array such that each element at each index
  stores the sum of previous counts.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

  The modified count array indicates the position of each object in
  the output sequence.

  3) Output each object from the input sequence followed by
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2.
  Position of 1 is 2.
  Put data 1 at index 2 in output.
  Decrease count by 1
  to place next data 1 at an index 1 smaller than this index.

  Input:     1, 4, 1, 2, 7, 5, 2
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7

  Input:     1*, 4, 1, 2, 7, 5, 2
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  1* 4  4  5  6  6  7  7
  Output:          1

  Input:     1, 4*, 1, 2, 7, 5, 2
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  1  4  4  4* 6  6  7  7
  Output:          1        4*

  Input:     1, 4, 1*, 2, 7, 5, 2
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  0* 4  4  4  6  6  7  7
  Output:       1* 1        4

  Input:     1, 4, 1, 2*, 7, 5, 2
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  0  3* 4  4  6  6  7  7
  Output:       1  1     2* 4

  Input:     1, 4, 1, 2, 7*, 5, 2
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  0  3  4  3  6  6  6* 7
  Output:       1  1     2  4     7*

  Input:     1, 4, 1, 2, 7, 5*, 2
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  0  3  4  3  5* 6  6  7
  Output:       1  1     2  4  5* 7

  Input:     1, 4, 1, 2, 7, 5, 2*
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  0  2* 4  3  6  5  6  7
  Output:       1  1  2* 2  4  5  7
*/

#include <stdio.h>
#include <stdlib.h>

void print_arr(int, int *);
int get_max(int sz, int *arr);
void sort_cnt(int, int, int *, int *);

int main() {
  /* Solution 1. */
  int arr[5] = {5, 2, 4, 3, 1};
  int mx = get_max(5, arr) + 1;
  int out[mx];
  sort_cnt(5, mx, arr, out);

  return 0;
}

int get_max(int sz, int *arr) {
  int mx = arr[0];
  for (int i = 1; i < sz; i++) {
    if (mx < arr[i]) {
      mx = arr[i];
    }
  }
  return mx;
}

void sort_cnt(int sz, int mx, int *arr, int *out) {
  /* initialize out array */
  for (int i = 0; i < mx; i++) out[i] = 0;
  /* create int count array */
  for (int i = 0; i < mx; i++) {
    out[i] = 0;
    for (int j = 0; j < sz; j++) {
      if (arr[j] == i) {
        out[i] += 1;
      }
    }
  }

  for (int i = 0; i < mx; i++) {
    for (int j = 0; j < out[i]; j++) {
      printf("%d ", i);
    }
  }
}

void print_arr(int sz, int *arr) {
  printf("Your array: ");
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}
