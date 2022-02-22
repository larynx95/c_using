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
3.10 Operations on two-dimensional arrays
  Transpose, Sum, Difference, Product (Program example 20 ~ 23)
3.11 Passing two-dimensional arrays to functions
  Passing a row
  Passing the entire 2D array (Program example 24)
3.12 Pointers and two-dimensional arrays (Program example 25)
******************************************************************************/

/*
2D array and its pointer:

  int mat[5][5];    // two-dimensional array
  int **ptr         // pointer to two-dimensional array
                    // array of pointers (to one-dimensional arrays)

  // accessing individual element
  mat[i][j] or
  *(*(mat + i) + j) or
  *(mat[i] + j)

  // four values for evaluating two-dimensional array
  1. The address of the first element of the array,
     which is given by the name of the array, i.e., mat in our case.
  2. The size of the type of the elements of the array,
     i.e., size of integers in our case.
  3. The specific index value for the row.
  4. The specific index value for the column.
*/

/*
Prpgram Example 25.
Write a program to read and display a 3 * 3 matrix.

-----------------
1. data_type array_name[ROWS][COLS];
  - array expression
  - actually,
      data_type (*array_name) [COLS];

2. data_type *array_name[ROWS];
  - the space for columns that can be dynamically allocated.

3. data_type (*array_name)[COLS];
  - the space for rows that may be dynamically allocated

----------------
Array to pointer decay and passing multidimensional arrays to functions
https://stackoverflow.com/questions/12674094/array-to-pointer-decay-and-passing-multidimensional-arrays-to-functions
Decay of multidimensional arrays as function parameters
https://stackoverflow.com/questions/51485989/decay-of-multidimensional-arrays-as-function-parameters
When an array decays, it converts into a pointer to the first element.
In the case of int a[3][4], a is an array of int[4],
so a pointer to an element of int [3][4] has type int (*)[4].
*/

#include <stdio.h>
#include <stdlib.h>
#define ROWS 2
#define COLS 3

void create_arr(int rows, int cols, int arr[][COLS]);
void display1(int rows, int cols, int arr[][COLS]);
void display2(int rows, int cols, int arr[][COLS]);
void display3(int rows, int cols, int (*)[COLS]);  // array decay
void display4(int rows, int cols, int (*)[COLS]);
void display5(int rows, int cols, int*);

int main() {
  int mat[ROWS][COLS] = {0, 1, 2, 3, 4, 5};

  /* testing for pointer to array */
  int arr[3][2] = {{0, 1}, {2, 3}, {4, 5}};
  int(*parr)[2];
  parr = &arr[0];  // parr = arr;

  printf("address of arr: %p\n", arr);                           // 0xffffcbb0
  printf("address of &arr[0]: %p\n", &arr[0]);                   // 0xffffcbb0
  printf("address of &arr[0][0]: %p\n", &arr[0][0]);             // 0xffffcbb0
  printf("arr == &arr[0]: %d\n", arr == &arr[0]);                // 1
  printf("&arr[0] == &arr[0][0]: %d\n", &arr[0] == &arr[0][0]);  // 1

  printf("address of arr: %p\n", parr);                 // 0xffffcbb0
  printf("address of &parr[0]: %p\n", &parr[0]);        // 0xffffcbb0
  printf("address of &parr[0][0]: %p\n", &parr[0][0]);  // 0xffffcbb0
  printf("parr == &parr[0]: %d\n", parr == &parr[0]);   // 1
  printf("&parr[0] == &parr[0][0]: %d\n", &parr[0] == &parr[0][0]);  // 1

  /* testing for single pointer */
  int* sptr;          // pointer (pointing) to single integer
  sptr = &arr[0][0];  // sptr = arr

  // testing for printing
  display4(3, 2, parr);
  // display5(ROWS, COLS, (int*)mat);
  display5(ROWS, COLS, (int*)mat);  // mat

  return 0;
}

/* creating a 2-D array */
void create_arr(int rows, int cols, int arr[][COLS]) {
  printf("Enter the elements of the matrix: ");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
}

/* explicitly, the numbers of both rows and cols are fixed */
void display1(int rows, int cols, int arr[][COLS]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* size of rows can be omitted */
void display2(int rows, int cols, int arr[][COLS]) {
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
void display3(int rows, int cols, int arr[][COLS]) {
  printf("The elements of the matrix are\n");
  for (int i = 0; i < rows; i++) {
    printf("\n");
    for (int j = 0; j < cols; j++) printf("\t %d", *(*(arr + i) + j));
  }
}

/* pointer to array
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
void display4(int rows, int cols, int (*arr)[COLS]) {
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