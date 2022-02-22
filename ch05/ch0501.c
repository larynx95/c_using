/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions
5.1 Introduction
  5.1.1 Structure declaration
  5.1.2 `typedef` declarations
  5.1.3 Initialization of structures
  5.1.4 Accessing the members of a structure
  5.1.5 Copying and comparing structures (Program example 1 ~ 2)
*/

/*
Programming Example
1. Write a program using structures to read and display the information about a
student.

TODO: Questions
1. Where is the best place to define (not declare) structure?
   in or out of main fx.
   https://stackoverflow.com/questions/31380268/where-to-declare-structures-inside-main-or-outside-main

# Structure definition
  definition                             usasge
  -----------------------------------------------
  struct Point {                         struct Point p1;
    member;
  };
  -----------------------------------------------
  struct Point {                         define and declare
    member;
  } P1;
  -----------------------------------------------
  typedef struct {                       struct Point P1;
    member;
  } Point;
  -----------------------------------------------
  typedef struct Point {                 Mypoint P1;
    member;
  } Mypoint;

*/

#include <stdio.h>
#include <stdlib.h>

/* How to define structure, different ways */
struct AAA {
  int val;
};

struct BBB {
  int val;
} B1;

typedef struct {
  int val;
} CCC;

typedef struct DDD {
  int val;
} Dname;

int main() {
  /* struct template inside main fx. */
  struct student {
    int roll_no;
    char name[80];
    float fees;
    char DOB[80];
  };

  /* declare struct variable (instance) */
  struct student stud1;

  /* get data from stdin, and initializaing struct */
  printf("Enter the roll number : ");
  scanf("%d", &stud1.roll_no);
  printf("Enter the name : ");
  scanf("%s", stud1.name);
  printf("Enter the fees : ");
  scanf("%f", &stud1.fees);
  printf("Enter the DOB : ");
  scanf("%s", stud1.DOB);

  /* print struct */
  printf("********STUDENT'S DETAILS *******");
  printf("ROLL No. = %d", stud1.roll_no);
  printf("NAME = %s", stud1.name);
  printf("FEES = %f", stud1.fees);
  printf("DOB = %s", stud1.DOB);

  return 0;
}