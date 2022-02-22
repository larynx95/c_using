/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
16. Write a program to concatenate two given strings "Good Morning" and "World".
Display the resultant string.
*/

#include <stdio.h>
#include <stdlib.h>

void myconcat(char *astr, char *bstr, char *ostr);

int main() {
  char astr[13] = "Good Morning";
  char bstr[6] = "World";
  char ostr[20];

  myconcat(astr, bstr, ostr);
  printf("%s\n", ostr);

  return 0;
}

void myconcat(char *astr, char *bstr, char *ostr) {
  while (*astr != '\0') {
    *ostr++ = *astr++;
  }
  *ostr++ = ' ';
  while (*bstr != '\0') {
    *ostr++ = *bstr++;
  }
  *ostr = *bstr;
}