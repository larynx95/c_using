/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 7.
Write a program to calculate simple interest and compound interest.

Hint.
Simple interest: base * rate * years
Compound interest: accumulate interest into base
*/

#include <stdio.h>
#include <stdlib.h>

double s_interest(double base, double rate, int years) {
  return base * rate * years;
}

double c_interest(double base, double rate, int years) {
  if (years == 0)
    return 0;
  else
    return (base * rate) + c_interest(base + base * rate, rate, years - 1);
}

int main() {
  double base = 100.00;
  double rate = 0.02;
  int years = 2;
  printf("simple interest: %.2f\n", s_interest(base, rate, years));
  printf("simple interest: %.2f\n", c_interest(base, rate, years));

  return 0;
}
