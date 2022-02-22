/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 12.
Write a program that prints a floating point value in exponential format with
the following specifications:
(a) correct to two decimal places;
(b) correct to four decimal places; and
(c) correct to eight decimal places.

TODO: https://en.cppreference.com/w/c/io/fprintf

  %   #0   12   .5   L   g
     (1)  (2)  (3)  (4) (5)
  (1) flags: -, +, space, #, 0
  (2) minimum field width
  (3) precision: d,i,o,u,x,X - a,A,e,E,f,F - g,G - s
  (4) length modifier: hh, h, l, ll, j, z, t, L
  () conversion specifier: d,i - f,F - e,E - g,G - a,A - c - s - p - n - %

* Correct format specifier for double in printf
  https://stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf
  printf - %f or %lf for both float and double
  scanf - %f for float, %lf for double
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  float flt;
  printf("Enter floating pointer number: ");
  scanf("%f", &flt);

  printf("%.2f\n", flt);
  printf("%.4f\n", flt);
  printf("%.8f\n", flt);

  printf("%.2g\n", flt);
  printf("%.4g\n", flt);
  printf("%.8g\n", flt);

  printf("%.2g\n", flt);
  printf("%.4g\n", flt);
  printf("%.8g\n", flt);

  printf("%.2e\n", flt);
  printf("%.4e\n", flt);
  printf("%.8e\n", flt);

  printf("%.2E\n", flt);
  printf("%.4E\n", flt);
  printf("%.8E\n", flt);

  double dbl;
  printf("Enter double number: ");
  scanf("%lf", &dbl);

  printf("%.2f\n", dbl);
  printf("%.4f\n", dbl);
  printf("%.8f\n", dbl);

  printf("%.2g\n", dbl);
  printf("%.4g\n", dbl);
  printf("%.8g\n", dbl);

  printf("%.2g\n", dbl);
  printf("%.4g\n", dbl);
  printf("%.8g\n", dbl);

  printf("%.2e\n", dbl);
  printf("%.4e\n", dbl);
  printf("%.8e\n", dbl);

  printf("%.2E\n", dbl);
  printf("%.4E\n", dbl);
  printf("%.8E\n", dbl);

  return 0;
}
