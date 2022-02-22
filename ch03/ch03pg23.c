/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 23.
Write a program to enter a number and break it into n number of digits.

# Concepts
number = 1234
digits = {1,2,3,4}

1234                / 10^3  = 1
(1234 - 1 * 10^3)   / 10^2  = 2
(234 - 2 * 10^2)    / 10^1  = 3
(34 - 3 * 10^1)     / 10^0  = 4
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int get_exp(int num);
void get_digits(int exp, int num, int arr[exp + 1]);

int main() {
  /* enter a number */
  int input;
  printf("Enter a number: ");
  scanf(" %d", &input);

  int exp = get_exp(input);
  int arr[4];
  get_digits(exp, input, arr);

  for (int i = 0; i < exp + 1; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

/* custom pow fx. */
int mypow(int base, int exp) {
  if (exp == 0) return 1;
  return base * mypow(base, exp - 1);
}

/* get n-1 in n-figure number */
int get_exp(int num) {
  if (num < 10) return 0;
  return 1 + get_exp(num / 10);
}

void get_digits(int exp, int num, int arr[exp + 1]) {
  int val = num;
  for (int i = exp; i >= 0; i--) {
    int pw = mypow(10, i);
    arr[exp - i] = val / pw;
    val = val - val / pw * pw;
  }
}
