/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
10. Write a program using structure to check if the
current year is leap year or not.

- leap year
https://en.wikipedia.org/wiki/Leap_year

if (year is not divisible by 4) then (it is a common year)
else if (year is not divisible by 100) then (it is a leap year)
else if (year is not divisible by 400) then (it is a common year)
else (it is a leap year)

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Enter a year: ");
  int yr;
  scanf("%d", &yr);

  bool leap;
  if (yr % 4 != 0)
    leap = false;
  else if (yr % 100 != 0)
    leap = true;
  else if (yr % 400 != 0)
    leap = false;
  else
    leap = true;

  if (leap)
    printf("it is leap year.\n");
  else
    printf("it is common year.\n");

  return 0;
}