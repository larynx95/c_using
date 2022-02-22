/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings
4.1 Introduction
  4.1.1 Reading Strings: scanf(), gets(), getchar(), getch(), getche()
  4.1.2 Writing strings
4.2 Operations on strings
  Finding length of a string (Program example 1)
  Converting characters of a string into upper/lower case (Program example 2)
  Appending a string to another string (Program example 3)
  Comparing two strings (Program example 4)
  Reversing a string (Program example 5)
*/

/*
Program Example 5.
Write a program to reverse a given string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rev();
void rev_ptr(char *);
void rev_rec(int, char *);  // TODO: Implement this.
char *head(char *);
char *last(int, char *);
char *tail(int, char *);
char *append(char, int, char *);

int main() {
  /* rev fx. */
  rev();

  /* head fx. */
  char *str = "abcd";
  printf("Head of \"%s\": %c\n", str, head(str));

  /* last fx. */
  printf("Last of \"%s\": %c\n", str, last(sizeof(str), str));

  /* tail fx. */
  char *tail_str = tail(5, str);
  printf("Tail of \"%s\": %s\n", str, tail_str);
  free(tail_str);

  /* append fx. */
  char fst = 'a';
  char *btr = "bcd";
  char *res = append(fst, 4, btr);
  printf("Append result: %c + %s = %s\n", fst, btr, res);
  free(res);

  return 0;
}

void rev() {
  char str[100];
  char temp;
  int i = 0, j = 0;

  printf("Enter the string: ");
  gets(str);

  j = strlen(str) - 1;
  while (i < j) {
    temp = str[j];
    str[j] = str[i];
    str[i] = temp;
    i++;
    j--;
  }

  printf("The reversed string is: ");
  puts(str);
}

/*
* Reversing a string in C
  https://stackoverflow.com/questions/784417/reversing-a-string-in-c

* Different methods to reverse a string in C/C++
  https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/

* TODO: recursive?
*/

/* head fx.
size    6
index   0 1 2 3 4 5
string  a b c d e \0
head    a (str[0])
*/
char *head(char *str) { return *str; }

/* last fx.
size    6
index   0 1 2 3 4 5
string  a b c d e \0
last    e (str[size - 2])
*/
char *last(int sz, char *str) { return *(str + sz - 2); }

/* tail fx.
size    6
index   0 1 2 3 4 5
string  a b c d e \0
tail      b c d e \0
*/
char *tail(int sz, char *str) {
  char *res = malloc(sizeof(char) * (sz - 1));
  char *ptr = res;
  int i = 1;
  while (i < sz) {
    *ptr++ = *(str + (i++));
  }
  return res;
}

/*
chr   'a'
str    "bcd"
res   "abcd"
*/
char *append(char chr, int sz, char *str) {
  char *res = malloc(sizeof(char) * (sz + 1));
  char *ptr = res;
  *ptr++ = chr;
  while (*str != '\0') {
    *ptr++ = *str++;
  }
  *ptr = '\0';
  return res;
}

/* TODO: Implement recursive reverse string fx. */