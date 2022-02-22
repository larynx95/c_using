/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 8.
Write a program to calculate salary of an employee given his basic pay
(to be entered by the user),
HRA = 10% of the basic pay, TA = 5% of basic pay.
Define HRA and TA as constants and use them
to calculate the salary of the employee.
*/

#include <stdio.h>
#include <stdlib.h>

#define HRA 0.1
#define TA 0.05

int main() {
  float pay;
  printf("Enter your basic pay: ");
  scanf("%f", &pay);
  printf("Total pay=%.2f\n", pay + pay * (HRA + TA));

  return 0;
}
