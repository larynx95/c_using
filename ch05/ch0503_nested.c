/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions
5.1 Introduction
  5.1.1 Structure declaration
  5.1.2 `typedef` declarations
  5.1.3 Initialization of structures
  5.1.4 Accessing the members of a structure
  5.1.5 Copying and comparing structures (Program example 1 ~ 2)
5.2 Nested structures (Program example 3)
*/

/*
Programming Example
3. Write a program to read and display the information of a student using a
nested structure.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  struct DOB {
    int day;
    int month;
    int year;
  };

  struct student {
    int roll_no;
    char name[100];
    float fees;
    struct DOB date; /* nested structure */
  };

  struct student stud1;

  /* user input */
  system("clear");
  printf("\n Enter the roll number : ");
  scanf("%d", &stud1.roll_no);
  printf("\n Enter the name : ");
  scanf("%s", stud1.name);
  printf("\n Enter the fees : ");
  scanf("%f", &stud1.fees);
  printf("\n Enter the DOB : ");
  scanf("%d %d %d", &stud1.date.day, &stud1.date.month, &stud1.date.year);

  /* printing */
  printf("\n ********STUDENT'S DETAILS *******");
  printf("\n ROLL No. = %d", stud1.roll_no);
  printf("\n NAME = %s", stud1.name);
  printf("\n FEES = %f", stud1.fees);
  printf("\n DOB = %d – %d – %d", stud1.date.day, stud1.date.month,
         stud1.date.year);

  return 0;
}