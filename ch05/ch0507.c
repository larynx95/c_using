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
7. Write a program, using an array of pointers to a structure, to read and
display the data of students.

TODO: scanf, gets
Problem with scanf() when there is fgets()/gets()/scanf() after it
https://www.geeksforgeeks.org/problem-with-scanf-when-there-is-fgetsgetsscanf-after-it/
https://stackoverflow.com/questions/46104371/c-how-gets-work-after-scanf
https://stackoverflow.com/questions/22226529/program-doesnt-execute-gets-after-scanf-even-using-fflushstdin
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
  int r_no;
  char name[20];
  char course[20];
  int fees;
};

struct student *ptr_stud[10];

int main() {
  int i, n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    ptr_stud[i] = (struct student *)malloc(sizeof(struct student));
    /* dynamic mem allocation
       pointer is just address variable
       should be initialized
    */
    printf("Enter the data for student %d ", i + 1);
    printf("ROLL NO.: ");
    scanf("%d", &ptr_stud[i]->r_no);

    // TODO: input malfunction!!!
    // Solution 1: failed
    // fflush(stdout);  // not working
    // Solution 2: success
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    printf("NAME: ");
    gets(ptr_stud[i]->name);
    printf("COURSE: ");
    gets(ptr_stud[i]->course);
    printf("FEES: ");
    scanf("%d", &ptr_stud[i]->fees);
  }

  printf("DETAILS OF STUDENTS\n");
  for (i = 0; i < n; i++) {
    printf("ROLL NO. = %d\n", ptr_stud[i]->r_no);
    printf("NAME = %s\n", ptr_stud[i]->name);
    printf("COURSE = %s\n", ptr_stud[i]->course);
    printf("FEES = %d\n", ptr_stud[i]->fees);
  }

  for (int i = 0; i < n; i++) {
    free(ptr_stud[i]);
  }

  return 0;
}
