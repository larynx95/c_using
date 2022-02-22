/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings
4.1 Introduction
  4.1.1 Reading Strings: scanf(), gets(), getchar(), getch(), getche()
  4.1.2 Writing strings
4.2 Operations on strings
  Finding length of a string (Program example 1)
*/

/*
Program Example 1.
Write a program to find the length of a string.
*/

#include <stdio.h>
#include <stdlib.h>

int str_len(char *);
int str_len_rec(char *);

int main() {
  /* gets() */
  char str[100], length = 0;
  printf("Enter the string: ");
  gets(str);

  while (str[length] != '\0') length++;
  printf("The length of the string is : %d\n", length);

  printf("%d \n", str_len_rec(str));

  /* getchar() */
  printf("Enter a string: ");
  int i = 0;
  char btr[10];
  char ch = getchar();
  while (ch != '\n' && ch != EOF) {
    btr[i++] = ch;
    ch = getchar();
  }
  btr[i] = '\0';
  printf("btr: %s\n", btr);

  /* getchar() */
  printf("Enter a string: ");
  char ctr[10];
  i = 0;
  while (1) {
    int ch = getchar();
    if (ch == '\n' || ch == EOF) {
      ctr[i] = '\0';
      break;
    } else {
      ctr[i++] = ch;
    }
  }
  printf("ctr: %s\n", ctr);

  return 0;
}

int str_len(char *str) {
  int number = 0;
  while (*str++ != '\0') {
    number++;
  }
  return number;
}

int str_len_rec(char *str) {
  if (*str == '\0') return 0;
  return 1 + str_len_rec(str + 1);
}