/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
26. Write a program to read a short story. Rewrite
the story by printing the line number before the
starting of each line.

# My Plan
- prepend '0: ' at the beginning of text
- find '\n' and replace it with '\n[n]: '
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /* user input */
  char text[50];
  char res[100] = "";
  printf("Enter a short story (<100 characters): ");
  char ch;
  char *ptr = text;
  while ((ch = getchar()) != EOF) {
    *ptr++ = ch;
  }
  printf("\nYou've entered this text:\n");
  printf("%s\n", text);

  /* append and create a new text */
  strcat(res, "0: ");
  char *qtr = text;
  int i = 1;
  while (*qtr != '\0') {
    if (*qtr != '\n') {
      char temp[2];
      sprintf(temp, "%c", *qtr);
      strcat(res, temp);
    } else {
      char temp[5];
      sprintf(temp, "\n%d: ", i++);
      strcat(res, temp);
    }
    qtr++;
  }

  printf("\nLine number added: \n");
  printf("%s\n", res);

  return 0;
}
