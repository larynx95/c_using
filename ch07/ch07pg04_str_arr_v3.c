/*
# Pointer and 2D array
  pointing at
  pointing range

# Declaration and initialization with compound literal

  char <symbols> <part A> [...] = (type conversion) <part B>
       +-------+ +------+ +---+   +---------------+ +------+
       * or **   var      bracket type conversion   array literal
  +---------------------------+   +------------------------+
  (1) array or pointer            (2) compund literal
  char arr[R][C]                        -          {"ax", "zy"}
                                  (char [R][C])    {"ax", "zy"}
  char *ptr                       (char *)         {"ax", "zy"}
  char *ptr[R]                    (char *[R])      {"ax", "zy"}
  char *ptr[R][C]                 (char *[R][C])   {"ax", "zy"}
  char (*ptr)[C]                  (char (*)[C])    {"ax", "zy"}
  char (*ptr)[R][C]               (char (*)[R][C]) {"ax", "zy"}
  char **ptr                      (char **)        {"ax", "zy"}

I. One step: Initialize with compund literal

  char arr[R][C]    = {"ax", "zy"};                  --------------[O]
                    = (char [R][C]){"ax", "zy"}      --------------[X]??
                    = (char *){"ax", "zy"}           --------------[X]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[X]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[X]
                    = (char **){"ax", "zy"}          --------------[X]
  char *ptr         = {"ax", "zy"};                  --------------[.]
                    = (char [R][C]){"ax", "zy"}      --------------[O]
                    = (char *){"ax", "zy"}           --------------[.]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[.]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[.]
                    = (char **){"ax", "zy"}          --------------[.]
  char *ptr[R]      = {"ax", "zy"};                  --------------[O]
                    = (char [R][C]){"ax", "zy"}      --------------[X]
                    = (char *){"ax", "zy"}           --------------[X]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[X]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[X]
                    = (char **){"ax", "zy"}          --------------[X]
  char *ptr[R][C]   = {"ax", "zy"};                  --------------[O]
                    = (char [R][C]){"ax", "zy"}      --------------[X]
                    = (char *){"ax", "zy"}           --------------[X]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[X]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[X]
                    = (char **){"ax", "zy"}          --------------[X]
  char (*ptr)[C]    = {"ax", "zy"};                  --------------[.]
                    = (char [R][C]){"ax", "zy"}      --------------[O]
                    = (char *){"ax", "zy"}           --------------[.]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[.]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[.]
                    = (char **){"ax", "zy"}          --------------[.]
  char (*ptr)[R][C] = {"ax", "zy"};                  --------------[.]
                    = (char [R][C]){"ax", "zy"}      --------------[O]
                    = (char *){"ax", "zy"}           --------------[?]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[.]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[.]
                    = (char **){"ax", "zy"}          --------------[.]
  char **ptr        = {"ax", "zy"};                  --------------[?]
                    = (char [R][C]){"ax", "zy"}      --------------[O]
                    = (char *){"ax", "zy"}           --------------[.]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[.]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[.]
                    = (char **){"ax", "zy"}          --------------[.]

II. Two steps: Initialize with other pointer or address

  char *ptr = &arr;           --------------[O]
  char *ptr[R] = &arr;        --------------[X]
  char *ptr[R][C] = &arr;     --------------[X]
  char (*ptr)[C] = &arr;      --------------[O]
  char (*ptr)[R][C] = &arr;   --------------[O]
  char **ptr = &arr;          --------------[.]

III. double pointer

  char **dptr = &arr;    char arr[R][C] = {"ax", "zy"};           --[ ]
  char **dptr = &ptr;    char *ptr = {"ax", "zy"};                --[ ]
                                   = (char [][]){"ax", "zy"};     --[ ]
                                   = (char *){"ax", "zy"};        --[ ]
                                   = (char *[R]){"ax", "zy"};     --[X]
                                   = (char *[R][C]){"ax", "zy"};  --[X]
                                   = (char (*)[C]){"ax", "zy"};   --[.]
                                   = (char (*)[R][C]){"ax", "zy"};--[ ]
*/

#include <stdio.h>
#define R 2
#define C 3

