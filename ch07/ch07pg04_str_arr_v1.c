/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure

Programming Exercises (optional)
4. Dealing with multidimensional character array (summary)

*/

#include <stdio.h>
#define R 2
#define C 3

int main() {
  /********************************************************
  1D character array - array, pointer

  ptr             value
  -------------------------------------------
  ptr => anom --> anom[0] == *(ptr+0) == 'a'
                  anom[1] == *(ptr+1) == 'x'
                  anom[2] == *(ptr+2) == '\0'

   ********************************************************/
  printf("1. Printing - char str or char * ptr\n");

  /* 1. array */
  char as[3] = "aa";
  char bs[3] = {'a', 'a', '\0'};
  for (int i = 0; i < C; i++) {
    printf("%c", as[i]);
  }
  printf("\n\n");

  /* 2. pointer */
  char single_char = 'a';
  char* ptr2single_char = &single_char;
  // char * ptr2songle_char = 'a'; // (X) not working

  char* aptr = "bb";  // immutable
  char* bptr = as;    // not &as (Notice this feature in C language!)
  char* cptr = {'a', 'a', '\0'};  // TODO: ???

  while (*aptr) {
    printf("%c", *aptr++);
  }
  printf("\n");

  /* 2-2-ii. */
  for (int i = 0; i < C; i++) {
    printf("%c", *(bptr + i));
  }
  printf("\n\n\n");

  /* 2-2-iii. */
  // printf("cptr: %c\n", cptr);  // TODO: error

  /********************************************************
  2D: array R of C characters: char str[2][3]

  dptr     ptr                    value
  ------------------------------------------------------
  a --> a[0] == *(a+0) --> a[0][0] == *(*(a+0)+0) == 'a'
                           a[0][1] == *(*(a+0)+1) == 'x'
                           a[0][2] == *(*(a+0)+2) == '\0'
        a[1] == *(a+1) --> a[1][0] == *(*(a+1)+0) == 'b'
                           a[1][1] == *(*(a+1)+1) == 'y'
                           a[1][2] == *(*(a+1)+2) == '\0'

  ********************************************************/
  printf("2. Printing - array R of C characters\n");

  char str[R][C] = {"ax", "by"};

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("*(*(str+%d)+%d): %c\n", i, j, *(*(str + i) + j));
    }
  }

  printf("\n");

  /********************************************************
  2D: single pointer: char *ptr

  dptr            ptr                     value
  -----------------------------------------------------------------
  ptr => a --> a[0] == *(ptr+0) --> a[0][0] == *(*(ptr+0)+0) == 'a'
                                    a[0][1] == *(*(ptr+0)+1) == 'x'
                                    a[0][1] == *(*(ptr+0)+2) == '\0'
               a[1] == *(ptr+1) --> a[1][0] == *(*(ptr+1)+0) == 'b'
                                    a[1][1] == *(*(ptr+1)+1) == 'b'
                                    a[1][2] == *(*(ptr+1)+2) == '\0'

  ********************************************************/
  printf("3. Printing - single pointer\n");

  /********************************************************
  2D: array of pointers

  dptr               ptr              value
  -----------------------------------------------------------------
  dpr --> dpr[0] == *(dpr+0) => a --> a[0] == *(*(dpr+0)+0) == 'a'
                                      a[1] == *(*(dpr+0)+1) == 'x'
                                      a[2] == *(*(dpr+0)+2) == '\0'
          dpr[1] == *(dpr+1) => a --> a[0] == *(*(dpr+1)+0) == 'b'
                                      a[1] == *(*(dpr+1)+1) == 'y'
                                      a[2] == *(*(dpr+1)+2) == '\0'

  ********************************************************/
  printf("4. Printing - array of pointers\n");

  /* 1. declaration and initialization */
  /* 1-1. one step */
  char* dpr[R] = {"aa", "bb"};
  char* epr[] = {"aa", "bb"};

  /* 1-2. two steps */
  char* fpr[R];
  fpr[0] = str[0];
  fpr[1] = str[1];

  /* 2. Pointer arithmetics and Printing */
  for (int i = 0; i < R; i++) {
    printf("fpr[%d]: %s\n", i, fpr[i]);
  }

  for (int i = 0; i < R; i++) {
    printf("*(fpr + %d): %s\n", i, *(fpr + i));
  }
  printf("\n");

  /********************************************************
   * 2D: two dimensional array of pointers to character type
   A. Declaration, Initialization
     1. One step
       - We can't initialize multiple pointers at once. (again)
       - This is not possible.
     2. Two steps
            char *ptr[R][C];
       - The 'ptr' is not a pointer, but an array name.
       - Array 'ptr' consists of pointers.
            ptr[0][0] ~ ptr[R-1][3-1]
       - These are also pointers.
            ptr[0] ~ ptr[R-1]
   B. Pointer arithmetics and Printing
     1. What exactly does the pointer 'ptr' point to?
       - 'ptr' is not a pointer, but a array name.
       - '&ptr' can be a pointer.
   C. Diagrams
                          +------------+
      &ptr --> ptr[0] --> | ptr[0][0]  | --> 'a'
                          +------------+
                          | ptr[0][1]  | --> 'a'
                          +------------+
                          | ptr[0][2]  | --> '\0'
                          +------------+
               ptr[1] --> | ptr[1][0]  | --> 'b'
                          +------------+
                          | ptr[1][1]  | --> 'b'
                          +------------+
                          | ptr[1][2]  | --> '\0'
                          +------------+
   ********************************************************/
  printf("5. Printing - 2D array of pointers\n");

  /* 1. declaration and initialization */
  char* gpr[R][C];
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      gpr[i][j] = &str[i][j];
    }
  }

  /* 2. Pointer arithmetics and Printing */
  for (int i = 0; i < R; i++) {
    printf("*gpr[%d]: %s\n", i, *gpr[i]);
  }

  for (int i = 0; i < R; i++) {
    printf("**gpr + C * %d: %s\n", i, **gpr + C * i);
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%c", *gpr[i][j]);
    }
    printf("\n\n");
  }
  printf("\n");

  /********************************************************
   * 2D: pointer to array of characters
   A. Declaration, Initialization
     1. One step
            char (*ptr)[C] = (char [R][C]){"aa", "bb"};
            char (*ptr)[C] = (char [][C]){"aa", "bb"};
            char (*ptr)[C] = (char (*)[C]){"aa", "bb"};
     2. Two steps
            char (*ptr)[C] = str;  // &str[0], &str[0][0]
   B. Pointer arithmetics and Printing
     1. What exactly does the pointer 'ptr' point to?
       1) pointer to a character
            char * ptr = "aa";
            printf("%c", ptr);  // a
            printf("%s", ptr);  // aa
            printf("%c", *ptr); // a
            printf("%s", *ptr); // error, '*ptr' is not a pointer or array name
                                // We can use '%s' type specfier here!
                                // It's just a character.
       2) pointer to an array of characters (a string)
            char (*ptr)[3] = "aa";
            printf("%c", ptr);  // a
            printf("%s", ptr);  // aa
            printf("%c", *ptr); // a
            printf("%s", *ptr); // aa, '*ptr' is a pointer
                                // to the first character 'a'
       3) pointer to an array of characters (a string)
            char (*ptr)[3] = (char [][3]){"aa", "bb"};
            printf("%c", ptr);  // a
            printf("%s", ptr);  // aa
            printf("%c", *ptr); // a
            printf("%s", *ptr); // aa
     2. Pointers
       - Pointer 'ptr' points to str[0], an array of characters
       - Pointer '*ptr' points to str[0][0], a character
   C. Diagrams
                                          +-----+
      ptr + 0 --> +-   *(ptr + 0) + 0 --> | 'a' |
                  |                       +-----+
                  |    *(ptr + 0) + 1 --> | 'a' |
                  |                       +-----+
                  +-   *(ptr + 0) + 2 --> |'\0' |
                                          +-----+
      ptr + 1 --> *-   *(ptr + 1) + 0 --> | 'b' |
                  |                       +-----+
                  |    *(ptr + 1) + 1 --> | 'a' |
                  |                       +-----+
                  +-   *(ptr + 1) + 2 --> |'\0' |
                                          +-----+
   ********************************************************/
  printf("6. Printing - pointer to array of characters\n");

  /* 1. declaration and initialization */
  /* 1-1. One step */
  char(*hpr)[C] = (char[R][C]){"aa", "bb"};
  char(*ipr)[C] = (char[][C]){"aa", "bb"};
  char(*jpr)[C] = (char(*)[C]){"aa", "bb"};  // warning messages

  /* 1-2. Two-steps */
  char(*kpr)[C] = str;  // &str[0], &str[0][0] are same result

  /* 2. Pointer arithmetics and Printing */
  for (int i = 0; i < R; i++) {
    printf("kpr + %d: %s\n", i, kpr + i);
  }

  for (int i = 0; i < R; i++) {
    printf("*(kpr + %d): %s\n", i, *(kpr + i));
  }
  printf("\n");

  /********************************************************
   * 2D: pointer to 2D array of characters
   A. Declaration, Initialization
     1. One step
            char (*ptr)[R][C] = {"aa", "bb"};
     2. Two steps
            char (*ptr)[R][C] = &str;
   B. Pointer arithmetics and Printing
     1. What exactly does the pointer 'ptr' point to?
       - Pointer 'ptr' points to the whole array?
     2. Dereferencing
       - ptr  : pointer to the whole 2D array
       - *ptr : pointer to a array of characters ("aa")
       - **ptr: pointer to a character ('a')
     3.
      tptr                dptr        ptr                             value
      ---------------------------------------------------------------------
      ptr --> anom[0] == *(ptr+0) --> anom[0][0] == *(*(ptr+0)+0) --> 'a'
                                      anom[0][1] == *(*(ptr+0)+1) --> 'x'
                                      anom[0][2] == *(*(ptr+0)+2) --> '\0'
              anom[1] == *(ptr+1)- -> anom[1][0] == *(*(ptr+1)+1) --> 'b'
                                      anom[1][1] == *(*(ptr+1)+2) --> 'y'
                                      anom[1][2] == *(*(ptr+1)+3) --> '\0'
   C. Diagrams
                                                     +-----+
      ptr --> +- *ptr + 0 --> +- *(*ptr + 0) + 0 --> | 'a' |
              |               |                      +-----+
              |               |  *(*ptr + 0) + 1 --> | 'a' |
              |               |                      +-----+
              |               +- *(*ptr + 0) + 2 --> |'\0' |
              |                                      +-----+
              |               +- *(*ptr + 1) + 0 --> | 'b' |
              |               |                      +-----+
              |               |  *(*ptr + 1) + 1 --> | 'a' |
              |               |                      +-----+
              +-              +- *(*ptr + 1) + 2 --> |'\0' |
                                                     +-----+
   ********************************************************/
  printf("7. Printing - pointer to 2D array of characters\n");

  /* 1. One step */
  char(*lpr)[R][C] = {"aa", "bb"};

  /* 2. Two steps */
  char(*mpr)[R][C] = &str;  // str, str[0], &str[0], &str[0][0]
  printf("mpr: %s, *mpr: %s, **mpr: %s\n", mpr, *mpr, **mpr);

  for (int i = 0; i < R; i++) {
    printf("*mpr + %d: %s\n", i, *mpr + i);
  }

  for (int i = 0; i < R; i++) {
    printf("**mpr + C * %d: %s\n", i, **mpr + C * i);
  }

  printf("\n");

  /********************************************************
   * 2D: double pointer
   A. Declaration, Initialization
     1. One step
            char** npr = {"aa", "bb"};
            char** opr = (char*){"aa", "bb"};
            char** ppr = (char**){"aa", "bb"};
            char** qpr = (char* []){"aa", "bb"};
            char** rpr = (char(*)[]){"aa", "bb"};
            char** spr = (char(*)[][C]){"aa", "bb"};
     2. Two steps
   B. Pointer arithmetics and Printing
     1. Review
     (1) single character
            char** npr = {"aa", "bb"};
      - 'npr' is a double pointer
        pointer to pointer to character type
      - We can't assign a character to a pointer directly like this.
            char *ptr = 'a'; (X)
            char chr = 'a'; char *ptr = &chr; (OK)
      - And then,
            dptr --> ptr --> var type = a character;
            &ptr     ptr     chr       'a'
     (2) array of characters
      - We can assign an array of characters to a pointer directly.
        (Actually, there is hidden mechanism.)
        i.
            char str[] = "aa";
            char *ptr = str; // or &str, &str[0]
            char **dptr = &ptr;
        ii.
            char *ptr = "aa"; (OK)
            (const char anom[] = "aa"; char *ptr = &anom;)
            char **dptr = &ptr;
      - And then,
            dptr --> ptr -->    arr name = an array or character
        i.  dptr     ptr==&str==str        "aa"
            &ptr     &str
        ii. dptr     ptr        anom       "aa"
            &ptr     &anom
     2. One step
            char** npr = {"aa", "bb"};
            char** opr = (char*){"aa", "bb"};
            char** ppr = (char**){"aa", "bb"};
            char** qpr = (char* []){"aa", "bb"};
            char** rpr = (char(*)[]){"aa", "bb"};
            char** spr = (char(*)[][C]){"aa", "bb"};
     3. Two-steps
            char ar[2][3] = {"aa", "bb"};    char **dptr = &ar;
            char* apt = {"aa", "bb"};        char **dptr = &apt;
            char* bpt[2] = {"aa", "bb"};     char **dptr = &bpt;
            char* cpt[2][3] = {"aa", "bb"};  char **dptr = &cpt;
            char(*dpt)[2] = {"aa", "bb"};    char **dptr = &dpt;
            char(*ept)[2][3] = {"aa", "bb"}; char **dptr = &ept;
            char** fpt = {"aa", "bb"};       char **dptr = fpt;
   C. Diagrams
     1. Review - array of array of characters
       - array name 'ar' is not pointer variable
                                             +-----+
              &ar --> ar[0] --> +- ar[0][0]  | 'a' |
                                |            +-----+
                                |  ar[0][1]  | 'a' |
                                |            +-----+
                                +- ar[0][2]  |'\0' |
                                             +-----+
                      ar[1] --> +- ar[1][0]  | 'b' |
                                |            +-----+
                                |  ar[1][1]  | 'a' |
                                |            +-----+
                                +- ar[1][2]  |'\0' |
                                             +-----+

   https://stackoverflow.com/questions/4832082/3-double-character-pointer-declaration-and-initialization
   ********************************************************/
  printf("8. Printing - double pointer\n");

  /* 1. Review of double pointer: single character */
  printf("8-1-1. single ppointer\n");
  char c = 'a';
  char* cp = &c;
  char** dcp = &cp;
  printf("*chr: %c, **dcp: %c\n", *cp, **dcp);

  /* 1. Review of double pointer: array of characters */
  /* 1-A. double pointer - from array */
  printf("8-1-2-a. double pointer - freom array \n");
  char cc[] = "ab";
  char* cpp = &cc;  // cc, &cc, &cc[0]
  char** dcpp = &cpp;
  printf("cc: %s, cpp: %s, *cc: %c, *cpp: %c\n", cc, cpp, *cc, *cpp);
  printf("*(cc+1): %c, *(cpp+1): %c\n", *(cc + 1), *(cpp + 1));
  printf("*dcpp: %s, *dcpp+1: %s, *(*dcpp+1): %c\n", *dcpp, *dcpp + 1,
         *(*dcpp + 1));
  printf("**dcpp: %c\n", **dcpp);

  /* 1-B. doubple pinter from pointer */
  printf("8-1-2-b. double pointer - from pointer \n");
  char* dpp = "cd";  // (char *)"bb" (OK)
  dcpp = &dpp;
  // dcpp = "bb";         // (X) error, not an address of a pointer
  // dcpp = (char*)"bb";  // (x) error, not an address of a pointer
  // dcpp = (char**)"bb"; // (X) "bb" can't be coverted to dptr type
  printf("cc: %s, dpp: %s, *cc: %c, *dpp: %c\n", cc, dpp, *cc, *dpp);
  printf("*(cc+1): %c, *(dpp+1): %c\n", *(cc + 1), *(dpp + 1));
  printf("*dcpp: %s, *dcpp+1: %s, *(*dcpp+1): %c\n", *dcpp, *dcpp + 1,
         *(*dcpp + 1));
  printf("**dcpp: %c\n", **dcpp);

  printf("\n");

  /* 2. One-step */
  /* 2-1. */
  printf("8-2. one step \n");
  char** npr = {"aa", "bb"};
  /* 2-2. */
  char** opr = (char*){"aa", "bb"};

  /* 2-3. */
  char** ppr = (char**){"aa", "bb"};

  /* 2-4. */
  char** qpr = (char* []){"aa", "bb"};

  /* 2-5. */
  char** rpr = (char(*)[]){"aa", "bb"};

  /* 2-6. */
  char** spr = (char(*)[][C]){"aa", "bb"};

  printf("\n");

  /* 3. Two steps */
  char ar[2][3] = {"aa", "bb"};

  /* 3-1. */
  printf("8-3-1. tw0 steps \n");
  char* apt = {"aa", "bb"};

  printf("\n");

  /* 3-2.
    char *bpt[2]: array 2 of pointer to character(s)
    array of pointers    array of characters
         bpt[0]   ----->    anom[0]   ----->   "aa"
         bpt[1]   ----->    anom[1]   ----->   "bb"
         *dbpt              **dbpt
    char **dbpt = &bpt[0];
        *(dbpt+0) == bpt[0]
        *(dbpt+1) == bpt[1]
        **dbpt == 'a', a character, not pointer
  */
  printf("8-3-2. \n");
  char* bpt[2] = {"ax", "by"};
  char** dbpt = &bpt[0];  // bpt, &bpt, &bpt[0]
  printf("*dbpt: %s, *(dbpt+1): %s\n", *dbpt, *(dbpt + 1));
  printf("dbpt[0]: %s, dbpt[1]: %s\n", dbpt[0], dbpt[1]);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      // Be careful not to include null terminator(C-1)
      printf("%c ", *(*(dbpt + i) + j));
    }
  }
  printf("\n");

  /* 3-3.
    char *dpt[R][C]: 2D array of pointer to character(s)
    pointers      pointers          characters
    cpt[0] ---->  cpt[0][0]   ----> 'a'
                  cpt[0][1]   ----> 'a'
                  cpt[0][2]   ----> '\0'
    cpt[1] ---->  cpt[1][0]   ----> 'b'
                  cpt[1][1]   ----> 'b'
                  cpt[1][2]   ----> '\0'
    *dcpt         **dcpt
  */
  printf("8-3-3. \n");
  char* cpt[2][3] = {"ax", "by"};
  char** dcpt = &cpt;

  printf("*dcpt: %s, **dcpt: %c\n", *dcpt, **dcpt);
  for (int i = 0; i < R; i++) {
    printf("dcpt[%d]: %s\n", i, dcpt[i]);
  }

  printf("*(*(dcpt + 0) + 0): %c\n", *(*(dcpt + 0) + 0));
  printf("*(*(dcpt + 0) + 1): %c\n", *(*(dcpt + 0) + 1));
  printf("*(*(dcpt + 1) + 0): %c\n", *(*(dcpt + 1) + 0));
  printf("*(*(dcpt + 1) + 1): %c\n", *(*(dcpt + 1) + 1));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C - 1; j++) {
      printf("%c ", *(*(dcpt + i) + j));
    }
    printf("\n");
  }

  int* cipt[2][2] = {10, 20, 30, 40};
  int** dcipt = &cipt;
  for (int i = 0; i < 4; i++) {
    printf("The %dth number is %d\n", i, *(dcipt + i));
  }

  printf("\n");

  /* 3-4.
    - char (*dpt)[2] = {"ax", "by"};
      pointer to array 2 of characters
    - diagram
      type:   dptr     ptr
      name:   ddpt --> dpt ==   +-  anom[0] ----> 'a''
                                |                 'x'
                                +-                '\0'
                                    anom[1] ---->  'b'
                                                  'y'
                                                  '\0'
              &dpt                                *dpt
                                    *ddpt         **ddpt
  */
  printf("8-3-4. \n");

  char(*dpt)[3] = {"ax", "by"};
  char** ddpt = &dpt;

  printf("dpt: %s, *dpt: %s, *(dpt+1): %s\n", dpt, *dpt, *(dpt + 1));
  printf("dpt+1: %s, *(dpt+1): %s\n", dpt + 1, *(dpt + 1));

  for (int i = 0; i < R; i++) {
    printf("*(dpt+%d): %s\n", i, *(dpt + i));
  }

  printf("*dpt+0: %s, *dpt+3: %s\n", *dpt, *dpt + 3);
  printf("*ddpt: %s, *ddpt+3: %s\n", *ddpt, *ddpt + 3);
  // TODO: loss of info?

  printf("\n");

  /* 3-5.
    - char (*ept)[2][3] = {"ax", "by"};
      pointer to 2D array to character
      ept == anom[0] ----> anom[0][0] ----> 'a'
                           anom[0][1] ----> 'x'
                           anom[0][2] ----> '\0'
             anom[1] ----> anom[1][0] ----> 'b'
                           anom[1][1] ----> 'y'
                           anom[1][2] ----> '\0'
    - char (*ept)[2][3] = {{"ax", "by", "cz"}, {"dx", "ey", "fz"}};
      // TODO: Is this possible?
      pointer to 2D array to array of characters
      ept --> anom[0] == *(ept+0) --> anom[0][0] == *(*(ept+0)+0) --> "ax"
                                      anom[0][1] == *(*(ept+0)+1) --> "by"
                                      anom[0][2] == *(*(ept+0)+2) --> "cz"
              anom[1] == *(ept+1)- -> anom[1][0] == *(*(ept+1)+1) --> "dx"
                                      anom[1][1] == *(*(ept+1)+2) --> "ey"
                                      anom[1][2] == *(*(ept+1)+3) --> "fz"
  */
  printf("8-3-5. \n");
  char(*ept)[2][3] = {"ax", "by"};
  char** dept = &ept;

  printf("ept: %s, *ept: %s\n", ept, *ept);
  printf("*dept + 0: %s\n", *dept + 0);
  printf("*dept + 3: %s\n", *dept + 3);

  printf("\n");

  /* 3-6. */
  printf("8-3-6. \n");
  char** fpt = {"aa", "bb"};
  char** dfpt = fpt;

  printf("\n");

  printf("THE END");
  return 0;
}