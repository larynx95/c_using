/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises (optional)
4. Dealing with multidimensional character array (summary)

# Pointer and 2D array
  pointing at
  pointing range

# Declare and initialize with compund literal

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

# One step: Initialize with compund literal

  char arr[R][C]    = {"ax", "zy"};                  --------------[O]
                    = (char [R][C]){"ax", "zy"}      --------------[X]??
                    = (char *){"ax", "zy"}           --------------[X]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[X]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[X]
                    = (char **){"ax", "zy"}          --------------[X]
  char *ptr         = {"ax", "zy"};                  --------------[.]
                    = (char [R][C]){"ax", "zy"}      --------------[X]
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
                    = (char [R][C]){"ax", "zy"}      --------------[.]
                    = (char *){"ax", "zy"}           --------------[.]
                    = (char *[R]){"ax", "zy"}        --------------[X]
                    = (char *[R][C]){"ax", "zy"}     --------------[X]
                    = (char (*)[C]){"ax", "zy"}      --------------[.]
                    = (char (*)[R][C]){"ax", "zy"}   --------------[.]
                    = (char **){"ax", "zy"}          --------------[.]

# Two steps

  char *ptr = &arr;           --------------[O]
  char *ptr[R] = &arr;        --------------[X]
  char *ptr[R][C] = &arr;     --------------[X]
  char (*ptr)[C] = &arr;      --------------[O]
  char (*ptr)[R][C] = &arr;   --------------[O]
  char **ptr = &arr;          --------------[.]

# double pointer

  char **dptr = &arr;    char arr[R][C] = {"ax", "zy"};           --[ ]   
  char **dptr = &ptr;    char *ptr = {"ax", "zy"};                --[ ]      
                                   = (char [R][C]){"ax", "zy"};   --[ ]         
                                   = (char *){"ax", "zy"};        --[ ]      
                                   = (char *[R]){"ax", "zy"};     --[ ]         
                                   = (char *[R][C]){"ax", "zy"};  --[ ]            
                                   = (char (*)[C]){"ax", "zy"};   --[ ]           
                                   = (char (*)[R][C]){"ax", "zy"};--[ ]              
*/

#include <stdio.h>
#define R 2
#define C 3

