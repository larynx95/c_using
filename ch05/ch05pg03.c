/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
3. Modify Question 2 to print each student’s average
marks and the class average
(that includes average of all the student’s marks).

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
void print_avg(struct student*);
void print_class_avg(struct student arr[]);

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

  for (int i = 0; i < 4; i++) {
    if (strcmp(students[i].name, name) == 0) {
      print_avg(&students[i]);
    }
  }

  print_class_avg(students);

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

void print_avg(struct student* st) {
  printf("Name: %s\n", st->name);
  float avg = (st->marks[0] + st->marks[1] + st->marks[2]) / 3.0;
  printf("Average of makrs: %.2f\n", avg);
  printf("Grade: %d\n", st->grade);
}

void print_class_avg(struct student arr[4]) {
  float avg_class[3];
  for (int i = 0; i < 3; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += arr[j].marks[i];
    }
    avg_class[i] = sum / 3.0;
  }
  for (int i = 0; i < 3; i++) {
    printf("Average of class %d: %.2f\n", i, avg_class[i]);
  }
}