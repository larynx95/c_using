/* Data Structures Using C, 2nd, Reema Thareja
Chapter 08. Queues
8.1 Introduction
8.2 Array representation of queues
  Operations on queues (Program example 1)
8.3 Linked representation of queues
  Operations on linked queues (Program example 2)
8.4 Types of queues
  8.4.1 Circular queues (Program example 3)
*/

/*
Programming Example
3. Write a program to implement a circular queue.

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main() {
  int option, val;
  system("clear");
  do {
    printf("***** MAIN MENU *****\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Peek\n");
    printf("4. Display the queue\n");
    printf("5. EXIT\n");

    printf("Enter your option : ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        insert();
        break;
      case 2:
        val = delete_element();
        if (val != -1) printf("The number deleted is : %d\n", val);
        break;
      case 3:
        val = peek();
        if (val != -1) printf("The first value in queue is : %d\n", val);
        break;
      case 4:
        display();
        break;
    }
  } while (option != 5);
  getch();
  return 0;
}

void insert() {
  int num;
  printf("Enter the number to be inserted in the queue: ");
  scanf("%d", &num);

  /* if no space for new elem */
  if (front == 0 && rear == MAX - 1) printf("OVERFLOW");
  /* if empty */
  else if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = num;
  }
  /* if one more space after rear */
  else if (rear == MAX - 1 && front != 0) {
    /* add new elem in front of queue */
    rear = 0;
    queue[rear] = num;
  } else {
    /* add new elem in rear++ position */
    rear++;
    queue[rear] = num;
  }
}

int delete_element() {
  int val;
  /* if empty */
  if (front == -1 && rear == -1) {
    printf("UNDERFLOW\n");
    return -1;
  }

  val = queue[front];
  /* if just one elem */
  if (front == rear) front = rear = -1;
  /* if one more elems */
  else {
    /* if front is MAX-1 position */
    if (front == MAX - 1) front = 0;
    /* move front to the right */
    else
      front++;
  }
  return val;
}

int peek() {
  if (front == -1 && rear == -1) {
    printf("QUEUE IS EMPTY\n");
    return -1;
  } else {
    return queue[front];
  }
}

void display() {
  int i;
  printf("\n");
  if (front == -1 && rear == -1)
    printf("QUEUE IS EMPTY\n");
  else {
    if (front < rear) {
      for (i = front; i <= rear; i++) printf("\t %d", queue[i]);
    } else {
      /* print front ~ rear */
      for (i = front; i < MAX; i++) printf("\t %d", queue[i]);
      for (i = 0; i <= rear; i++) printf("\t %d", queue[i]);
    }
  }
}