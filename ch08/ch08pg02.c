/* Data Structures Using C, 2nd, Reema Thareja
Chapter 08. Queues

Programming Exercises
2. Write a program to create a linear queue of 10 values.

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void insert(int *, int);
int delete_element(void);
int peek(void);
void display(void);

int main() {
  //
  return 0;
}

/* possible states
   i. queue is empty
   ii. queue is full
   iii. else case
*/
void insert(int *que, int val) {
  /* if queue is full */
  if (rear >= MAX - 1) {
    printf("queue is full.");
    exit(EXIT_FAILURE);
  }
  /* if queue is empty */
  else if (front == -1) {
    front = rear = 0;
    queue[rear] = val;
  }
  /* else */
  else {
    rear++;
    queue[rear] = val;
  }
}

/* delete element */
int delete_element() {
  int val;
  /* if queue is empty */
  if (front == -1 || front > rear) {
    printf("UNDERFLOW.\n");
    return -1;
  } else {
    val = queue[front];
    front++;
    if (front > rear) front = rear = -1;
    return val;
  }
}

/* peek */
int peek() {
  if (front == -1 || front > rear) {
    printf("QUEUE IS EMPTY.\n");
    return -1;
  } else {
    return queue[front];
  }
}

/* display queue */
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