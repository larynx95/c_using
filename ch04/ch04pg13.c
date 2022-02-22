/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
13. Write a program to input a text of at least two paragraphs.
Interchange the first and second paragraphs
and then re-display the text on the screen.

# My Plan
- paragraphs are divided by '\n' character.

TODO: Read multiple lines with scanf fx.
https://stackoverflow.com/questions/13592875/reading-multiple-lines-of-input-with-scanf
*/

#include <stdio.h>
#include <stdlib.h>

void two_paragraphs(char *str, char *apg, char *bpg);

int main() {
  char str[50] = "abc \n dfg";
  char apg[25], bpg[25];

  /* string containing a line breaking special character */
  two_paragraphs(str, apg, bpg);

  return 0;
}

/* change the order of two paragraphs */
void two_paragraphs(char *str, char *apg, char *bpg) {
  int idx = 0;
  int i = 0;
  int j = 0;

  while (str[idx] != '\n') {
    apg[i] = str[idx];
    idx++;
    i++;
  }
  idx++;
  apg[i] = '\0';

  while (str[idx] != '\0') {
    bpg[j] = str[idx];
    j++;
    idx++;
  }
  j++;
  bpg[j] = '\0';

  printf("%s\n", bpg);
  printf("%s", apg);
}