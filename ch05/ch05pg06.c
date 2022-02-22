/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
6. Write a program to calculate the distance between
the given points (6,3) and (2,2).

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  double x, y;
} POINT;

double distance(POINT *pos1, POINT *pos2);

int main() {
  POINT *a = malloc(sizeof(POINT));
  POINT *b = malloc(sizeof(POINT));
  a->x = 10.0;
  a->y = 10.0;
  b->x = 20.0;
  b->y = 20.0;
  printf("distance bw a and b: %.2f\n", distance(a, b));
  free(a);
  free(b);

  return 0;
}

double distance(POINT *pos1, POINT *pos2) {
  double xdis = (pos1->x) - pos2->x;
  double ydis = (pos1->y) - pos2->y;
  return sqrt(pow(xdis, 2) + pow(ydis, 2.0));
}
