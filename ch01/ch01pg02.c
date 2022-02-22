/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 2.
Write a program to print the count of even numbers between 1–200.
Also print their sum.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int cnt = 0;
  for (int i = 1; i < 201; i++) {
    if (i % 2 == 0) cnt++;
  }
  printf("The number of even numbers is %d\n", cnt);

  return 0;
}

