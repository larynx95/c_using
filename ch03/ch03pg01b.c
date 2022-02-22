/* Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 1.
Consider an array MARKS[20][5]
which stores the marks obtained by 20 students in 5 subjects.
Now write a program to

(a) find the average marks obtained in each subject.
(b) find the average marks obtained by every student.
(c) find the number of students who have scored below 50 in their average.
(d) display the scores obtained by every student.
*/

#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 2

void user_input(int rows, int cols, int **);
void print_arr(int rows, int cols, int **);
void avg_each_student(int rows, int cols, int **);
void avg_each_subject(int rows, int cols, int **);
void below_fifty(int row, int cols, int **);

int main() {
  int MARKS[ROWS][COLS];
  int **ptr = MARKS;
  user_input(ROWS, COLS, ptr);

  // (a)
  avg_each_student(ROWS, COLS, ptr);

  // (b)
  avg_each_subject(ROWS, COLS, ptr);

  // (c)
  below_fifty(ROWS, COLS, ptr);

  // (d)
  print_arr(ROWS, COLS, ptr);

  return 0;
}

/* user input */
void user_input(int rows, int cols, int **arr) {
  for (int i = 0; i < rows; i++) {
    printf("Marks of strudent (%d): \n", i);
    for (int j = 0; j < cols; j++) {
      int temp;
      scanf("%d", *(arr + i) + j);
    }
  }
}

/* print array*/
void print_arr(int rows, int cols, int **arr) {
  for (int i = 0; i < rows; i++) {
    printf("Marks of student (%d): \n", i);
    for (int j = 0; j < cols; j++) {
      printf("\tMark of subject (%d): %d\n", j, *(*(arr + i) + j));
    }
    printf("\n");
  }
  printf("\n");
}

void avg_each_student(int rows, int cols, int **arr) {
  for (int i = 0; i < rows; i++) {
    printf("Average marks of student (%d): ", i);
    int sum = 0;
    for (int j = 0; j < cols; j++) {
      sum += *(*(arr + i) + j);
    }
    printf("%.2f\n", sum / (cols * 1.0));
  }
  printf("\n");
}

void avg_each_subject(int rows, int cols, int **arr) {
  for (int j = 0; j < cols; j++) {
    printf("Average marks of subject (%d): ", j);
    int sum = 0;
    for (int i = 0; i < rows; i++) {
      sum += *(*(arr + i) + j);
    }
    printf("%.2f\n", sum / (rows * 1.0));
  }
  printf("\n");
}

void below_fifty(int rows, int cols, int **arr) {
  int num = 0;
  for (int i = 0; i < rows; i++) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
      sum += *(*(arr + i) + j);
    }
    if (sum / (rows * 1.0) < 50.0) num++;
  }
  printf("The number of students (avg < 50): %d\n", num);
}