/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
14. Write a program to input a text of at least two
paragraphs. Construct an array PAR such that
PAR[I] contains the location of the ith paragraph
in text
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char name[15];
  // Taking a name as an input.
  // name can only include alphabets
  scanf("%[a-zA-Z]", name);
  printf("%s", name);

  return 0;
}
