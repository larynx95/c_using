/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 4.
Write a program to read the address of a user.
Display the result by breaking it in multiple lines.

# representation of 2-D array
1) char arr[R][C]
   - the most basic way
   - when it passed to a function, it will decayed into `char (*arr)[C]`
2) char arr[ ][C]
   - the number of rows can be omitted
3) char (*arr)[C]
   - passed to a function, 2-d array decays
   - if it is not a param of a fx, it shoulde be initialized first.
     (pointer should be initialized before using it)
4) char *arr[R]
5) char **arr

*/

#include <stdio.h>
#include <stdlib.h>
#define ROWS 2
#define COLS 3

void create_arr(int rows, int cols, int arr[rows][cols]);
void display1(int rows, int cols, int arr[rows][cols]);
void display2(int rows, int cols, int arr[][cols]);
void display3(int rows, int cols, int (*)[cols]);
void display4(int rows, int cols, int (*)[cols]);
void display5(int rows, int cols, int*);

int main() {
  int mat[ROWS][COLS] = {0, 1, 2, 3, 4, 5};

  /* testing for pointer to array */
  int arr[3][2] = {{0, 1}, {2, 3}, {4, 5}};
  int(*parr)[2];
  parr = &arr[0];  // parr = arr;
  printf("address of arr: %p\n", arr);
  printf("address of &arr[0]: %p\n", &arr[0]);
  printf("address of &arr[0][0]: %p\n", &arr[0][0]);
  printf("arr == &arr[0]: %d\n", arr == &arr[0]);
  printf("&arr[0] == &arr[0][0]: %d\n", &arr[0] == &arr[0][0]);
  printf("address of arr: %p\n", parr);
  printf("address of &parr[0]: %p\n", &parr[0]);
  printf("address of &parr[0][0]: %p\n", &parr[0][0]);
  printf("parr == &parr[0]: %d\n", parr == &parr[0]);
  printf("&parr[0] == &parr[0][0]: %d\n", &parr[0] == &parr[0][0]);

  /* test for single pointer */
  int* sptr;          // pointer (pointing) to single integer
  sptr = &arr[0][0];  // sptr = arr

  /* test for printing */
  display4(3, 2, parr);
  // display5(ROWS, COLS, (int*)mat);
  display5(ROWS, COLS, (int*)mat);  // mat

  /* test for double pointer */
  int** dptr = (int**)arr;

  return 0;
}

/* creating a 2-D array */
void create_arr(int rows, int cols, int arr[rows][cols]) {
  printf("Enter the elements of the matrix: ");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}

/* explicitly, the numbers of both rows and cols are fixed */
void display1(int rows, int cols, int arr[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* size of rows can be omitted */
void display2(int rows, int cols, int arr[][cols]) {
  printf("The elements of the matrix are\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* compare this with above */
void display3(int rows, int cols, int arr[][cols]) {
  printf("The elements of the matrix are\n");
  for (int i = 0; i < rows; i++) {
    printf("\n");
    for (int j = 0; j < cols; j++) printf("\t %d", *(*(arr + i) + j));
  }
}

/* pointer to array of character
   arr: pointer (pointing) to array of N integers
        pointing to the whole array instead of only one array element

  int arr[3][2] = {{0,1}, {2,3}, {4,5}};
  (if passed to parameter of a function)
  arr --->  arr+0 ---> {0,1} == *(arr+0) == {*(*(arr+0)+0), *(*(arr+0)+1)}
            arr+1 ---> {2,3} == *(arr+1) == {*(*(arr+1)+0), *(*(arr+1)+1)}
            arr+2 ---> {4,5} == *(arr+2) == {*(*(arr+2)+0), *(*(arr+2)+1)}
  1}

  int (*ptr)[2];
  ptr = &arr[0];  // ptr = arr;

  ptr --->  ptr+0 ---> {0,1} == *(ptr+0) == {*(*(ptr+0)+0), *(*(ptr+0)+1)}
            ptr+1 ---> {2,3} == *(ptr+1) == {*(*(ptr+0)+0), *(*(ptr+0)+1)}
            ptr+2 ---> {4,5} == *(ptr+2) == {*(*(ptr+0)+0), *(*(ptr+0)+1)}

  https://stackoverflow.com/questions/16724368/how-to-pass-a-2d-array-by-pointer-in-c
  void printarray( char (*array)[50], int SIZE)
  void printarray( char array[][50], int SIZE), equivalent
*/
void display4(int rows, int cols, int (*arr)[cols]) {
  printf("The elements of the matrix are\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", *(*(arr + i) + j));
    }
    printf("\n");
  }
}

/* array of pointer
   arr: array of pointer (pointing) to single integer

  int arr[3][2] = {{0,1}, {2,3}, {4,5}};

  int *ptr;
  ptr = &arr[0][0];

  ptr ---> 0 == *((ptr + 0 * 3) + 0) == *(ptr + 0)
           1 == *((ptr + 0 * 3) + 1) == *(ptr + 1)
           2 == *((ptr + 0 * 3) + 2) == *(ptr + 2)
           3 == *((ptr + 1 * 3) + 0) == *(ptr + 3)
           4 == *((ptr + 1 * 3) + 1) == *(ptr + 4)
           5 == *((ptr + 1 * 3) + 2) == *(ptr + 5)
*/
void display5(int rows, int cols, int* arr) {
  printf("The elements of the matrix are\n");
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%d ", *((arr + i * rows) + j));
    }
    printf("\n");
  }
}

/* TODO: double pointer
   https://stackoverflow.com/questions/5201708/how-to-return-a-2d-array-to-a-function-in-c
*/

void dusplay6(int rows, int cols, int** arr) {}

float** createArray(int m, int n) {
  float* values = calloc(m * n, sizeof(float));
  float** rows = malloc(n * sizeof(float*));
  for (int i = 0; i < n; ++i) {
    rows[i] = values + i * m;
  }
  return rows;
}

void destroyArray(float** arr) {
  free(*arr);
  free(arr);
}