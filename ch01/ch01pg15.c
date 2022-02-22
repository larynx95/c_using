/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 15.
Write a program to find whether a number is divisible by two or not
using functions.
*/

#include <stdio.h>
#include <stdlib.h>

int is_divisible_by_two(int);

int main() {
  printf("Enter a number: ");
  int num;
  scanf("%d", &num);

  int res = is_divisible_by_two(num);
  if (res == 1) {
    printf("%d is divisible by 2.", num);
  } else {
    printf("%d is not divisible by 2.", num);
  }

  return 0;
}

int is_divisible_by_two(int num) { return num % 2 == 0; }