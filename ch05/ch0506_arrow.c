/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions
5.1 Introduction
  5.1.1 Structure declaration
  5.1.2 `typedef` declarations
  5.1.3 Initialization of structures
  5.1.4 Accessing the members of a structure
  5.1.5 Copying and comparing structures (Program example 1 ~ 2)
5.2 Nested structures (Program example 3)
5.3 Arrays of structures (Program example 4)
5.4 Structures and fucntions
  5.4.1 Passing individual members
  5.4.2 Passing the entire structure (Program example 5)
  5.4.3 Passing structures through pointers (Program example 6 ~ 8)
*/

/*
Programming Example
6. Write a program to initialize the members of a structure
   by using a pointer to the structure.

- When declared as a pointer variable,
  member of astructure can be accessed using arrow operator.

*/

#include <stdio.h>
#include <stdlib.h>

struct student {
  int r_no;
  char name[20];
  char course[20];
  int fees;
};

int main() {
  struct student stud1, *ptr_stud1;
  system("clear");

  ptr_stud1 = &stud1;

  printf("\n Enter the details of the student :");
  printf("\n Enter the Roll Number =");
  scanf("%d", &ptr_stud1->r_no); /* notice this line */
  printf("\n Enter the Name = ");
  gets(ptr_stud1->name); /* here too */
  printf("\n Enter the Course = ");
  gets(ptr_stud1->course);
  printf("\n Enter the Fees = ");
  scanf("%d", &ptr_stud1->fees);

  printf("\n DETAILS OF THE STUDENT");
  printf("\n ROLL NUMBER = %d", ptr_stud1->r_no);
  printf("\n NAME = %s", ptr_stud1->name);
  printf("\n COURSE = %s", ptr_stud1->course);
  printf("\n FEES = %d", ptr_stud1->fees);

  return 0;
}
