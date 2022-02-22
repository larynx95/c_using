/* Data Structures Using C, 2nd, Reema Thareja
Chapter 08. Queues

Programming Exercises
3. Write a program to create a queue using arrays
   which permits insertion at both the ends.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int front = -1, rear = -1;

int *insert(int *);
void display(void);

int main() {
  //
  return 0;
}

void display() {
  int i;
  printf("\n");
  if (front == -1 || front > rear)
    printf("QUEUE IS EMPTY.\n");
  else {
    for (i = front; i <= rear; i++) printf("%d ", queue[i]);
  }
  printf("\n\n");
}