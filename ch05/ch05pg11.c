/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
11. Write a program using pointer to structure to
initialize the members of an employee structure.
Use functions to print the employee’s information.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[10];
  int salary;
} EMPLOYEE;

void init_struct(EMPLOYEE *, char *, int);
void print_struct(EMPLOYEE *);

int main() {
  EMPLOYEE *man;
  man = malloc(sizeof(EMPLOYEE));

  init_struct(man, "kim", 1000);
  print_struct(man);

  free(man);

  return 0;
}

void init_struct(EMPLOYEE *man, char name[10], int salary) {
  strcpy(man->name, name);
  man->salary = salary;
}

void print_struct(EMPLOYEE *man) {
  printf("Name: %s, Salary: %d\n", man->name, man->salary);
}