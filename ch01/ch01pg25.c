/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 25.
Write a program to calculate area of a triangle using pointers.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pos {
  float x;
  float y;
} Pos;

float get_area(Pos *sar);

int main() {
  Pos pos[3];
  for (int i = 0; i < 3; i++) {
    printf("Enter x, y coordinate of point %d: ", i);
    scanf("%f %f", &pos[i].x, &pos[i].y);
  }

  printf("Area of the triangle: %.2f\n", get_area(pos));

  return 0;
}

float get_area(Pos *pos) {
  float minx = pos->x;
  float maxx = pos->x;
  float miny = pos->y;
  float maxy = pos->y;
  for (int i = 1; i < 3; i++) {
    if (pos[i].x < minx) {
      minx = pos[i].x;
    }
    if (pos[i].x > maxx) {
      maxx = pos[i].x;
    }
    if (pos[i].y < miny) {
      miny = pos[i].y;
    }
    if (pos[i].y > maxy) {
      maxy = pos[i].y;
    }
  }
  float xdist = maxx - minx;
  float ydist = maxy - miny;

  return (float)xdist * (float)ydist / (float)2;
}
