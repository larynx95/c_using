/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 26. (optional)
TODO: Write a program to calculate factorial (large number).
*/

// https://www.programming9.com/programs/c-programs/259-compute-factorial-of-large-numbers-using-c

#include <stdio.h>

// This fx does not working when n is greater than 13.
int fact(int n) {
  if (n == 1) return 1;
  return n * fact(n - 1);
}

int main() {
  // a[MAX]  : MAX is the number of digits
  // n       : factorial(n)
  // counter :
  // temp    :
  // i       :
  int a[200], n, counter, temp, i;
  a[0] = 1;
  counter = 0;

  printf("Enter the number to Find Factorial: ");
  scanf("%d", &n);

  for (; n >= 2; n--) {               // (1)
    temp = 0;                         // (2)
    for (i = 0; i <= counter; i++) {  // (3)
      temp = (a[i] * n) + temp;       // (4), (5)
      a[i] = temp % 10;               // (6)
      temp = temp / 10;               // (7)
    }
    while (temp > 0) {
      a[++counter] = temp % 10;
      temp = temp / 10;
    }
  }
  for (i = counter; i >= 0; i--) printf("%d", a[i]);

  return 0;
}

/*
outer   inner
1   2       3   4   5   6   7
n   t   c   i  a[i] t a[i]  t
=============================
2   0   0   0   1   2   2   0
-----------------------------
3   0   0   0   1   3   3   0
2   0   0   0   3   6   6   0
-----------------------------
4   0   0   0   1   4   4   0
3   0   0   0   4  12   2   1
2   0   1   0   2   4   4   0
        1   1   1   2   2   0
-----------------------------
5   0   0   0   1   5   5   0
4   0   0   0   5  20   0   2
3   0   1   0   0   0   0   0
        1   1   2   6   6   0
2   0   1   0   0   0   0   0
        1   1   6  12   2   1
-----------------------------
6   0   0   0   1   6   6   0
5   0   0   0   6  30   0   3
4   0   1   0   0   0   0   0
        1   1   3  12   2   1
3   0   2   0   0   0   0   0
        2   1   2   6   6   0
        2   2   1   3   3   0
2   0   2   0   0   0   0   0
        2   1   6  12   2   1
        2   2   3   7   7   0
*/