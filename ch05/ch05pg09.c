/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
9. Write a program to add and subtract 10hrs 20mins
50sec and 5hrs 30min 40sec.

TODO: Improve this code!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int hrs, mins, secs;
} TIME;

void *add_time(TIME *t1, TIME *t2, TIME *res);
void *substract_time(TIME *t1, TIME *t2, TIME *res);

int main() {
  TIME t1 = {.hrs = 10, .mins = 20, .secs = 50};
  TIME t2 = {.hrs = 5, .mins = 30, .secs = 40};
  // 15:51:30
  //  4:50:10

  TIME *result = malloc(sizeof(TIME));
  add_time(&t1, &t2, result);
  printf("TIME: %d hrs, %d mins, %d secs\n", result->hrs, result->mins,
         result->secs);

  substract_time(&t1, &t2, result);
  printf("TIME: %d hrs, %d mins, %d secs\n", result->hrs, result->mins,
         result->secs);

  free(result);

  return 0;
}

void *add_time(TIME *t1, TIME *t2, TIME *res) {
  int addsecs = t1->secs + t2->secs;
  int addmins = t1->mins + t2->mins;
  int addhrs = t1->hrs + t2->hrs;
  if (addsecs >= 60) {
    res->secs = addsecs % 60;
    addmins++;
    if (addmins >= 60) {
      res->mins = addmins % 60;
      addhrs++;
    } else {
      res->mins = addmins;
      res->hrs = addhrs;
    }
  } else {
    res->secs = addsecs;
    if (addmins >= 60) {
      res->mins = addmins % 60;
      addhrs++;
      res->hrs = addhrs;
    } else {
      res->mins = addmins;
      res->hrs = addhrs;
    }
  }
}

void *substract_time(TIME *t1, TIME *t2, TIME *res) {
  TIME *lg, *sm;
  if (t1->hrs > t2->hrs) {
    lg = t1;
    sm = t2;
  } else {
    lg = t2;
    sm = t1;
  }

  int subsecs = lg->secs - sm->secs;
  int submins = lg->mins - sm->mins;
  int subhrs = lg->hrs - sm->hrs;

  if (subsecs < 0) {
    res->secs = 60 + subsecs;
    submins--;
    if (submins < 0) {
      res->mins = 60 + submins;
      subhrs--;
      res->hrs = subhrs;
    } else {
      res->mins = submins;
      res->hrs = subhrs;
    }
  } else {
    res->secs = subsecs;
    if (submins < 0) {
      res->mins = 60 + submins;
      subhrs--;
      res->hrs = subhrs;
    } else {
      res->mins = submins;
      res->hrs = subhrs;
    }
  }
}