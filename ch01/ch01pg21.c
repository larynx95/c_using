/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 21.
Write a program to print all odd numbers from m to n .
*/

#include <stdio.h>
#include <stdlib.h>

void get_odd_numbers(int m, int n) {
  for (int i = m; i <= n; i++) {
    if (i % 2 == 1) printf("%d ", i);
  }
}

int main() {
  get_odd_numbers(10, 20);

  return 0;
}
