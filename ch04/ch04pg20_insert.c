/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
20. Write a program to insert "University" in the given string "Oxford Press" so
that the string should read as "Oxford University Press".
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char univ[11] = "University";
  char oxfo[13] = "Oxford Press";
  char out[30];
  char *pu = univ;
  char *po = oxfo;
  char *pout = out;

  /* Oxford */
  while (*po != '\0' && *po != ' ') {
    *pout++ = *po++;
  }
  *pout++ = ' ';
  po++;

  /* University */
  while (*pu != '\0') {
    *pout++ = *pu++;
  }
  *pout++ = ' ';

  /* Press */
  while (*po != '\0') {
    *pout++ = *po++;
  }
  *pout = '\0';

  printf("%s\n", out);

  return 0;
}