int main() {
  /********************************************************
  I. 1D character array - array, pointer
  - `char *ptr` can point to
    i. a character
    ii. the first character in an array of characters

  ptr    value
  -------------------------------------------
  ptr => a[0] == *(ptr+0) == 'a'
         a[1] == *(ptr+1) == 'x'
         a[2] == *(ptr+2) == '\0'

   ********************************************************/
  printf("1. char str or char * ptr\n");

  /* 1. array */
  char as[3] = "ax";
  char bs[3] = {'a', 'x', '\0'};
  for (int i = 0; i < C - 1; i++) {
    printf("as[%d]: %c\n", i, as[i]);  // a x
  }
  printf("\n");

  /* 2. pointer */
  char single_char = 'a';
  char* ptr2single_char = &single_char;
  // char * ptr2songle_char = 'a'; // (X) not working

  char* aptr = "zy";  // immutable
  char* bptr = as;    // not &as (Notice this feature in C language!)

  while (*aptr) {
    printf("*aptr++: %c\n", *aptr++);  // z y
  }
  printf("\n");

  /* 2-2-ii. */
  for (int i = 0; i < C; i++) {
    printf("*(bptr+%d): %c\n", i, *(bptr + i));  // a x
  }
  printf("\n");

  /* 2-2-iii. */
  // char* cptr = {'a', 'a', '\0'};
  // printf("cptr: %c\n", cptr);  // TODO: error

  /********************************************************
  II. char str[2][3]
  - array name is not pointer
    but it can be used as pointer
  - points to: str == &str == *str == str[0] == &str[0] == &str[0][0]
    size: 3

  a             *(a+i)                *(*(a+i)+j)
  a --> a[0] == *(a+0) --> a[0][0] == *(*(a+0)+0) == 'a'
                           a[0][1] == *(*(a+0)+1) == 'x'
                           a[0][2] == *(*(a+0)+2) == '\0'
        a[1] == *(a+1) --> a[1][0] == *(*(a+1)+0) == 'b'
                           a[1][1] == *(*(a+1)+1) == 'y'
                           a[1][2] == *(*(a+1)+2) == '\0'

  ********************************************************/
  printf("2. 2D array of characters\n");

  /* 1. */
  char str[R][C] = {"ax", "zy"};

  /* array name, pointer, address */
  printf(" str  : %p, str+1 : %p\n", str, str + 1);    // diff 3
  printf("str[0]: %p, str[1]: %p\n", str[0], str[1]);  // diff 3

  printf("*str  : %p\n", *str);
  printf("&str  : %p\n", &str);
  printf(" str  : %p\n", str[0]);
  printf("str   : %p\n", &str[0]);
  printf("str   : %p\n", &str[0][0]);

  printf("*str[0]  : %p\n", *str[0]);  // not the same as above
  printf("**str    : %p\n", **str);
  printf("str[0][0]: %p\n", str[0][0]);

  /* printing each string */
  for (int i = 0; i < R; i++) {
    printf("str + %d: %s\n", i, str + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*(str + %d): %s\n", i, *(str + i));
  }

  /* printing each character */
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(str+%d)+%d): %c\n", i, j, *(*(str + i) + j));
    }
  }

  /********************************************************
  III. char *ptr
  ********************************************************/
  printf("3. single pointer\n");

  /* 1-1. char *ptr = {"ax", "zy"};
  - Actually, this is not good because of type mismatch.
  - details
    points to: a character or an array of characters ("zy" vanishes!)
    dereferencing: ptr => *ptr (no more)
  - diagram (p: pointer, a: anonymous temporary array name)
    p --> a --> a[0] --> a[0][0] == 'a'
                         a[0][1] == 'x'
                         a[0][2] == '\0'
                a[1] --> a[1][0] == 'z'
                         a[1][1] == 'y'
                         a[1][2] == '\0'
                (As soon as p is initialized, a[1] will vanish!)
  */
  char* a1p = {"ax", "zy"};

  /* pointer size */
  printf("a1p: %p, a1p+1: %p\n", a1p, a1p + 1);  // diff 1

  for (int i = 0; i < C - 1; i++) {
    printf("*(a1p+%d): %c\n", *(a1p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(a1p+%d*%d+%d): %c\n", i, C, j, *(a1p + C * i + j));
      // "zy" vanishes!
    }
  }

  printf("\n");

  /* 1-2. */
  char* a2p = (char[R][C]){"ax", "zy"};

  printf("a2p: %s, a2p+1: %s\n", a2p, a2p + 1);

  printf("\n");

  /* 1-3. */
  char* a3p = (char * [R]){"ax", "zy"};

  printf("a3p: %c\n", *a3p);

  printf("\n");

  /* 1-4. */
  char* a4p = (char * [R][C]){"ax", "zy"};

  printf("a4p: %c\n", *a4p);

  printf("\n");

  /* 1-5. */
  char* a5p = (char(*)[C]){"ax", "zy"};

  printf("a5p: %s, *a5p: %c\n", a5p, *a5p);

  printf("\n");

  /* 1-6. */
  char* a6p = (char(*)[R][C]){"ax", "zy"};

  printf("a6p: %s, *a6p: %c\n", a6p, *a6p);

  printf("\n");

  /* 1-7. */
  char* a7p = (char**){"ax", "zy"};

  printf("a7p: %s, *a7p: %c\n", a7p, *a7p);

  printf("\n");

  /* 2-1. char *ptr = &str
  - str == &str == str[0] == &str[0] == &str[0][0]
  - details: same as above
  - In this case, str[1] will not vanish, because str exists somewhere.
  - daigram
  p --> str --> str[0] --> str[0][0] == 'a'
                           str[0][1] == 'x'
                           str[0][2] == '\0'
                str[1] --> str[1][0] == 'z'
                           str[1][1] == 'y'
                           str[1][2] == '\0'
                (Array str exists somewhere, so it will not vanish.)
  */
  char* a9p = str;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(a9p+%d*%d+%d): %c\n", i, C, j, *(a9p + C * i + j));
      // "zy" was printed!
    }
  }

  printf("\n");

  /********************************************************
  IV. char *ptr[R]
  ********************************************************/
  printf("4. array of pointers\n");

  /* 1. char* apr[N] = {"ax", "zy"};
  - details
    not pointer, but array of N pointers
    dereferencing: apr[i] (pointer)
                   *apr[i] (points to an array of N characters)
  - diagram (pr: array pf pointers)
    apr[0] --> "ax"
    apr[1] --> "zy"
  - (Be careful) "ax" and "zy" already have their memory addresses.
    Two addresses may not be consecutive(?) (check this)
  */
  char* b1r[R] = {"ax", "zy"};

  /* TODO: check memory address: consecutive or not? */
  printf("b1r[0]: %p, b1r[1]: %p\n", b1r[0], b1r[1]);  // not 3, unexpected

  for (int i = 0; i < R; i++) {
    printf("b1r[%d]: %s\n", i, b1r[i]);
  }

  for (int i = 0; i < R; i++) {
    printf("*(b1r+%d): %s\n", i, *(b1r + i));  // b1r + i, (X)
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(b1r + %d) + %d): %c\n", i, j, *(*(b1r + i) + j));
    }
  }

  /* 1-2.
  apr[0] --> &str[0]
  apr[1] --> &str[1]
  */
  char* b2r[R];  // can't be initialized with array one step.
  b2r[0] = &str[0];
  b2r[1] = &str[1];

  printf("b2r[0]: %p, b2r[1]: %p\n", b2r[0], b2r[1]);  // diff 3, as expected

  printf("\n");

  /********************************************************
  V. char* ptr[R][C]
  - ptr is 2D array of pointers to character(s)
  - ptr[0][0] is not a character (value) here, but a pointer to
        a. a charactr
        b. an array of characters
    and stores address of one of above targets.
  - If it points to a character, it will be this shape.
    *ptr[0] == *(ptr+0) --> *ptr[0][0] == *(*ptr+0) --> 'a'
                            *ptr[0][1] == *(*ptr+1) --> 'x'
                            *ptr[0][2] == *(*ptr+2) --> '\0'
    *ptr[1] == *(ptr+1) --> *ptr[1][0] == *(*ptr+3) --> 'b'
                            *ptr[1][1] == *(*ptr+4) --> 'y'
                            *ptr[1][2] == *(*ptr+5) --> '\0'
  - If it points to an array of characters, it will be this shape.
    *ptr[0] == *(ptr+0) --> *ptr[0][0] == *(*ptr+0) --> "ax"
                            *ptr[0][1] == *(*ptr+1) --> "by"
                            *ptr[0][2] == *(*ptr+2) --> NULL
    *ptr[1] == *(ptr+1) --> *ptr[1][0] == *(*ptr+3) --> NULL
                            *ptr[1][1] == *(*ptr+4) --> NULL
                            *ptr[1][2] == *(*ptr+5) --> NULL
  - Which will happen?
    Can it be vary depending on how you declare or initialize it?
  ********************************************************/
  printf("5. 2D array of pointers\n");

  /* 1. `char *apr[][] = {"ax", "by"};`
  - details
    not a pointer, but 2D array of pointers
  - Our '2D array of pointers' was initialized as follows.
            *apr       **apr
    apr --> apr[0] --> apr[0][0] --> "ax"
                       apr[0][1] --> "zy"
                       apr[0][2] --> NULL
            apr[1] --> apr[1][0] --> NULL
                       apr[1][1] --> NULL
                       apr[1][2] --> NULL
  */
  char* c1p[R][C] = {"ax", "zy", "yy", "rr"};

  /* just check the addresses of pointer variables */
  printf("c1p       : %p\n", c1p);
  printf("c1p[0]    : %p\n", c1p[0]);
  printf("&c1p[0]   : %p\n", &c1p[0]);
  printf("*(c1p+0)  : %p\n", *(c1p + 0));
  printf("&c1p[0][0]: %p\n", &c1p[0][0]);
  printf("\n");

  /* Only the first two pointer elements of 2D array was initialized. */
  printf("**c1p: %s\n", **c1p);
  printf("***c1p: %c\n", ***c1p);
  printf("*(*(c1p+1)+0): %s\n", *(*(c1p + 1) + 0));
  printf("c1p[0][0]: %s\n", c1p[0][0]);
  printf("c1p[0][1]: %s\n", c1p[0][1]);
  printf("c1p[0][2]: %s\n", c1p[0][2]);
  printf("*(*c1p+0): %s\n", *(*c1p + 0));
  printf("*(*c1p+1): %s\n", *(*c1p + 1));
  printf("**(c1p+1): %s\n", **(c1p + 1));
  printf("*(*c1p + 3): %s\n", *(*c1p + 3));
  printf("\n");

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("*(*(c1p+%d)+%d): %s\n", i, j, *(*(c1p + i) + j));
    }
  }

  printf("\n");

  /* 2. Initialize `*ptr[]` one by one with string (NOT GOOD)
  - What would happen if we just initialize `*ptr[0]` pointer?
    Will the sub-pointers be initialized automatically? NEVER.
    char *ptr[][];
    *ptr[0] = &str[0] // or str[0]
    *ptr[1] = &str[1] // or str[1]
  - We didn't initialize all pointer elements of the 2D array of pointers.
    We just initilaized some of pointers incompletely.
  */
  char* c2p[R][C];
  for (int i = 0; i < R; i++) {
    *c2p[i] = &str[i];
  }

  for (int i = 0; i < R; i++) {
    printf("*c2p[%d]: %s\n", i, *c2p[i]);
  }

  printf("\n");

  /* 3. Initialize `*ptr[][]` one by one with string
  - We can initialize all of pointers in the 2D array of pointers.
  - we initilaize `*ptr[][]` with a character, not an array of characters.
  */
  char* c3p[R][C];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      c3p[i][j] = &str[i][j];
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*c3p[%d][%d]: %c\n", i, j, *c3p[i][j]);
    }
  }

  for (int i = 0; i < R; i++) {
    printf("*(*(c3p+%d)): %s\n", i, *(*(c3p + i)));
  }

  for (int i = 0; i < R; i++) {
    printf("**c3p + C * %d: %s\n", i, **c3p + C * i);
  }

  printf("\n");

  /********************************************************
  VI. char (*ptr)[C]
  ********************************************************/
  printf("6. pointer to array of N characters\n");

  /* 1-1. char(*ptr)[N] = {"ax", "zy"};
  - details
    points to array of N characters
    "zy" is not at the address where the pointer (ptr+1) points
    As soon as the ptr initialized, "zy" will vanish.
  - diagram
            *ptr  **ptr
    ptr --> a --> a[0] == 'a'
                  a[1] == 'x'
                  a[2] == '\0'
  */
  char(*d1p)[C] = {"ax", "by"};

  for (int i = 0; i < C - 1; i++) {
    printf("*(d1p+%d): %s\n", i, *(d1p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(d1p+%d)+%d): %c\n", i, j, *(*(d1p + i) + j));
    }
  }

  printf("\n");

  /* 1-2. char(*ptr)[C] = (char (*)[C]){"ax", "zy"};
  - details
    points to: array of C(3) characters
    The pointer 'ptr' can point to nothing more than it.
    "zy" will vanish.
  */
  char(*d2p)[C] = (char(*)[C]){"ax", "zy"};

  printf("d2p: %s\n", d2p);

  for (int i = 0; i < C - 1; i++) {
    printf("*(*(d2p+0)+%d): %c\n", i, *(*(d2p + 0) + i));
  }

  printf("\n");

  /* 1-3. char(*ptr)[C] = (char [R][C]){"ax", "zy"}
  - details
    points to: array of C(3) characters
    target: type converted to 2D array
            anonymous array stores "ax" and "zy" in consecutive mem staces(?)
            So, pointer arithmetic works!
  - diagram
                 *ptr
    ptr == a --> a[0] --> "ax"
                 a[1] --> "zy"
  */
  char(*d3p)[C] = (char[][C]){"ax", "zy"};
  for (int i = 0; i < R; i++) {
    printf("*(d3p+%d): %s\n", i, *(d3p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(d3p+%d)+%d): %c\n", i, j, *(*(d3p + i) + j));
    }
  }

  printf("\n");

  /* 1-4. char(*ptr)[C] = (char(*)[][C]){"ax", "zy"};
  - details
    points to: pointer to 2D array
    target:
  - diagram
    ptr --> a --> a[0]
                  a
   */
  char(*d4p)[C] = (char(*)[][C]){"ax", "by"};

  printf("d4p: %s, *d4p+1: %s, **d4p: %c\n", d4p, *d4p + 1, **d4p);

  printf("\n");

  /* 2-1. char(*ptr)[C] = str; */
  char(*d5p)[C] = str;
  for (int i = 0; i < R; i++) {
    printf("*(d5p+%d): %s\n", i, *(d5p + i));
  }

  printf("\n");

  /********************************************************
  VII. char(*ptr)[R][C] = {"ax", "zy"};
  ********************************************************/
  printf("7. pointer to 2D array of characters\n");

  /* 1-1. char(*ptr)[R][C] = {"ax", "zy"};
  - details
    points to: 2D array

  - diagram
    p --> a[0] == *p+0 --> a[0][0] == *(*(p+0)+0) == 'a'
                           a[0][1] == *(*(p+0)+1) == 'x'
                           a[0][2] == *(*(p+0)+2) == '\0'
    ~~~~~~~~~~~~~~~~~~~~~ can't see below ~~~~~~~~~~~~~~~~~~~~~
          a[1] == *p+1 --> a[1][0] == *(*(p+1)+1) == 'z'
                           a[1][1] == *(*(p+1)+2) == 'y'
                           a[1][2] == *(*(p+1)+3) == '\0'
  */
  char(*e1p)[R][C] = {"ax", "by"};
  // TODO:
  printf("e1p  : %p\n", e1p);
  printf("*e1p : %p, *e1p: %s\n", *e1p, *e1p);
  printf("**e1p: %p, **e1p: %s, ***e1p: %c\n", **e1p, **e1p, ***e1p);

  printf("e1p : %p, e1p+1: %p\n", e1p, e1p + 1);     // diff 6
  printf("*e1p: %p, *e1p+1: %p\n", *e1p, *e1p + 1);  // diff 3

  printf("e1p: %s, *e1p: %s, **e1p: %s, ***e1p: %c\n", e1p, *e1p, **e1p,
         ***e1p);

  printf("*e1p: %s\n", e1p);
  printf("e1p[0]: %s\n", e1p[0]);

  printf("*e1p: %p, *e1p+1: %p\n", *e1p, *e1p + 1);  // diff 3 byte
  printf("*e1p+3: %c\n", *e1p + 1);

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(*e1p + %d) + %d): %c\n", i, j, *(*(*e1p + i) + j));
    }
  }

  /* 1-2 char(*ptr)[R][C] = (char[][3]){"ax", "zy"};
  - details
  - diagram
            *ptr            **ptr                 ***ptr
    ptr --> a == *ptr+0 --> a[0] == *(*ptr+0) --> a[0][0]
                                                  a[0][1]
                                                  a[0][2]
                 *ptr+1 --> a[1] == *(*ptr+1) --> a[1][0]
                                                  a[1][1]
                                                  a[1][2]
  */
  char(*e2p)[R][C] = (char[][3]){"ax", "zy"};

  for (int i = 0; i < R; i++) {
    printf("*e2p+%d: %s\n", i, *e2p + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*(*e2p+%d): %s\n", i, *(*e2p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(*e2p+%d)+%d): %c\n", i, j, *(*(*e2p + i) + j));
    }
  }

  printf("\n");

  /* 2-1. */
  char(*e3p)[R][C] = &str;

  for (int i = 0; i < R; i++) {
    printf("*e3p + %d: %s\n", i, *e3p + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*e3p + %d: %s\n", i, *(*e3p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(*e3p + %d) + %d): %c\n", i, j, *(*(*e3p + i) + j));
    }
  }

  printf("\n");

  /********************************************************
  VIII. Double pointers
  ********************************************************/
  printf("8. double pointer\n");

  /* 1.
    char** dptr = {"ax", "zy"};
    char** dptr = (char [R][C]){"ax", "zy"};
    char** dptr = (char*){"ax", "zy"};
    char** dptr = (char**){"ax", "zy"};
    char** dptr = (char* []){"ax", "zy"};
    char** dptr = (char(*)[]){"ax", "zy"};
    char** dptr = (char(*)[][C]){"ax", "zy"};
  */

  /* 1-1. char** dptr = &ptr; char *ptr = "ax";
  - diagram
             *dptr   **dptr
    dptr --> ptr --> "ax"
  */
  char* aa = "ax";
  char** f1p = &aa;
  printf("f1p: %s, *f1p: %s, **f1p: %c\n", f1p, *f1p, **f1p);

  printf("\n");

  /* 1-2. char** dptr = "ax"; */
  char** f2p = "ax";

  printf("f2p: %p, f2p+1: %p\n", f2p + 0, f2p + 1);                // diff 8
  printf("*(f2p+0): %p, *(f2p+1): %p\n", *(f2p + 0), *(f2p + 1));  // diff ???

  printf("f2p: %s, *f2p: %c\n", f2p, *f2p);

  printf("\n");

  /* 1-3. char** ptr = {"ax", "zy"}; */
  char** f3p = {"ax", "zy"};

  printf("f3p: %s, *f3p: %c\n", f3p, *f3p);

  printf("\n");

  /* 1-4. char** dptr = (char*){"ax", "zy"}; */
  char** f4p = (char*){"ax", "zy"};

  printf("f4p: %s, *f4p: %c\n", f4p, *f4p);

  printf("\n");

  /* 1-5. char** dptr = (char**){"ax", "zy"}; */
  char** f5p = (char**){"ax", "zy"};

  printf("f5p: %s, *f5p: %c\n", f5p, *f5p);

  printf("\n");

  /* 1-6. char** f6p = (char* []){"ax", "zy"};
    dptr --> p[0] --> "ax"
             p[1] --> "zy"
  */
  char** f6p = (char* []){"ax", "zy"};
  printf("\n");
  for (int i = 0; i < R; i++) {
    printf("*(f6p+%d): %s\n", i, *(f6p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(f6p+%d)+%d): %c\n", i, j, *(*(f6p + i) + j));
    }
  }
  printf("\n");

  /* 1-7. char** dptr = (char(*)[]){"ax", "zy"};
    f6p --> p => a[0] == 'a'
                 a[1] == 'x'
  */
  char** f7p = (char(*)[]){"ax", "zy"};

  printf("f7p: %s, *f7p: %c\n", f7p, *f7p);

  printf("\n");

  /* 1-8. char** dptr = (char(*)[][C]){"ax", "zy"}; */
  char** f8p = (char(*)[][C]){"ax", "zy"};

  printf("f8p: %s, *f8p: %c\n", f8p, *f8p);

  printf("\n");

  /* 1-9. char** dptr = (char[R][C]){"ax", "zy"}; */
  char** f9p = (char[R][C]){"ax", "zy"};

  printf("f9p: %s, *f9p: %c\n", f9p, *f9p);

  printf("\n");

  /* 2.
    char arr[2][3] = {"ax", "zy"};    char **dptr = &arr;
    char* ptr = {"ax", "zy"};        char **dptr = &ptr;
    char* ptr[2] = {"ax", "zy"};     char **dptr = &ptr;
    char* ptr[2][3] = {"ax", "zy"};  char **dptr = &ptr;
    char(*ptr)[2] = {"ax", "zy"};    char **dptr = &ptr;
    char(*ptr)[2][3] = {"ax", "zy"}; char **dptr = &ptr;
  */

  /* 2-1. */
  char** g1p = &str;

  printf("%p, %p, %p, %p\n", g1p, *g1p, str, &str);
  printf("g1p: %s, *g1p: %c\n", g1p, *g1p);

  printf("\n");

  /* 2-2. */
  char** g2p = &a1p;  // char* a1p = {"ax", "by"};

  printf("*g2p: %s, **g2p: %c\n", *g2p, **g2p);

  for (int i = 0; i < C - 1; i++) {
    printf("*(*g2p+%d): %c\n", i, *(*g2p + i));
  }

  printf("\n");

  /* 2-3. char* ptr[R] = {"ax", "zy"}; char** dptr = &ptr;
  dptr == p --> p[0] == *(dptr+0) --> "ax"
                p[1] == *(dptr+1) --> "zy"
  */
  char** g3p = &b1r;  // char* b1r[R] = {"ax", "zy"};

  for (int i = 0; i < R; i++) {
    printf("*(g3p+%d): %s\n", i, *(g3p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(g3p+%d)+%d):%c\n", i, j, *(*(g3p + i) + j));
    }
  }

  printf("\n");

  /* 2-4. char* ptr[R][C] = {"ax", "zy"}; char **dptr = &ptr;
  dptr => p[0] --> p[0][0] --> "ax"
                   p[0][1] --> "zy"
  */
  char** g4p = &c1p;  // char* c1p[R][C] = {"ax", "zy"};

  printf("*g4p: %s, **g4p: %c\n", *g4p, **g4p);

  for (int i = 0; i < R; i++) {
    printf("g4p[%d]: %s\n", i, g4p[i]);
  }

  for (int i = 0; i < R; i++) {
    printf("*(g4p+%d): %s\n", i, *(g4p + i));
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(g4p+%d)+%d): %c\n", i, j, *(*(g4p + i) + j));
    }
  }

  printf("\n");

  /* 2-5. char(*ptr)[C] = {"ax", "zy"}; char **dptr = &ptr;
  dptr --> ptr == *dptr => a[0] == 'a'
                           a[1] == 'x'
                           a[2] == '\0'
  */
  char** g5p = &d1p;  // char(*d1p)[C] = {"ax", "zy"}

  printf("%s\n", *g5p);
  for (int i = 0; i < C - 1; i++) {
    printf("*(*g5p+%d): %c\n", i, *(*g5p + i));
  }

  printf("\n");

  /* 2-6. char(*ptr)[R][C] = {"ax", "zy"}; char **dptr = &ptr
    dp --> p => a[0] --> a[0][0] == 'a'
                         a[0][1] == 'x'
                         a[0][2] == '\0'
                a[1] --> a[1][0] == 'z'
                         a[1][1] == 'y'
                         a[1][2] == '\0'
  */
  char** g6p = &e1p;  // char(*e1p)[R][C] = {"ax", "zy"};

  printf("g6p  : %p\n", g6p);
  printf("*g6p : %p\n", *g6p);
  printf("**g6p: %p\n", **g6p);

  for (int i = 0; i < C - 1; i++) {
    printf("*(*g6p+%d): %c\n", i, *(*g6p + i));
  }

  printf("\n");

  printf("\nTHE END");
  return 0;
}