/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
24. Write a program to read and display names of employees in a department.

* array of strings == array of array of characters
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_employees(int, char emp[3][10]);
void print_employees1(int, char emp[][10]);
void print_employees2(int, char *emp[10]);  // TODO:
void print_employees3(int, char (*)[10]);
void print_employees4(int, char **emp);  // TODO:

int main() {
  char name[10];
  char employees[3][10];

  for (int i = 0; i < 3; i++) {
    printf("Enter a name: ");
    gets(name);
    strcpy(employees[i], name);
  }

  print_employees3(3, employees);

  return 0;
}

void print_employees(int num, char emp[3][10]) {
  for (int i = 0; i < num; i++) {
    printf("%s\n", emp[i]);
  }
}

void print_employees1(int num, char emp[][10]) {
  for (int i = 0; i < num; i++) {
    printf("%s\n", emp[i]);
  }
}

void print_employees3(int num, char (*emp)[10]) {
  for (int i = 0; i < num; i++) {
    printf("%s\n", emp++);
  }
}
