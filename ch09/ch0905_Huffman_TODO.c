/* Data Structures Using C, 2nd, Reema Thareja
Chapter 09. Trees
9.1 Introduction
9.2 Types of trees
9.3 Creating a binary tree from a general tree
9.4 Traversing a binary tree
9.5 Huffman's tree
*/

/*
* Youtube
https://www.youtube.com/watch?v=dM6us854Jk0
https://www.youtube.com/watch?v=co4_ahEDCho

* Terminology
- Variable length code (== Prefix code)
- data to be transferred: characters + decoding table
- Key point: compressing bits of characters with high frequencies

- Given n nodes and their weights,
  the Huffman algorithm is used to find a tree
  with a minimum-weighted path length.
- internal path length(IPL): sum of all depth of each node in binary tree
- external path length(EPL): sum of all depth of newly-add nodes
                              in extended binary tree

* HUffman's algorithm
(1)
  A       B       C       D       E       F       G       H       I       J
  7       9      11      14      18      21      27      29      35      40
(2)
    16      C       D       E       F       G       H       I       J
   / \     11      14      18      21      27      29      35      40
  A7 B9
(3)
    16       25      E       F       G       H       I       J
   / \      / \     18      21      27      29      35      40
  A7 B9   C11 D14
(4)
     25         34       F       G       H       I       J
    / \        / \      21      27      29      35      40
  C11 D14    16  E18
                / \
              A7  B9
(5)
     34          46       G       H       I       J
    / \         / \       27      29      35      40
  16  E18     25  F21
     / \     / \
   A7  B9  C11 D14
(6)
     34          46         56        I        J
    / \         / \        / \       35      40
  16  E18     25  F21    G27 H29
     / \     / \
   A7  B9  C11 D14
(7)
        46         56          69        J
       / \        / \         / \       40
     25  F21    G27 H29     34 I35
    / \                    / \
  C11 D14                16  E18
                        / \
                      A7  B9
(8)
     56          69          86
    / \         / \         / \
  G27 H29     34 I35      46  J40
             / \         / \
           16  E18     25  F21
          / \         / \
        A7  B9      C11 D14
(9)
              125                86
             /   \              / \
           56    69           46  J40
         /  \   /  \         / \
      G27 H29  34  I35     25  F21
              / \         / \
            16  E18     C11 D14
           / \
         A7  B9
(10)
                        211
                 /              \
              125                86
             /   \              / \
           56    69           46  J40
         /  \   /  \         / \
      G27 H29  34  I35     25  F21
              / \         / \
            16  E18     C11 D14
           / \
         A7  B9

* Concepts
  1. frequency table (already-given data)
    characters   freq
    -----------------
    A           10
    E           15
    I           12
    S            3
    T            4
    P           13
    \n           1

  2. Create a code tree (not sorted)
    Left traversal = 0, Right traversal = 1
                O
           0/      \1
          O         O
       0/  \1    0/  \1
      O    O     O    O
    0/ \ 0/ \  0/ \ 0/
    A  E I  S  T  P /n

    characters  code   freq    total bits (length * freq)
    -------------------------------------
    A           000   10       30 (3 * 10)
    E           001   15       45
    I           010   12       36
    S           011    3       12
    T           100    4       12
    P           101   13       39
    \n          110    1        3   Total: 174 bits

    a. bits of code * freq => 174 bits
    b. characters          => 7 * 8 bits = 56 bits (characer == 1 byte)
    c. codes               => 7 * 3 bits = 21 bits
                              --------------------
                              Real total bits = 251 bits

  3. Create a code tree (sorted)
  1) Creating a tree 1 (Total bits = 146, best)
  - creating a tree with two characters with MIN and the next MIN frequencies.
    ('\n', 1), ('S', 3), ('T', 4), ('A', 10), ('I', 12), ('P', 13), ('E', 15)
                                18         18       25          18    25
                               / \        / \      / \         / \   / \
                   8          8  A       8  A     I  p        8  A  I  p
                  / \       / \        / \                  / \
      4          4  T      4  T       4  T                 4  T
     / \       / \       / \        / \                  / \
    \n S      \n S     \n S        \n S                 \n S
    (1)       (2)       (3)        (4!!)                (5)

    In step 4, the number 18 is greater than all remaining requencies.
    So, create a another subtree with 'I'(12) and 'P'(13).

                                         58
                                        /  \
               33                     33   25
              / \                    / \   / \
            18  E      25          18  E  I  P
           / \        / \         / \
          8  A       I  p        8  A
        / \                    / \
       4  T                   4  T
     / \                    / \
    \n S                   \n S
    (6)                   (7)

    characters  code     freq  total bits (length * freq)
    -------------------------------------
    \n          00000    1     5 * 1 = 5
    S           00001    3     5 * 3 = 15
    T            0001    4     4 * 4 = 16
    A             001   10     3 * 10 = 30
    I              01   12     2 * 12 = 24
    P              11   13     2 * 13 = 26
    E              10   15     2 * 15 = 30    Total bits = 146

    a. bits of code * freq => 146 bits
    b. characters          => 7 * 8 bits = 56 bits
    c. codes               => 5+5+4+3+2+2+2 = 23 bits
                              --------------------
                              Real total bits = 225 bits

  2) creating tree 2 (Total bits: 161, not best)
  - Let's just add the lowest node, not the lowest two.
    ('\n', 1), ('S', 3), ('T', 4), ('A', 10), ('I', 12), ('P', 13), ('E', 15)
                  58
                 / \
                43 E
               / \
              30 P
             / \
            18 I
           / \
          8  A
         / \
        4  T
       / \
      \n S

    characters  code      freq  total bits (length * freq)
    -------------------------------------
    \n          000000    1     6 * 1 = 6
    S           000001    3     6 * 3 = 18
    T            00001    4     5 * 4 = 20
    A             0001   10     4 * 10 = 40
    I              001   12     3 * 12 = 36
    P               01   13     2 * 13 = 26
    E                1   15     1 * 15 = 15  Total bits = 161

    a. bits of code * freq => 161 bits
    b. characters          => 7 * 8 bits = 56 bits
    c. codes               => 6+6+5+4+3+2+1 = 27 bits
                              --------------------
                              Real total bits = 244 bits

* TODO: Implement Huffman's tree (array and llk versions)
  - Sort data structure by frequency and get frequency table.
  - Create a tree by Huffman's algorithm.
  - Get char-freq-binary table
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 20

void print_charr(char *);  // print arr
void print_intarr(int, int *);
int get_freq(char *, char);  // get frequency
int get_freq_rec(char *, char);
int get_sz(char *);  // get size of character array
int get_sz_rec(char *);
int is_in(char, char *);  // check whetehr a char in char array
int is_in_rec(char, char *);
void get_set(char *, char *);
void get_set2(char *);
char *get_set3(char *);
void sort_cnt(int, int *);

int main() {
  char str[20] = "abbcdefffghiaaajkkk";
  char out[20];
  out[0] = '\0';

  return 0;
}

/* print int array */
void print_intarr(int sz, int *arr) {
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/* print character array */
void print_charr(char *str) {
  while (*str != '\0') {
    printf("%c ", *str);
    str++;
  }
  printf("\n");
}

/* get frequency of a character in the character array */
int get_freq(char *str, char ch) {
  int fq = 0;
  while (*str != '\0') {
    if (*str == ch) fq++;
    str++;
  }
  return fq;
}

/* get frequency of a character in the character array, recursion */
int get_freq_rec(char *str, char ch) {
  if (*str == '\0')
    return 0;
  else {
    if (*str == ch) {
      return 1 + get_freq_rec(str + 1, ch);
    } else {
      return get_freq_rec(str + 1, ch);
    }
  }
}

/* get array size */
int get_sz(char *str) {
  int total = 0;
  while (*str++ != '\0') total++;
  return total;
}

/* get array size, recursion */
int get_sz_rec(char *str) {
  if (*str == '\0') return 0;
  return 1 + get_sz_rec(str + 1);
}

/* check if a character is in the character array */
int is_in(char ch, char *str) {
  while (*str != '\0') {
    if (*str == ch) return 1;
    str++;
  }
  return 0;
}

/* check if a character is in the character array, recursion */
int is_in_rec(char ch, char *str) {
  if (*str == '\0')
    return 0;
  else if (*str != '\0' && *str == ch)
    return 1;
  else
    is_in_rec(ch, str + 1);
}

/* get set from character array */
void get_set(char *orig, char *out) {
  char *fst = out;
  int sz = get_sz(orig);
  while (*orig != '\0') {
    if (!is_in(*orig, fst)) {
      *out++ = *orig;
      *out = '\0';
    }
    orig++;
  }
}

/* get set from character array, using local array */
void get_set2(char *str) {
  int i = 0, j = 0, sz = get_sz(str);
  char tmp[sz + 1], *sp = str;
  tmp[0] = '\0';  // initilaize array before using it

  // get unique elements
  while (*sp != '\0') {
    if (!is_in(*sp, tmp)) {
      tmp[i] = *sp;
      i++;
      tmp[i] = '\0';
    }
    sp++;
  }

  // modify original array
  while (tmp[j] != '\0') {
    *str++ = tmp[j++];
  }
  *str = '\0';
}

/* get set from character array: TODO:  */
char *get_set3(char *str) {
  int i = 0, j = 0, sz = get_sz(str);
  char tmp[sz + 1], *sp = str;
  tmp[0] = '\0';

  while (*sp != '\0') {
    if (!is_in(*sp, tmp)) {
      tmp[i] = *sp;
      i++;
      tmp[i] = '\0';
    }
    sp++;
  }

  sp = str;
  while (tmp[j] != '\0') {
    *sp++ = tmp[j++];
  }
  *sp = '\0';

  return str;
}

/* count sort: https://www.programiz.com/dsa/counting-sort */
void sort_cnt(int size, int *array) {
  int output[10];
  // get the max value
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) max = array[i];
  }
  // initilize empty array (for counting frequency) with zero
  int count[10];
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }
  // get frequency array `count`
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  // get accumulated frequency array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}