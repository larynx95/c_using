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
*/

/*
Programming Example
4. Write a program to read and display the information of all the students in a
class. Then edit the details of the ith student and redisplay the entire
information.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  struct student {
    int roll_no;
    char name[80];
    int fees;
    char DOB[80];
  };

  struct student stud[50];
  int n, i, num, new_rolno;
  int new_fees;
  char new_DOB[80], new_name[80];
  system("clear");

  printf("\n Enter the number of students: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("\n Enter the roll number: ");
    scanf("%d", &stud[i].roll_no);
    printf("\n Enter the name: ");
    gets(stud[i].name);
    printf("\n Enter the fees: ");
    scanf("%d", &stud[i].fees);
    printf("\n Enter the DOB: ");
    gets(stud[i].DOB);
  }

  for (i = 0; i < n; i++) {
    printf("\n ********DETAILS OF STUDENT %d*******", i + 1);
    printf("\n ROLL No. = %d", stud[i].roll_no);
    printf("\n NAME = %s", stud[i].name);
    printf("\n FEES = %d", stud[i].fees);
    printf("\n DOB = %s", stud[i].DOB);
  }

  printf("\n Enter the student number whose record has to be edited : ");
  scanf("%d", &num);
  num = num - 1;
  printf("\n Enter the new roll number : ");
  scanf("%d", &new_rolno);
  printf("\n Enter the new name : ") : gets(new_name);
  printf("\n Enter the new fees : ");
  scanf("%d", &new_fees);
  printf("\n Enter the new DOB : ");
  gets(new_DOB);
  stud[num].roll_no = new_rolno;
  strcpy(stud[num].name, new_name);
  stud[num].fees = new_fees;
  strcpy(stud[num].DOB, new_DOB);

  for (i = 0; i < n; i++) {
    printf("\n ********DETAILS OF STUDENT %d*******", i + 1);
    printf("\n ROLL No. = %d", stud[i].roll_no);
    printf("\n NAME = %s", stud[i].name);
    printf("\n FEES = %d", stud[i].fees);
    printf("\n DOB = %s", stud[i].DOB);
  }

  return 0;
}