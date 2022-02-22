/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
6. Write a program to compute F(x, y) , where
  F(x, y) = F(x-y, y) + 1 if y<=x
  And
  F(x, y) = 0 if x<y

TODO: What operation does this code mean?
F(20, 20) => 1
F(30, 20) => 1
F(40, 20) => 2
This code means simple division.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F(int x, int y) {
  if (x < y) {
    return 0;
  } else {
    return F(x - y, y) + 1;
  }
}

int main() {
  int res = F(20, 20);
  printf("result: %d\n", res);
  return 0;
}
