/******************************************************************************
Data Structures Using C, 2nd, Reema Thareja
Chapter 03. Arrays

Programming exercises 14.
Write a menu driven program to read and display a p * q * r matrix.
Also, find the sum, transpose, and product of the two p * q * r matrices.
(diffcult! Tensor!!)
******************************************************************************/

/*
TODO:
What is the (1) scalar-product, (2) dot-product, (3) inner-product, (4)
outer-product, and (5) cross-product?
What is the (1) vector, (2) matrix, (3) tensor, and (4) scalar?
https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:multiplying-matrices-by-matrices/a/multiplying-matrices
https://www.youtube.com/watch?v=FCmH4MqbFGs

# Key Concepts
1. Inner product (== dot product) of vectors
- equation:    x ⋅ y == <x,y> == xTy
- Output of inner product of two vectors is always scalar value.
2. Outer product (== cross product) of vectors
- equation:   x⊗y == xyT

3. dot product of matrices

4. Tensor product

# Plan for solving this exercise
1. dot-product of n-tuples
  a = (2,5), b = (3,1)
  a⋅b = (2,5)⋅(3,1) = 2⋅3+5⋅1

  2D matrix as collection of n-tuples
  6  2
  4  3

  r1 = (6,2)
  r2 = (4,3)
  c1 = (6,4)
  c2 = (2,3)

2. matrix multiplication (2D)
  Let's think we have two 2D matrices.
  a   1 2        b  5 6
      3 4           7 8
  (2*2)          (2*2)        -> (2*2)
  (r1*c1)        (r2*c2)         (r1*c2), c1 == r2

  Then n-tuples in two 2D matrices are:
  ar1 = (1,2), ar2 = (3,4)
  ac1 = (1,3), ac2 = (2,4) *
  br1 = (5,6), br2 = (7,8)
  bc1 = (5,7), bc2 = (6,8) *

  Matrix multiplication means:
  output  ar1⋅bc1  ar1⋅bc2
          ar2⋅bc1  ar2⋅bc2     (It's totally different from what I've thought)

  a   1 2 3      b   1 4
      4 5 6          2 5
                     3 6
  (2*3)          (3*2)        -> (2*2)
  (r1*c1)        (r2*c2)         (r1*c2), c1 == r2

  Then n-tuples in two 2D matrices are:
  ar1 = (1,2,3), ar2 = (4,5,6)
  bc1 = (1,2,3), bc2 = (4,5,6)

  Matrix multiplication means:
  output  ar1⋅bc1  ar1⋅bc2
          ar2⋅bc1  ar2⋅bc2

  Generally, dot product of (i,j)-matrix is the output of i-ar and j-bc.
  That is, matrix a should have i rows and matrix b should have j columns.
  More easily, matrix multiplication is
  dot-product of n-tuples of i-th row of matrix a and
                             j-th col of matrix b.

3. TODO: variable-length array diemension

  int dim[2] = {2,2};
  int arr[dim[0]][dim[1]] = {{1,1}, {1,1}};  // error, WHY?

  or

  int ar[dim[0]][dim[1]];
  for (int i = 0; dim[0]; i++) {
    for (int j = 0; i < dim[1]; j++) {
      ar[i][j] = 1;
    }
  }

4. matrix transpose

  1 2                   1 3 5
  3 4  -> transpose ->  2 4 6
  5 6

  matrix(i,j) -> matrix(j,i)

*/

#include <stdio.h>
#include <stdlib.h>

void print2d(int rows, int cols, int ar[rows][cols]);
void sum2d(int rows, int cols, int ar[rows][cols], int br[rows][cols],
           int out[rows][cols]);
void mult2d_scalar(int rows, int cols, int ar[rows][cols], int out[rows][cols],
                   int scal);
void transpose2d_incorrect(int rows, int cols, int arr[rows][cols]);
void transpose2d(int rows, int cols, int arr[rows][cols], int out[cols][rows]);
int mult_tuples(int sz, int ar[], int br[]);
void mult2d(int r1, int c1, int r2, int c2, int ar[r1][c1], int br[r2][c2],
            int out[r1][c2]);

int main() {
  /* sum of two matrices */
  int ar[2][2] = {{1, 2}, {8, 9}};
  int br[2][2] = {{2, 2}, {2, 2}};
  int summed[2][2];

  sum2d(2, 2, ar, br, summed);
  print2d(2, 2, summed);

  /* n-tuples multiplication */
  int tup1[3] = {1, 2, 3};
  int tup2[3] = {4, 5, 6};
  printf("n-tuples mult: %d\n", mult_tuples(3, tup1, tup2));

  /* transpose matrix */
  int cr[2][2] = {{1, 2}, {3, 4}};
  int transposed[2][2];
  print2d(2, 2, cr);
  transpose2d(2, 2, cr, transposed);
  print2d(2, 2, transposed);

  /* matrix scalar-multiplication */
  int dr[2][2] = {{1, 2}, {3, 4}};
  int scalmult[2][2];
  mult2d_scalar(2, 2, dr, scalmult, 10);
  print2d(2, 2, scalmult);

  /* matrix multiplication (dot-product) */
  int er[2][2] = {{1, 2}, {3, 4}};
  int fr[2][2] = {{5, 6}, {7, 8}};
  int prod1[2][2];
  mult2d(2, 2, 2, 2, er, fr, prod1);
  print2d(2, 2, prod1);

  return 0;
}

void print1d(int sz, int arr[sz]) {
  for (int i = 0; i < sz; i++) {
    printf("%d ", arr[i]);
  }
}

void print2d(int rows, int cols, int ar[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", ar[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

/* void, 2D sum of two matrices */
void sum2d(int rows, int cols, int ar[rows][cols], int br[rows][cols],
           int out[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      out[i][j] = ar[i][j] + br[i][j];
    }
  }
}

/* void, 2D scalar multiplication */
void mult2d_scalar(int rows, int cols, int ar[rows][cols], int out[rows][cols],
                   int scal) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      out[i][j] = scal * ar[i][j];
    }
  }
}

/* void, swap elements in 2D array */
void transpose2d_incorrect(int rows, int cols, int arr[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int temp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = temp;
    }
  }
}

/* void, swap elemets in 2D array */
void transpose2d(int rows, int cols, int arr[rows][cols], int out[cols][rows]) {
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      out[i][j] = arr[j][i];
    }
  }
}

/* n-tuple multiplication (helper fx) */
int mult_tuples(int sz, int ar[], int br[]) {
  int total = 0;
  for (int i = 0; i < sz; i++) {
    total += ar[i] * br[i];
  }
  return total;
}

/* void, 2D dot multiplication
 */
void mult2d(int r1, int c1, int r2, int c2, int ar[r1][c1], int br[r2][c2],
            int out[r1][c2]) {
  /* condition for multiplication of two matrices */
  if (c1 != r2) {
    exit(EXIT_FAILURE);
  }

  int tps[c2][r2];  //
  transpose2d(r2, c2, br, tps);

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      out[i][j] = mult_tuples(c1, ar[i], tps[j]);
    }
  }
}

/* TODO: Implement 2D-array-sum-returning fx */
/* TODO: Implement 2D-array-scalar-multiplication-returning fx */
