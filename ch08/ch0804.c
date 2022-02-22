/* Data Structures Using C, 2nd, Reema Thareja
Chapter 08. Queues
8.1 Introduction
8.2 Array representation of queues
  Operations on queues (Program example 1)
8.3 Linked representation of queues
  Operations on linked queues (Program example 2)
8.4 Types of queues
  8.4.1 Circular queues (Program example 3)
  8.4.2 Deques (Program example 4)
*/

/*
Programming Example
4. Write a program to implement input and output restricted deques
(deck, head-tail linked list).

# Deques
- deck, dequeue, head-tail linked list, double ended queue
- input restricted deque: insertion only at one of the ends
                          deletion from both ends
- output restricted deque: insertion on both ends
                           deletion at one of the ends

TODO: Draw structure
idx  0  1  2  3  4  5  6  7  8  9
             29 37 45 54 63
             Lt          Rt
idx  0  1  2  3  4  5  6  7  8  9
    42 56                63 27 18
       Rt                Lt
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int deque[MAX];
int left = -1, right = -1;

void input_deque(void);
void output_deque(void);

void insert_left(void);
void insert_right(void);
void delete_left(void);
void delete_right(void);
void display(void);

int main() {
  int option;
  system("clear");
  printf("*****MAIN MENU*****\n");
  printf("1.Input restricted deque\n");
  printf("2.Output restricted deque\n");

  printf("Enter your option: ");
  scanf("%d", &option);

  switch (option) {
    case 1:
      input_deque();
      break;
    case 2:
      output_deque();
      break;
  }
  return 0;
}

void input_deque() {
  int option;
  do {
    printf("INPUT RESTRICTED DEQUE\n");
    printf("1.Insert at right\n");
    printf("2.Delete from left\n");
    printf("3.Delete from right\n");
    printf("4.Display\n");
    printf("5.Quit\n");

    printf("Enter your option : ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        insert_right();
        break;
      case 2:
        delete_left();
        break;
      case 3:
        delete_right();
        break;
      case 4:
        display();
        break;
    }
  } while (option != 5);
}

void output_deque() {
  int option;
  do {
    printf("OUTPUT RESTRICTED DEQUE\n");
    printf("1.Insert at right\n");
    printf("2.Insert at left\n");
    printf("3.Delete from left\n");
    printf("4.Display\n");
    printf("5.Quit\n");

    printf("Enter your option : ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        insert_right();
        break;
      case 2:
        insert_left();
        break;
      case 3:
        delete_left();
        break;
      case 4:
        display();
        break;
    }
  } while (option != 5);
}

/*
idx  0  1  2  3  4  5  6  7  8  9   (MAX == 10)
(1)  -  -  -  -  -  -  -  -  -  -   : empty
(2)  o  *
     Lt==Rt==0
(3)  o  o  o  *
     Lt   Rt
(4)  o  o  o  o  o  o  o  o  o  o   : full
     Lt                        Rt
(5)  o  o  o  o  o  o  o  o  o  o   : full
        RtLt
(6)  o  *                       o
     Rt                        Lt

*/
void insert_right() {
  int val;
  printf("Enter the value to be added:");
  scanf("%d", &val);

  /* if full, there're two condition for full deque
     idx  0  1  2  3  4  5  6  7  8  9  (MAX == 10)
          o  o  o  o  o  o  o  o  o  o
          Lt                        Rt
     idx  0  1  2  3  4  5  6  7  8  9  (MAX == 10)
          o  o  o  o  o  o  o  o  o  o
                     Rt Lt
  */
  if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
    printf("OVERFLOW\n");
    return;
  }
  /* if empty */
  if (left == -1) {
    left = 0;
    right = 0;
  }
  /* if not empty, not full  */
  else {
    /* right is at last position of queue */
    if (right == MAX - 1)
      right = 0;
    else
      right = right + 1;
  }
  deque[right] = val;
}

/*
idx  0  1  2  3  4  5  6  7  8  9   (MAX == 10)
(1)  -  -  -  -  -  -  -  -  -  -   : empty
(2)  o  *
     Lt==Rt==0
(3)  o  o  o  *
     Lt   Rt
(4)  o  o  o  o  o  o  o  o  o  o   : full
     Lt                        Rt
(5)  o  o  o  o  o  o  o  o  o  o   : full
        RtLt
(6)  o  *                       o
     Rt                        Lt
*/
void insert_left() {
  int val;
  printf("Enter the value to be added:");
  scanf("%d", &val);

  if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
    printf("OVERFLOW\n");
    return;
  }
  /*If queue is initially empty*/
  if (left == -1) {
    left = 0;
    right = 0;
  } else {
    if (left == 0)
      left = MAX - 1;
    else
      left = left - 1;
  }
  deque[left] = val;
}

void delete_left() {
  if (left == -1) {
    printf("UNDERFLOW\n");
    return;
  }
  printf("The deleted element is : %d", deque[left]);
  /*Queue has only one element */
  if (left == right) {
    left = -1;
    right = -1;
  } else {
    if (left == MAX - 1)
      left = 0;
    else
      left = left + 1;
  }
}

void delete_right() {
  if (left == -1) {
    printf("UNDERFLOW\n");
    return;
  }
  printf("The element deleted is : %d", deque[right]);
  /*queue has only one element*/
  if (left == right) {
    left = -1;
    right = -1;
  } else {
    if (right == 0)
      right = MAX - 1;
    else
      right = right - 1;
  }
}

void display() {
  int front = left, rear = right;
  if (front == -1) {
    printf("QUEUE IS EMPTY\n");
    return;
  }
  printf("The elements of the queue are : ");
  if (front <= rear) {
    while (front <= rear) {
      printf("%d", deque[front]);
      front++;
    }
  } else {
    while (front <= MAX - 1) {
      printf("%d", deque[front]);
      front++;
    }
    front = 0;
    while (front <= rear) {
      printf("%d", deque[front]);
      front++;
    }
  }
  printf("\n");
}