int main() {
  /////////////////////////////////////////////////////////
  // I. One Step                                         //
  /////////////////////////////////////////////////////////

  /********************************************************
  [O] char arr[R][C] = {"ax", "zy"};
  arr+0 -> arr[0] == *(arr+0) -> arr[0][0] == *(*(arr+0)+0) == 'a'
                                 arr[0][1] == *(*(arr+0)+1) == 'x'
                                 arr[0][2] == *(*(arr+0)+2) =='\0'
  arr+1 -> arr[1] == *(arr+1) -> arr[1][0] == *(*(arr+1)+0) == 'z'
                                 arr[1][1] == *(*(arr+1)+1) == 'y'
                                 arr[1][2] == *(*(arr+1)+2) == '\0'
  ********************************************************/
  char str[R][C] = {"ax", "zy"};

  /* // print addresses
  printf("str        : %p\n", str);
  printf("&str       : %p\n", &str);
  printf("str        : %p\n", str);
  printf("str[0]     : %p\n", str[0]);
  printf("&str[0]    : %p\n", &str[0]);
  printf("&str[0][0] : %p\n", &str[0][0]);

  // print strings
  for (int i = 0; i < R; i++) {
    printf("str[%d]: %s\n", i, str[i]);
  }

  for (int i = 0; i < R; i++) {
    printf("*(str+%d): %s\n", i, *(str + i));
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("str[%d][%d]: %c\n", i, j, str[i][j]);
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(str+%d)+%d): %c\n", i, j, *(*(str + i) + j));
    }
  }

  printf("\n"); */

  /********************************************************
  [.] char *ptr = {"ax", "zy"};
  ptr == a -> a[0] == *(ptr+0) == 'a'
              a[1] == *(ptr+1) == 'x'
              a[2] == *(ptr+2) == '\0'
  - The second string "zy" vanishes.
  ********************************************************/
  /* char *a1p = {"ax", "zy"};

  // print string
  printf("a1p: %s\n", a1p);

  // print characters
  printf("*(a1p+0):%c, *(a1p+1): %c\n", *(a1p + 0), *(a1p + 1));

  printf("\n"); */

  /********************************************************
  [O] char *ptr = (char[R][C]){"ax", "zy"};
  ptr+C*0 == a -> a[0] -> a[0][0] == *(ptr+C*0+0) == 'a'
                          a[0][1] == *(ptr+C*0+1) == 'x'
                          a[0][2] == *(ptr+C*0+2) == '\0'
                  a[1] -> a[1][0] == *(ptr+C*1+0) == 'z'
                          a[1][1] == *(ptr+C*1+1) == 'y'
                          a[1][2] == *(ptr+C*1+2) == '\0'
  ********************************************************/
  /* char *a2p = (char[R][C]){"ax", "zy"};

  // print string
  for (int i = 0; i < R; i++) {
    printf("a2p+C*%d: %s\n", i, a2p + C * i);
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(a2p+C*%d+%d): %c\n", i, j, *(a2p + C * i + j));
    }
  }

  printf("\n"); */

  /********************************************************
  [.] char *ptr = (char *){"ax", "zy"};
  ptr = p => a == ptr+0 -> a[0] == *(ptr+0) == 'a'
                  ptr+1 -> a[1] == *(ptr+1) == 'x'
                  ptr+2 -> a[2] == *(ptr+2) == '\0'
  ********************************************************/
  /* char *a3p = (char *){"ax", "zy"};

  // print string
  printf("a3p: %s\n", a3p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(a3p+%d): %c\n", i, *(a3p + i));
  }

  printf("\n"); */

  /********************************************************
  [X] char *ptr = (char *[R]){"ax", "zy"};  (X)
  ********************************************************/

  /********************************************************
  [X] char *ptr = (char *p[R][C]){"ax", "zy"};  (X)
  ********************************************************/

  /********************************************************
  [.] char *ptr = (char (*)[C]){"ax", "zy"};
  ptr == p => a == ptr+0 -> a[0] == *(ptr+0) == 'a'
                   ptr+1 -> a[1] == *(ptr+1) == 'x'
                   ptr+2 -> a[2] == *(ptr+2) == '\0'
  ********************************************************/
  /* char *a6p = (char(*)[C]){"ax", "zy"};

  // print string
  printf("a6p: %s\n", a6p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(a6p+%d): %c\n", i, *(a6p + i));
  }

  printf("\n"); */

  /********************************************************
  [.] char *ptr = (char (*)[R][C]){"ax", "zy"};
  ********************************************************/
  /* char *a7p = (char(*)[R][C]){"ax", "zy"};

  // print string
  printf("a7p: %s, *a7p: %c\n", a7p, *a7p);

  // print characterss
  printf("*(a7p+0): %c, *(a7p+1): %c\n", *(a7p + 0), *(a7p + 1));

  printf("\n"); */

  /********************************************************
  [.] char *ptr = (char **){"ax", "zy"};
  ********************************************************/
  /* char *a8p = (char **){"ax", "zy"};

  // print string
  printf("a8p: %s, *a8p: %c\n", a8p, *a8p);

  // print characters
  printf("*(a8p+0): %c, *(a8p+1): %c\n", *(a8p + 0), *(a8p + 1));

  printf("\n"); */

  /********************************************************
  [O] char *ptr[R] = {"ax", "zy"};
  ptr -> ptr[0] -> "ax"
         ptr[1] -> "zy"
  ptr -> ptr[0] == *(ptr+0) == a -> a[0] == *(*(ptr+0)+0) == 'a'
                                    a[1] == *(*(ptr+0)+1) == 'x'
                                    a[2] == *(*(ptr+0)+2) == '\0'
         ptr[1] == *(ptr+1) == b -> b[0] == *(*(ptr+1)+0) == 'z'
                                    b[1] == *(*(ptr+1)+1) == 'y'
                                    b[2] == *(*(ptr+1)+2) == '\0'
  ********************************************************/
  /* char *b1p[R] = {"ax", "zy"};

  // print strings
  for (int i = 0; i < R; i++) {
    printf("b1p[%d]: %s\n", i, b1p[i]);
  }

  for (int i = 0; i < R; i++) {
    printf("b1p+%d: %s\n", i, b1p + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*(b1p+%d): %s\n", i, *(b1p + i));
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(b1p+%d)+%d): %c\n", i, j, *(*(b1p + i) + j));
    }
  }

  printf("\n"); */

  /********************************************************
  [X] char *ptr[R] = (char [R][C]){"ax", "zy"};
  ********************************************************/
  // char *b2p[2] = (char[R][C]){"ax", "zy"};

  /********************************************************
  [X] char *ptr[R] = (char *){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R] = (char *[R]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R] = (char *[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R] = (char (*)[C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R] = (char (*)[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R] = (char **){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [O] char *ptr[R][C] = {"ax", "zy"};
  ptr[0][0] -> "ax"
  ptr[0][1] -> "zy"
  ********************************************************/
  /* char *c1p[R][C] = {"ax", "zy"};

  // print strings
  printf("c1p[0][0]: %s, c1p[0][1]: %s\n", c1p[0][0], c1p[0][1]);

  // print characters
  for (int i = 0; i < R; i++) {
    printf("*c1p[0][%d]: %c\n", i, *c1p[0][i]);
  }

  printf("\n"); */

  /********************************************************
  [X] char *ptr[R][C] = (char [R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R][C] = (char *){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R][C] = (char *[R]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R][C] = (char *[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R][C] = (char (*)[C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R][C] = (char (*)[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char *ptr[R][C] = (char **){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [.] char (*ptr)[C] = {"ax", "zy"};
  ptr -> a == *ptr-> a[0] == *(*ptr+0) == 'a'
                     a[1] == *(*ptr+1) == 'x'
                     a[2] == *(*ptr+2) == '\0'
  ********************************************************/
  /* char(*d1p)[C] = {"ax", "zy"};

  // print strings
  printf("d1p: %s, *d1p; %s\n", d1p, *d1p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d1p+%d): %c\n", i, *(*d1p + i));
  }

  printf("\n"); */

  /********************************************************
  [O] char (*ptr)[C] = (char [R][C]){"ax", "zy"}
  ptr+0 --> a == *(ptr+0) --> a[0] == *(*(ptr+0)+0) == 'a'
                              a[1] == *(*(ptr+0)+1) == 'x'
                              a[2] == *(*(ptr+0)+2) == '\0'
  ptr+1 --> b == *(ptr+1) --> b[0] == *(*(ptr+1)+0) == 'z'
                              b[1] == *(*(ptr+1)+1) == 'y'
                              b[2] == *(*(ptr+1)+2) == '\0'
  ********************************************************/
  /* char(*d2p)[C] = (char[R][C]){"ax", "zy"};

  // print strings
  for (int i = 0; i < R; i++) {
    printf("d2p+%d: %s\n", i, d2p + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*d2p+%d: %s\n", i, *(d2p + i));
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(d2p+%d)+%d): %c\n", i, j, *(*(d2p + i) + j));
    }
  }

  printf("\n"); */

  /********************************************************
  [.] char (*ptr)[C] = (char *){"ax", "zy"};
               *     **
  ptr == p --> a --> a[0]
                     a[1]
                     a[2]
  ********************************************************/
  /* char(*d3p)[C] = (char *){"ax", "zy"};

  // print string
  printf("d3p: %s, *d3p: %s, **d3p: %c\n", d3p, *d3p, **d3p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d3p+%d): %c\n", i, *(*d3p + i));
  }

  printf("\n"); */

  /********************************************************
  [X] char (*ptr)[C] = (char *[R]){"ax", "zy"};
  one pointer      two pointers
  char (*ptr)[3] = (char *[2])
  ********************************************************/

  /********************************************************
  char (*ptr)[C] = (char *[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [.] char (*ptr)[C] = (char (*)[C]){"ax", "zy"};
               *     **
  ptr == p --> a --> a[0] == *(*d6p + 0) == 'a'
                     a[1] == *(*d6p + 1) == 'x'
                     a[2] == *(*d6p + 2) == '\0'
  ********************************************************/
  /* char(*d6p)[C] = (char(*)[C]){"ax", "zy"};

  // print string
  printf("d6p: %s, *d6p: %s, **d6p: %c\n", d6p, *d6p, **d6p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d6p+%d): %c\n", i, *(*d6p + i));
  }

  printf("\n"); */

  /********************************************************
  [.] char (*ptr)[C] = (char (*)[R][C]){"ax", "zy"};
  ********************************************************/
  /* char(*d7p)[C] = (char(*)[R][C]){"ax", "zy"};

  // print string
  printf("d7p: %s, *d7p: %s, **d7p: %c\n", d7p, *d7p, **d7p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d7p+%d): %c\n", i, *(*d7p + i));
  }

  printf("\n"); */

  /********************************************************
  [.] char (*ptr)[C] = (char **){"ax", "zy"};
  ********************************************************/
  /* char(*d8p)[C] = (char **){"ax", "zy"};

  // print string
  printf("d8p: %s, *d8p: %s, **d8p: %c\n", d8p, *d8p, **d8p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d8p+%d): %c\n", i, *(*d8p + i));
  }

  printf("\n"); */

  /********************************************************
  [.] char (*ptr)[R][C] = {"ax", "zy"};
  ********************************************************/
  /* char(*e1p)[R][C] = {"ax", "zy"};

  // print string
  printf("*e1p: %s, **e1p: %s, ***e1p: %c\n", *e1p, **e1p, ***e1p);

  // print characters
  printf("**e1p: %s\n", **e1p);

  for (int i = 0; i < R; i++) {
    printf("*(*(*e1p+0)+%d): %c\n", i, *(*(*e1p + 0) + i));
  }

  printf("\n"); */

  /********************************************************
  [O] char (*ptr)[R][C] = (char [R][C]){"ax", "zy"};
  ptr -> a+0 == *ptr+0 -> a[0] == *(*ptr+0) -> a[0][0]
                                               a[0][1]
                                               a[0][2]
         a+1 == *ptr+1 -> a[1] == *(*ptr+1) -> a[1][0]
                                               a[1][1]
                                               a[1][2]
  ********************************************************/
  char(*e2p)[R][C] = (char[][3]){"ax", "zy"};

  // print strings
  for (int i = 0; i < R; i++) {
    printf("*e2p+%d: %s\n", i, *e2p + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*(*e2p+%d): %s\n", i, *(*e2p + i));
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(*e2p+%d)+%d): %c\n", i, j, *(*(*e2p + i) + j));
    }
  }

  printf("\n");

  /********************************************************
  [.] char (*ptr)[R][C] = (char *){"ax", "zy"};
  ********************************************************/
  /* char(*e3p)[R][C] = (char *){"ax", "zy"};

  // print string
  printf("e3p: %s, *e3p: %s, **e3p: %s\n", e3p, *e3p, **e3p);

  // print characters
  printf("***e3p: %c\n", ***e3p);

  for (int i = 0; i < C - 1; i++) {
    printf("*(**e3p+%d): %c\n", i, *(**e3p + i));
  }

  printf("\n");
 */
  /********************************************************
  [X] char (*ptr)[R][C] = (char *[R]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char (*ptr)[R][C] = (char *[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [.] char (*ptr)[R][C] = (char (*)[C]){"ax", "zy"};
  ********************************************************/
  /* char(*e6p)[R][C] = (char(*)[C]){"ax", "zy"};

  // print string
  printf("e6p: %s, *e6p: %s, **e6p: %s\n", e6p, *e6p, **e6p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(**e6p+%d): %c\n", i, *(**e6p + i));
  }

  printf("\n"); */

  /********************************************************
  [.] char (*ptr)[R][C] = (char (*)[R][C]){"ax", "zy"};
  ********************************************************/
  /* char(*e7p)[R][C] = (char(*)[R][C]){"ax", "zy"};

  // print string
  printf("e7p: %s, *e7p: %s, **e7p: %s\n", e7p, *e7p, **e7p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(**e7p+%d): %c\n", i, *(**e7p + i));
  }

  printf("\n"); */

  /********************************************************
  [.] char (*ptr)[R][C] = (char **){"ax", "zy"};
  ********************************************************/
  /* char(*e8p)[R][C] = (char **){"ax", "zy"};

  // print string
  printf("e8p: %s, *e8p: %s, **e8p: %s\n", e8p, *e8p, **e8p);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(**e8p+%d): %c\n", i, *(**e8p + i));
  }

  printf("\n"); */

  /********************************************************
  [?] char **dptr = {"ax", "zy"};
  ********************************************************/
  /* char **f1p = {"ax", "zy"};

  // print string
  printf("f1p: %s, *f1p: %c\n", f1p, *f1p);

  // print characters
  printf("f1p: %c\n", *f1p);

  printf("\n"); */

  /********************************************************
  [.] char **ptr = (char [R][C]){"ax", "zy"};
  ********************************************************/
  /* char **f2p = (char[R][C]){"ax", "zy"};

  // print string
  printf("f2p: %s, *f2p: %c\n", f2p, *f2p);

  // print characters
  printf("f2p: %c\n", *f2p);

  printf("\n"); */

  /********************************************************
  [.] char **ptr = (char *){"ax", "zy"};
  ********************************************************/
  /* char **f3p = (char *){"ax", "zy"};

  // print string
  printf("f3p: %s, *f3p: %c\n", f3p, *f3p);

  // print characters
  printf("f3p: %c\n", *f3p);

  printf("\n"); */

  /********************************************************
  [X] char **ptr = (char *[R]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char **ptr = (char *[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [.] char **ptr = (char (*)[C]){"ax", "zy"};
  ********************************************************/
  /* char **f6p = (char(*)[C]){"ax", "zy"};

  // print string
  printf("f6p: %s, *f6p: %c\n", f6p, *f6p);

  // print characters
  printf("f6p: %c\n", *f6p);

  printf("\n"); */

  /********************************************************
  [.] char **ptr = (char (*)[R][C]){"ax", "zy"};
  ********************************************************/
  /* char **f7p = (char(*)[R][C]){"ax", "zy"};

  // print string
  printf("f7p: %s, *f7p: %c\n", f7p, *f7p);

  // print characters
  printf("f7p: %c\n", *f7p);

  printf("\n"); */

  /********************************************************
  [.] char **ptr = (char **){"ax", "zy"};
  ********************************************************/
  /* char **f8p = (char **){"ax", "zy"};

  // print string
  printf("f8p: %s, *f8p: %c\n", f8p, *f8p);

  // print characters
  printf("f8p: %c\n", *f8p);

  printf("\n"); */

  /////////////////////////////////////////////////////////
  // II. Two Steps                                       //
  /////////////////////////////////////////////////////////

  /********************************************************
  [0] char *ptr = &arr;
  ********************************************************/
  /* char *dat = &str;

  // print string
  for (int i = 0; i < R; i++) {
    printf("dat+C*%d: %s\n", i, dat + C * i);
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(a9p+%d*%d+%d): %c\n", i, C, j, *(dat + C * i + j));
      // "zy" was printed!
    }
  }

  printf("\n"); */

  /********************************************************
  [X] char *ptr[R] = &arr;
  ********************************************************/

  /********************************************************
  [X] char *ptr[R][C] = &arr;
  ********************************************************/

  /********************************************************
  [O] char (*ptr)[C] = &arr;
  ********************************************************/
  /* char(*ddt)[C] = &str;

  // print string
  for (int i = 0; i < R; i++) {
    printf("ddt+%d: %s\n", i, ddt + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*(ddt+%d): %s\n", i, *(ddt + i));
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(ddt+%d)+%d: %c\n", i, j, *(*(ddt + i) + j));
    }
  }

  printf("\n"); */

  /********************************************************
  [O] char (*ptr)[R][C] = &arr;
  ptr -> arr == *ptr+0 -> arr[0] == *(*ptr+0)-> arr[0][0] == *(*(*ptr+0)+0)
                                                arr[0][1] == *(*(*ptr+0)+1)
                                                arr[0][2] == *(*(*ptr+0)+2)
                *ptr+1 -> arr[1] == *(*ptr+1)-> arr[1][0] == *(*(*ptr+1)+0)
                                                arr[1][1] == *(*(*ptr+1)+1)
                                                arr[1][2] == *(*(*ptr+1)+2)
  ********************************************************/
  /* char(*det)[R][C] = &str;

  // print string
  printf("%s %s %c\n", *det, **det, ***det);

  for (int i = 0; i < R; i++) {
    printf("*det+%d: %s\n", i, *det + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*(*det+%d): %s\n", i, *(*det + i));
  }

  // print characters
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(*det+%d)+%d): %c\n", i, j, *(*(*det + i) + j));
    }
  }

  printf("\n"); */

  /********************************************************
  [.] char **dptr = &arr;
  ********************************************************/
  /* char **dft = &str;

  // print string
  printf("dft: %s\n", dft);

  // print characters
  printf("*dft: %c\n", *dft);

  printf("\n"); */

  /////////////////////////////////////////////////////////
  // III. Double Pointer                                 //
  /////////////////////////////////////////////////////////

  /********************************************************
  [.] char **dptr = &arr;
  ********************************************************/

  /********************************************************
  [.] char **dptr = &ptr; char *ptr = {"ax", "zy"};
  ********************************************************/
  /* char **d1ptr = &a1p;

  // print string
  printf("*d1ptr: %s\n", *d1ptr);

  // print character
  printf("**d1ptr: %c\n", **d1ptr);

  printf("\n"); */

  /********************************************************
  [O] char **dptr = &ptr; char *ptr = (char [R][C]){"ax", "zy"};
  ********************************************************/
  /* char *a2p = (char[R][C]){"ax", "zy"};
  char **d2ptr = &a2p;

  // print string
  for (int i = 0; i < R; i++) {
    printf("*d2ptr+C*%d: %s\n", i, *d2ptr + C * i);
  }

  // print character
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*d2ptr+C*%d+%d): %c\n", i, j, *(*d2ptr + C * i + j));
    }
  }

  printf("\n"); */

  /********************************************************
  [.] char **dptr = &ptr; char *ptr = (char *){"ax", "zy"};
  dptr -> ptr == *(dptr+0) => a -> a[0] == **(dptr+0) == 'a'
                 *(dptr+1)      -> a[1] == **(dptr+0) == 'x'
                 *(dptr+2)      -> a[2] == **(dptr+0) == '\0'
  ********************************************************/
  /* char **d3ptr = &a3p;

  // print string
  printf("*d3ptr: %s\n", *d3ptr);

  // print character
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d3ptr+%d): %c\n", i, *(*d3ptr + i));
  }

  printf("\n"); */

  /********************************************************
  [X] char **dptr = &ptr; char *ptr = (char *[R]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [X] char **dptr = &ptr; char *ptr = (char *[R][C]){"ax", "zy"};
  ********************************************************/

  /********************************************************
  [.] char **dptr = &ptr; char *ptr = (char (*)[C]){"ax", "zy"};
  dptr -> ptr == *(dptr+0) == p => a -> a[0] == *(*dptr+0) == 'a'
                 *(dptr+1)           -> a[1] == *(*dptr+1) == 'x'
                 *(dptr+2)           -> a[2] == *(*dptr+2) == '\0'
  ********************************************************/
  /* har **d6ptr = &a6p;

  // print string
  printf("*d6ptr: %s\n", *d6ptr);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d6ptr+%d): %c\n", i, *(*d6ptr + i));
  } */

  /********************************************************
  [] char **dptr = &ptr; char *ptr = (char (*)[R][C]){"ax", "zy"};
  dptr == p -> a == *dptr -> a[0] == *dptr+0 -> a[0][0] == *(*dptr+0) == 'a'
                                     *dptr+1 -> a[0][1] == *(*dptr+1) == 'x'
                                     *dptr+2 -> a[0][2] == *(*dptr+2) == '\0'
  ********************************************************/
  /* char **d7ptr = &a7p;

  // print string
  printf("*d7ptr: %s\n", *d7ptr);

  // print characters
  for (int i = 0; i < C - 1; i++) {
    printf("*(*d7ptr+%d): %c\n", i, *(*d7ptr + i));
  }

  printf("\n"); */

  /////////////////////////////////////////////////////////
  // IV. The End                                        //
  /////////////////////////////////////////////////////////

  printf("The End");
  return 0;
}