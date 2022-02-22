/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays
3.1 Introduction
3.2 Declaration of arrays
3.3 Accessing the elements of an array
  3.3.1 Calculating the address of array elements (Example 3.1)
  3.3.2 Calculating the length of an array (Example 3.2)
3.4 Storing values in arrays
  Initializing arrays during declaration
  Inputting values from the keyboard
  Assigning values to individual elements
3.5 Operations on arrays
  3.5.1 Traversing an array (Program example 1 ~ 6)
  3.5.2 Onserting an element in an array (Example 3.3)
    Algorithm to insert an elem in the middle of an arr (Program example 7 ~ 8)
  3.5.3 Deleting an element from an array (Example 3.4)
    Algorithm to delete an elem from the middle of an array
    (Program example 9 ~ 10)
  3.5.4 Merging two arrays (Program example 11 ~ 12)
3.6 Passing arrays to functions
  3.6.1 Passing individual elements
    Passing data values
    passing addresses
  3.6.2 Passing the entire array (Program example 13 ~ 14)
3.7 Pointers and arrays (Program example 15)
3.8 Arrays of pointers
3.9 Two-dimensional arrays
  3.9.1 Declaring two-dimensional arrays (Example 3.5)
  3.9.2 Initializing two-dimensional arrays
  3.9.3 Accessing the elements of two-dimensional arrays
       (Program example 16 ~ 19)
******************************************************************************/

/*
Prpgram Example 17.
Write a program to generate Pascal’s triangle.

https://en.wikipedia.org/wiki/Pascal%27s_triangle

TODO: practice for linked list approach
[[01], [01,01], [01,02,01], [01,03,03,01], ... ]
   1        2           3              4

  01             2 spaces  level 2 (2*2 - 2 = 2)
01  01           0 spaces
[01, 01, 01]
  0   1   2

    01           4 spaces  level 3 (2*3 - 2 = 4)
  01  01         2 spaces
01  02  01       0 spaces
[01, 01, 01, 01, 02, 01]
  0   1   2   3   4   5
[01, 02, 01]
  0   1   2

      01         6 spaces  level 4 (2*4 - 2 = 6: 2*(level-0) - 2)
    01  01       4 spaces                        2*(level-1) - 2
  01  02  01     2 spaces                        2*(level-2) - 2
01  03  03  01   0 spaces                        2*(level-3) - 2
[01, 01, 01, 01, 02, 01, 01, 03, 03, 01]
  0   1   2   3   4   5   6   7   8   9
[01, 02, 01]
[01, 03, 03, 01]

        01            8 spaces
      01  01          6 spaces
    01  02  01        4 spaces
  01  03  03  01      2 spaces
01  04  06  04  01    0 spaces
[01, 01, 01, 01, 02, 01, 01, 03, 03, 01, 01, 04, 06, 04, 01]
  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
[01, 02, 01]
[01, 03, 03, 01]
[01, 04, 06, 04, 01]
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLVL 10

typedef struct Nd {
  int level;
  int ar[MAXLVL];  // TODO: Can I use int *ar[] or something instead?
  struct Nd *next;
} Nd;

Nd *create(Nd *);
Nd *add_level(Nd *, int);
// TODO: Implement delete_level fx.
void print_ar(Nd *);
void print_pascal(Nd *);

int main() {
  Nd *start = NULL;
  start = create(start);
  start = add_level(start, 3);
  start = add_level(start, 4);
  start = add_level(start, 5);

  print_ar(start->next->next);
  printf("\n");

  print_pascal(start);

  return 0;
}

Nd *create(Nd *start) {
  /* add first level: {1} */
  Nd *fst = malloc(sizeof(Nd));
  fst->ar[0] = 1;
  fst->level = 1;
  fst->next = NULL;

  /* add second level: {1,1} */
  Nd *snd = malloc(sizeof(Nd));
  snd->ar[0] = 1;
  snd->ar[1] = 1;
  snd->level = 2;

  /* start */
  fst->next = snd;
  snd->next = NULL;

  start = fst;

  return start;
}

Nd *add_level(Nd *start, int lvl) {
  /* we need both previous and current Nd pointer  */
  Nd *cur = start;
  while (cur->next != NULL) cur = cur->next;

  /* create a new node */
  Nd *new = malloc(sizeof(Nd));
  new->level = lvl;
  new->next = NULL;
  new->ar[0] = 1;
  new->ar[lvl - 1] = 1;
  for (int i = 0; i < lvl - 2; i++) {
    new->ar[i + 1] = cur->ar[i] + cur->ar[i + 1];
    // printf("%d = %d + %d\n", new->ar[i + 1], cur->ar[i], cur->ar[i + 1]);
  }

  /* add the new node to the end of the linked list */
  cur->next = new;

  return start;
}

void print_ar(Nd *ptr) {
  for (int i = 0; i < ptr->level; i++) {
    printf("%02d  ", ptr->ar[i]);
  }
}

void print_pascal(Nd *start) {
  /* find the last node */
  Nd *ptr = start;
  while (ptr->next != NULL) ptr = ptr->next;

  int lvl = ptr->level;
  ptr = start;
  for (int i = 0; i < lvl; i++) {
    printf("%*s", 2 * (lvl - i) - 2, "");  // for leading spaces
    print_ar(ptr);
    printf("\n");
    ptr = ptr->next;
  }
}