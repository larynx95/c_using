/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
27. Write a program to enter a text that contains multiple lines.
Display the n lines of text starting from the m th line.

# My Plan
- multiple lines
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  /* n, m */
  char n, m;
  printf("Enter a starting line number: ");
  scanf("%c", &m);
  printf("Enter the number of lines: ");
  scanf("%c ", &n);
  getchar();

  /* user text input */
  char text[50];
  char res[100] = "";
  printf("Enter a short story (<100 characters): ");
  char ch;
  char *ptr = text;
  while ((ch = getchar()) != EOF) {
    *ptr++ = ch;
  }
  ptr = '\0';

  /* append and create a new text */
  strcat(res, "0: ");
  ptr = &text[0];
  int i = 1;
  while (*ptr != '\0') {
    if (*ptr != '\n') {
      char temp[2];
      sprintf(temp, "%c", *ptr);
      strcat(res, temp);
    } else {
      char temp[5];
      sprintf(temp, "\n%d: ", i++);
      strcat(res, temp);
    }
    ptr++;
  }

  printf("\nLine number added: \n");
  printf("%s\n", res);

  /* result m=1, n=2
  0: aaa
  1: bbb     *
  2: ccc     *
  3: ddd
  TODO: Why error?
  */
  ptr = &text[0];
  i = 0;
  while (*ptr != m) ptr++;
  while (i < n) {
    if (*ptr == '\n') i++;
    printf("%c", *ptr++);
  }

  return 0;
}
