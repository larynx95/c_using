/* Data Structures Using C, 2nd, Reema Thareja
Chapter 05. Structure and Unions

Programming Exercises
7. Write a program to read and display the information
about all the employees in a department.
Edit the details of the i th employee and redisplay the information.

TODO: How to write this? https://cdecl.org/
      And which is the best?

        i)              array of pointers (pointing) to structures
        ii)  pointer to array of pointers (pointing) to structures
        iii)            pointer to array of structrues

        1. array n of pointers (pointing) to structures
           struct *foo[n];

        2. pointer to array n of structrues
           struct (*foo)[n];

        3. pointer to array n of pointer to structure
           struct *(*foo)[n]

        4. array n of pointer to pointer to structure
           struct **foo[n]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 2

typedef struct {
  char name[10];
  float salary;
} EE;

void print_structs1(EE *emps[NUM]);
void print_structs2(EE (*ptr)[NUM]);
void print_structs3(EE *(*ptr)[NUM]);
void print_structs4(EE **ptr);

int main() {
  /********************************************************
   * 1. array n of pointers (pointing) to structures
   *    struct *foo[n];
   *
   *    foo[0] ---> structure 0
   *    foo[1] ---> structure 1
   *    foo[2] ---> structrue 2
   *
   *********************************************************/
  EE *arr[NUM];
  for (int i = 0; i < NUM; i++) {
    arr[i] = malloc(sizeof(EE));
  }

  strcpy(arr[0]->name, "Kim");
  arr[0]->salary = 100;
  strcpy(arr[1]->name, "Jung");
  arr[1]->salary = 200;

  print_structs1(arr);

  for (int i = 0; i < NUM; i++) {
    free(arr[i]);
  }
  printf("\n");

  /********************************************************
   * 2. pointer to array n of structrues
   *    struct (*atr)[n];
   *
   *    atr ---> structure 0
   *             structure 1
   *             structure 2
   *********************************************************/
  EE(*atr)[NUM];
  atr = malloc(sizeof(EE) * NUM); /*  pointer needs memory allocation */

  strcpy((*atr)->name, "John");
  strcpy((*atr + 1)->name, "Park");
  (*atr)->salary = 200;
  (*atr)->salary = 500;

  print_structs2(atr);
  free(atr); /* free memory */
  printf("\n");

  /********************************************************
   * 3. pointer to array n of pointer to structure
   *    struct *(*btr)[n]
   *
   *    btr --->  ptr0  ---> structure 0
   *              ptr1  ---> structure 1
   *              ptr2  ---> structure 2
   *
   *********************************************************/
  EE *(*btr)[NUM] = malloc(NUM * sizeof(EE *)); /* fisrt mem allocation */
                                                /* TODO: Is this required?  */
  for (int i = 0; i < NUM; i++) {               /* second mem allocation */
    (*btr + i)[i] = malloc(sizeof(EE));
  }

  strcpy((*btr + 0)[0]->name, "Jung");
  (*btr + 0)[0]->salary = 800;
  strcpy((*btr + 1)[1]->name, "Jang");
  (*btr + 1)[1]->salary = 700;

  print_structs3(btr);

  for (int i = 0; i < NUM; i++) {
    free((*btr + i)[i]);
  }
  free(btr);
  printf("\n");

  /********************************************************
   * 4. pointer to pointer to structure
   *    struct **ctr
   *
   *    ctr  ---> *(ctr + 0) ---> structure 1
   *              *(ctr + 1) ---> structure 2
   *              *(ctr + 2) ---> structure 3
   *********************************************************/

  /********************************************************
   * 5. array n of pointer to pointer to structure
   *    struct **ptr[n]
   *
   *    ptr[0]  ---> *(ptr[0] + 0)  ---> structure 0
   *    ptr[1]  ---> *(ptr[1] + 1)  ---> structure 1
   *    ptr[2]  ---> *(ptr[2] + 2)  ---> structure 2
   *
   * https://stackoverflow.com/questions/19384243/how-to-create-a-pointer-to-pointer-array-to-struct
   *********************************************************/

  printf("\n");

  return 0;
}

void print_structs1(EE *emps[NUM]) {
  for (int i = 0; i < NUM; i++) {
    printf("Name: %s, \tSalary: %.2f\n", emps[i]->name, emps[i]->salary);
  }
}

void print_structs2(EE (*ptr)[NUM]) {
  for (int i = 0; i < NUM; i++) {
    printf("Name: %s, \tSalaray: %.2f\n", (*ptr + i)->name, (*ptr + i)->salary);
  }
}

void print_structs3(EE *(*ptr)[NUM]) {
  for (int i = 0; i < NUM; i++) {
    printf("Name: %s, \tSalary: %.2f\n", (*ptr + i)[i]->name,
           (*ptr + i)[i]->salary);
  }
}

void print_structs4(EE **ptr) {
  for (int i = 0; i < NUM; i++) {
    printf("Name: %s, \tSalary: %.2f\n", (*ptr + i)->name, (*ptr + i)->salary);
  }
}