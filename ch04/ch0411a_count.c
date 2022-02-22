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
  Extracting a substring from a string (Program example 6)
  Inserting a string in the main string (Program example 7)
  Pattern matching
  Deleting a substring from the main string (Program example 8)
  Replacing a pattern with another pattern in a string (Program example 9)
4.3 Arrays of strings (Program example 10 ~ 12)
*/

/*
Program Example 11.
Write a program to read multiple lines of text and
then count the number of characters, words, and lines in the text.

1. counting characters
- count all, except EOF (Ctrl+Z)

2. counting words
- word consist of only characters
- special characters are not word: space, '\0', EOF, '\t', '\n' ...
- counting continues till EOF

3. counting lines
- lines are divided by line breaker: '\n'

K and R, C programming language
*/

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main() {
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {  // EOF Ctrl+Z
    ++nc;
    if (c == '\n') ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}

/*
* Word count
  - Each word is separated by non-alphabet character(s).

* TODO: Implement `split()` fx.
        Implement a function creating an array of words
*/
