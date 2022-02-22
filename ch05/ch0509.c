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
9. Union

*/

#include <stdio.h>

struct student {
  union {
    char name[20];
    int roll_no;
  };
  int marks;
};

int main() {
  struct student stud;
  printf("size of struct: %d\n", sizeof(stud));  // 24, not 28
  char choice;
  printf("\nYou can enter the name or roll number of the student");
  printf("\nDo you want to enter the name? (Y or N): ");
  scanf("%c", &choice);
  getchar();

  if (choice == 'y' || choice == 'Y') {
    printf("Enter the name: ");
    gets(stud.name);
  } else {
    printf("Enter the roll number: ");
    scanf("%d", &stud.roll_no);
  }
  printf("Enter the marks: ");
  scanf("%d", &stud.marks);

  if (choice == 'y' || choice == 'Y')
    printf("Name: %s\n", stud.name);
  else
    printf("Roll Number: %d\n", stud.roll_no);
  printf("Marks: %d\n", stud.marks);

  return 0;
}