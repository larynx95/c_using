/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
2. Define a structure to store the name, an array marks[]
which stores the marks of three different subjects,
and a character grade.

Write a program to display the details of the student whose name
is entered by the user.

- (option) Use the structure definition of the first question to make an array
of students. Display the name of the students who have secured less than 40% of
the aggregate.

TODO: Structure can have the same data twice.
      Is there 'set' concept in C array?
TODO: Which is the better between pointer and value
      in passing structure to a function?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  char name[20];
  int marks[3];
  char grade;
};

void create_student(struct student*);
void print_student(struct student*);

int main() {
  struct student students[4] = {
      {.name = "Jonna", .marks = {100, 90, 99}, .grade = 'A'},
      {.name = "Jonna", .marks = {100, 90, 99}, .grade = 'A'},
      {.name = "Kimberly", .marks = {50, 90, 45}, .grade = 'C'},
      {.name = "Joanna", .marks = {70, 76, 85}, .grade = 'B'}};

  char name[10];
  printf("Enter the name: ");
  scanf("%s", name);

  for (int i = 0; i < 4; i++) {
    if (strcmp(students[i].name, name) == 0) {
      print_student(&students[i]);
    }
  }

  return 0;
}

void create_student(struct student* st) {
  printf("Enter name: ");
  scanf("%s", st->name);
  printf("Enter three marks: ");
  scanf("%d %d %d", st->marks[0], st->marks[1], st->marks[2]);
  printf("Enter grade: ");
  scanf("%c", st->grade);
}

void print_student(struct student* st) {
  printf("Name: %s\n", st->name);
  printf("Marks: %d, %d, %d\n", st->marks[0], st->marks[1], st->marks[2]);
  printf("Grade: %c\n", st->grade);
}
