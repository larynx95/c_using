/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
9. Write a program to count the total number of occurrences of a word in the
text.

TODO:
- Find more info about `gets` fx.
- local array in a function!
- strtok fx.
  https://wiki.sei.cmu.edu/confluence/display/c/STR06-C.+Do+not+assume+that+strtok%28%29+leaves+the+parse+string+unchanged#space-menu-link-content
  The strtok() function parses the string up to the first instance of the
  delimiter character, replaces the character in place with a null byte ('\0'),
  and returns the address of the first character in the token.
  Subsequent calls to strtok() begin parsing immediately after the most recently
  placed null character.

# My Plan
1. Not creating array of words
2. Creating array of words (implementing split or strtok fx.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  */
char *test1(char *str, char *temp) {
  char *ptr = temp;
  while (*str != '\0' && *str != ' ') {
    *ptr++ = *str++;
  }
  *ptr = '\0';
  return temp;
}

/* */
void test2(char *str, char *temp, char *par[5]) {
  int idx = 0;
  char *beg = temp;
  while (*str != '\0') {
    char *ptr = beg;
    if (*str != ' ') {
      while (*str != '\0' && *str != ' ') {
        *ptr++ = *str++;
      }
      *ptr = '\0';
      strcpy(par[idx++], temp);
    }
    str++;
  }
}

int main() {
  char *str = "ab cd e fgh   ";
  char *temp = malloc(sizeof(char) * 5);
  char *par[5];
  for (int i = 0; i < 5; i++) {
    par[i] = malloc(sizeof(char) * 5);
    *par[i] = '\0';
  }

  /* test for test 1 function */
  /* printf("%s\n", test1(str, temp));
  free(temp); */

  /* test for test 2 function */
  test2(str, temp, par);
  for (int i = 0; i < 5; i++) {
    printf("par[%d]: %s\n", i, par[i]);
  }

  /* free */
  for (int i = 0; i < 5; i++) {
    free(par[i]);
  }

  free(temp);

  return 0;
}