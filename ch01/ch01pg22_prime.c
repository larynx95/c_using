/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 22.
Write a program to print all prime numbers from m to n. [m,n]
*/

#include <stdio.h>
#include <stdlib.h>
#define SZ(arr) = sizeof(arr) / sizeof(arr[0])

int is_in(int, int, int *);
int is_prime(int);

int main() {
  /* find prime */
  int m = 10;
  int n = 20;
  for (int i = m; i <= n; i++) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");

  /* test for is_in fx. */
  int brr[5] = {1, 2, 3, 4, 5};
  printf("%d\n", is_in(5, 5, brr));
  printf("%d\n", is_in(13, 5, brr));

  return 0;
}

int is_prime(int num) {
  for (int i = 2; i < num / 2; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int is_in(int num, int sz, int *arr) {
  for (int i = 0; i < sz; i++) {
    if (num == arr[i]) return 1;
  }
  return 0;
}