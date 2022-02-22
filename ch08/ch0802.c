/* Data Structures Using C, 2nd, Reema Thareja
Chapter 08. Queues
8.1 Introduction
8.2 Array representation of queues
  Operations on queues (Program example 1)
8.3 Linked representation of queues
  Operations on linked queues (Program example 2)
*/

/*
Programming Example
2. Write a program to implement a linked queue.

TODO: Draw the structure.
front --> NULL <-- rear

front --> (1, next)
                --> (2, next)
                         --> (3, next) <-- rear
                                   --> (4, NULL)

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *next;
};

/* struct queue is consist of pointers, no data value */
struct queue {
  struct node *front;
  struct node *rear;
};

struct queue *q;

void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main() {
  int val, option;
  create_queue(q);
  system("clear");

  do {
    printf("*****MAIN MENU*****\n");
    printf("1. INSERT\n");
    printf("2. DELETE\n");
    printf("3. PEEK\n");
    printf("4. DISPLAY\n");
    printf("5. EXIT\n");

    printf("Enter your option : ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Enter the number to insert in the queue:");
        scanf("%d", &val);
        q = insert(q, val);
        break;
      case 2:
        q = delete_element(q);
        break;
      case 3:
        val = peek(q);
        if (val != -1) printf("The value at front of queue is : %d\n", val);
        break;
      case 4:
        q = display(q);
        break;
    }
  } while (option != 5);
  getch();
  return 0;
}

void create_queue(struct queue *q) {
  q->rear = NULL;
  q->front = NULL;
}

struct queue *insert(struct queue *q, int val) {
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));

  ptr->data = val;
  if (q->front == NULL) {
    q->front = ptr;
    q->rear = ptr;
    q->front->next = q->rear->next = NULL;  // ptr->next = ptr->next = NULL;
  } else {
    q->rear->next = ptr;
    q->rear = ptr;
    q->rear->next = NULL;
  }

  return q;
}

struct queue *display(struct queue *q) {
  struct node *ptr;
  ptr = q->front;
  if (ptr == NULL)
    printf("QUEUE IS EMPTY\n");
  else {
    printf("\n");
    while (ptr != q->rear) {
      printf("%d\t", ptr->data);
      ptr = ptr->next;
    }
    printf("%d\t", ptr->data);
  }
  return q;
}

struct queue *delete_element(struct queue *q) {
  struct node *ptr;
  ptr = q->front;
  if (q->front == NULL)
    printf("UNDERFLOW");
  else {
    q->front = q->front->next;
    printf("The value being deleted is : %d\n", ptr->data);
    free(ptr);
  }
  return q;
}

int peek(struct queue *q) {
  if (q->front == NULL) {
    printf("QUEUE IS EMPTY\n");
    return -1;
  } else
    return q->front->data;
}