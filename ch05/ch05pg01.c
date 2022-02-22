/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
1. Declare a structure that represents the following
hierarchical information.
  (a) Student
  (b) Roll Number
  (c) Name
    (i) First name
    (ii) Middle Name
    (iii) Last Name
  (d) Sex
  (e) Date of Birth
    (i) Day
    (ii) Month
    (iii) Year
  (f) Marks
    (i) English
    (ii) Mathematics
    (iii) Computer Science

*/

#include <stdio.h>
#include <stdlib.h>

struct name {
  char nfst[10];  /* first name */
  char nmid[10];  /* middle name */
  char nlast[10]; /* last name */
};

struct marks {
  int eng;  /* 0 for english */
  int math; /* 1 for mathematics */
  int cs;   /* 2 for computer science */
};

struct birth {
  int day;   /* 1 ~ 31 */
  int month; /* 1 ~ 12 */
  int year;  /* ex. 1970 */
};

struct student {
  int sex; /* 0 for male, 1 for female */
  long int roll_number;
  struct marks mks; /* nested struct */
  struct name nam;
  struct birth bth;
};

int main() {
  //
  return 0;
}
