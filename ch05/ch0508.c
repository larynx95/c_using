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
5.5 Self-referential structures
5.6 Unions
  5.6.1 Declaring a union
  5.6.2 Accessing a member of a union
  5.6.3 Initializing unions
5.7 Arrays fo union variables
5.8 Unions inside structures
*/

/*
Programming Example
8. Write a program that passes a pointer to a structure to a function.

*/

#include <stdio.h>
#include <stdlib.h>

struct student {
  int r_no;
  char name[20];
  char course[20];
  int fees;
};

void display(struct student *);

int main() {
  struct student *ptr;
  ptr = (struct student *)malloc(sizeof(struct student));

  printf("\n Enter the data for the student ");
  printf("\n ROLL NO.: ");
  scanf("%d", &ptr->r_no);
  printf("\n NAME: ");
  gets(ptr->name);
  printf("\n COURSE: ");
  gets(ptr->course);
  printf("\n FEES: ");
  scanf("%d", &ptr->fees);
  display(ptr);
  getch();

  return 0;
}

void display(struct student *ptr) {
  printf("\n DETAILS OF STUDENT");
  printf("\n ROLL NO. = %d", ptr->r_no);
  printf("\n NAME = %s", ptr->name);
  printf("\n COURSE = %s ", ptr->course);
  printf("\n FEES = %d", ptr->fees);
}