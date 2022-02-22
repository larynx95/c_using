/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

# Radix Sort
https://www.geeksforgeeks.org/radix-sort/

  a. 1s place
    170, 45, 75, 90, 802, 24, 2, 66
    17(0), 4(5), 7(5), 9(0), 80(2), 2(4), (2), 6(6)
    170, 90, 802, 2, 24, 45, 75, 66

  b. 10s place
    170, 90, 802, 2, 24, 45, 75, 66
    1(7)0, (9)0, 8(0)2, 2, (2)4, (4)5, (7)5, (6)6
    802, 2, 24, 45, 66, 170, 75, 90

  c. 100s place
    802, 2, 24, 45, 66, 170, 75, 90
    (8)02, 2, 24, 45, 66, (1)70, 75, 90
    2, 24, 45, 66, 75, 90, 170, 802

# My Plan
- find digit: 1s, 10s, 100s, ...
- sort by one digit (= using count sort)
- 1s, 10s, 100s, ...
*/

#include <stdio.h>
#include <stdlib.h>

void print_arr(int, int *);
int get_exp(int);
int get_max_exp(int sz, int *arr);
void sort_by_dg(int, int *, int);

int main() {
  int arr[5] = {5, 2, 40, 3000, 1};
  printf("%d\n", get_exp(123));         // 2
  printf("%d\n", get_max_exp(5, arr));  // 3

  return 0;
}

/* get max 10^x value in a number */
int get_exp(int num) {
  if (num / 10 == 0) return 0;
  return 1 + get_exp(num / 10);
}

/* get max 10^x value in an array */
int get_max_exp(int sz, int *arr) {
  int mx = 0;
  for (int i = 0; i < sz; i++) {
    int ex = get_exp(arr[i]);
    if (ex > mx) {
      mx = ex;
    }
  }
  return mx;
}

void sort_by_dg(int sz, int *arr, int dg) {
  int mx = get_max_exp(sz, arr);
  //
}

void print_arr(int sz, int *arr) {
  printf("Your array: ");
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}
