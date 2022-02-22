/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises
10. Write a program to reverse a string using recursion.

# algorithms
1) iteration
2) stack
3) recursion
(1) swapping
  idx 0  1  2  3  4 (len==5)
      a* b  c  d*\0 swap str[0] and str[len-2]
      d  b* c* a \0 swap str[1] and str[len-2-1]
      d  c  b  a \0 swap str[2] and str[len-2-2]
(2)
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************
 * Iteration
 **********************************************************/

void revs_iter1(int len, char str[]) {
  int i = 0;
  while (len - 2 - i >= 0) {
    printf("%c", str[len - 2 - i]);
    i++;
  }
}

void revs_iter2(int len, char str[]) {
  for (int i = len - 2; i >= 0; i--) {
    printf("%c", str[i]);
  }
}

void revs_iter3(int len, char str[], char out[]) {
  int i = 0;
  while (len - 2 - i >= 0) {
    out[i] = str[len - 2 - i];
    i++;
  }
  out[i] = '\0';
}

void revs_iter4(int len, char str[], char out[]) {
  int i = 0;
  while (len - 2 - i >= 0) {
    *out++ = str[len - 2 - i];
    i++;
  }
  out[i] = '\0';
}

void revs_iter5(int len, char str[], char out[]) {
  int i = 0;
  while (len - 2 - i >= 0) {
    out[i] = str[len - 2 - i];
    i++;
  }
  out[i] = '\0';
}

/**********************************************************
 * recursion
 **********************************************************/

/*
  idx 0  1  2  3  4 (len==5)
      a  b  c  d \0

f("abc") = f("bc")               print "a"
         = f("c")     print "b"
         = print "c"

https://www.geeksforgeeks.org/reverse-a-string-using-recursion/
*/
void revs_rec1(char *str) {
  if (*str) {
    revs_rec1(str + 1);
    printf("%c", *str);
  }
}

/* swapping
  idx 0  1  2  3  4 (len==5)
      a* b  c  d*\0 swap str[0] and str[len-2]
      d  b* c* a \0 swap str[1] and str[len-2-1]
      d  c  b  a \0 swap str[2] and str[len-2-2]

https://www.programmingsimplified.com/c-program-reverse-string
*/
void revs_rec2(char *x, int begin, int end) {
  char c;
  if (begin >= end) return;

  c = *(x + begin);
  *(x + begin) = *(x + end);
  *(x + end) = c;

  revs_rec2(x, ++begin, --end);
}

/**********************************************************
 * stack
 **********************************************************/

int main() {
  char *str = "abc";  // length 4
  char atr[4] = "abc";
  char out[4];

  revs_rec1(atr);
  revs_rec2(atr, 0, 2);
  printf("%s\n", atr);

  return 0;
}
