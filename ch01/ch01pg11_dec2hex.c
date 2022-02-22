/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 11.
Write a program to read an integer.
Display the value of that integer in decimal, octal, and hexadecimal notation.

TODO: Implement conversion functions.
      Find library functions.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
a. Iterative
b. TODO: Recursive
fx(9, 2)
= 1 + fx(9, 4)
= 1 + 1 + fx(9, 8)
= 1 + 1 + 1 + fx(9, 16)
= 1 + 1 + 1 + 0
= 3
*/

int get_exp_while(int num, int base);
int get_exp_rec(int num, int base);
int dec2base(int num, int base);

int main() {
  int a = 100;
  printf("100 is octal %o\n", a);
  printf("100 is hexadecimal %x\n", a);

  printf("%d\n", (int)pow((double)8, (double)1));

  /* tests for get_exp_while fx. */
  printf("%d\n", get_exp_while(7, 8));
  printf("%d\n", get_exp_while(8, 8));
  printf("%d\n", get_exp_while(64, 8));
  printf("%d\n", get_exp_while(65, 8));
  printf("%d\n", get_exp_while(512, 8));
  printf("%d\n", get_exp_while(513, 8));

  /* tests for decimal to base */
  printf("decimal 9 is octal %d\n", dec2base(9, 8));
  printf("decimal 149 is octal %d\n", dec2base(149, 8));

  return 0;
}

int get_exp_while(int num, int base) {
  int i = 0;
  if (num / base == 0) return 0;

  while (1) {
    // Be careful! Type conversion!
    if (num / (int)pow((double)base, (double)i) == 0) break;
    // printf("%d -- %d\n", i, num / (int)pow((double)base, (double)i));
    i++;
  }
  return i - 1;
}

// TODO: Fix this fx.
int get_exp_rec(int num, int base) {
  if (num < base) {
    return 0;
  }
  return 1 + get_exp_rec(num, base * base);  // this is not correct
}

/*
fx(149, 8)
= 10^2 * 149/(8^2) + fx(21, 8)       max_exp = 2  (1, 8, 64, 512, ...)
= 200 + 10^1 * 21/(8^1) + fx(5, 8)   max_exp = 1  (1, 8, 64, 512, ...)
= 200 + 20 + 5                       max_exp = 0
= 225
*/

int dec2base(int num, int base) {
  int mx = get_exp_while(num, base);
  if (mx == 0) return num;
  int val = (int)pow((double)10, (double)mx);
  int divisor = (int)pow((double)base, (double)mx);
  int quotient = num / divisor;
  int remainder = num - divisor * quotient;
  return val * quotient + dec2base(remainder, base);
}

// TODO: Improve this fx.