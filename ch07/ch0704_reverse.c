/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure
7.1 Introduction
7.2 Array refresentation of stacks
7.3 Operations on a stack
  7.3.1 Push operation
  7.3.2 pop operation
  7.3.3 Peek operation (Program example 1)
7.4 Linked representation of stacks
7.5 Operations ona linked stack
  7.5.1 Push operation
  7.5.2 Pop operation (Program example 2)
7.6 Multiple stacks (Program example 3)
7.7 Applications of stacks
  7.7.1 Reversing a list (Program example 4)
*/

/*
Programming Example
4. Write a program to reverse a list of given numbers.

TODO: Wow! Stack data structure already has reverse algorithm in itself.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stk[10];
int top = -1;

int pop();
void push(int);

int main() {
  int val, n, i, arr[10];
  system("clear");

  /* The capacity of stack is already fixed.
     TODO: Is there any meaning of this scanf? */
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  printf("Enter the elements of the array: ");
  for (i = 0; i < n; i++) scanf("%d", &arr[i]);
  for (i = 0; i < n; i++) push(arr[i]);

  for (i = 0; i < n; i++) {
    val = pop();
    arr[i] = val;
  }

  printf("The reversed array is : ");
  for (i = 0; i < n; i++) printf("%d ", arr[i]);

  return 0;
}

void push(int val) { stk[++top] = val; }

int pop() { return (stk[top--]); }