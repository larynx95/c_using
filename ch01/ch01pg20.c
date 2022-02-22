/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 20.
Write a program to display sum and average of numbers from 1 to n.
Use for loop.
*/

#include <stdio.h>
#include <stdlib.h>

int mysum(int);
float myavg(int);

int main() {
  printf("Total: %d\n", mysum(10));
  printf("Average: %.2f\n", myavg(10));

  return 0;
}

int mysum(int num) {
  int total = 0;
  for (int i = 1; i <= num; i++) {
    total += i;
  }
  return total;
}

float myavg(int num) {
  int total = mysum(num);
  return total / num;
}
