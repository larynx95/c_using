/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 23.
Write a program to read numbers until -1 is entered and display whether it is an
Armstrong number or not.

TODO:
- What is the Amstrong's number?
  1634 == 1^4 + 6^4 + 3^4 + 4^4
- Find Amstrong numbers in the range of [m, n].
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int num_digits(int);
int is_Amstrong(int);

int main() {
  int num;

  /* user input */
  printf("Enter a number: ");
  scanf(" %d", &num);

  while (num != -1) {
    if (is_Amstrong(num)) {
      printf("%d is Amstrong number.\n", num);
    } else {
      printf("%d is not Amstrong number.\n", num);
    }

    /* user input again */
    printf("Enter a number: ");
    scanf("%d", &num);
  }

  return 0;
}

int num_digits(int num) {
  if (num < 10) return 1;
  return 1 + num_digits(num / 10);
}

/*
1234 / 10^0 % 10 -> 4
1234 / 10^1 % 10 -> 3
1234 / 10^2 % 10 -> 2
1234 / 10^3 % 10 -> 1
*/
int is_Amstrong(int num) {
  int dgs = num_digits(num);
  int val = 0;
  for (int i = 0; i < dgs; i++) {
    int temp = num / (int)pow((int)10, (int)i) % 10;
    val += (int)pow((int)temp, (int)dgs);
  }
  return num == val;
}