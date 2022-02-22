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
  8.4.3 Priority queues
    Implementation of a priority queue
    Linked representation of a priority queue
    Array representation of a priority queue (Program example 5)
  8.4.4 multiple queues (Program example 6)
*/

/*
Programming Example
6. Write a program to implement multiple queues.

# Concept
  QUEUE A  -->     <-- QUEUE B

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
int QUEUE[MAX], rearA = -1, frontA = -1, rearB = MAX, frontB = MAX;

void insertA(int val) {
  if (rearA == rearB - 1)
    printf("\n OVERFLOW");
  else {
    if (rearA == -1 && frontA == -1) {
      rearA = frontA = 0;
      QUEUE[rearA] = val;
    } else
      QUEUE[++rearA] = val;
  }
}

int deleteA() {
  int val;
  if (frontA == -1) {
    printf("\n UNDERFLOW");
    return -1;
  } else {
    val = QUEUE[frontA];
    frontA++;
    if (frontA > rearA) frontA = rearA = -1 return val;
  }
}

void display_queueA() {
  int i;
  if (frontA == -1)
    printf("\n QUEUE A IS EMPTY");
  else {
    for (i = frontA; i <= rearA; i++) printf("\t %d", QUEUE[i]);
  }
}

void insertB(int val) {
  if (rearA == rearB - 1)
    printf("\n OVERFLOW");
  else {
    if (rearB == MAX && frontB == MAX) {
      rearB = frontB = MAX - 1;
      QUEUE[rearB] = val;
    } else
      QUEUE[--rearB] = val;
  }
}

int deleteB() {
  int val;
  if (frontB == MAX) {
    printf("\n UNDERFLOW");
    return -1;
  } else {
    val = QUEUE[frontB];
    frontB--;
    if (frontB < rearB) frontB = rearB = MAX;
    return val;
  }
}

void display_queueB() {
  int i;
  if (frontB == MAX)
    printf("\n QUEUE B IS EMPTY");
  else {
    for (i = frontB; i >= rearB; i--) printf("\t %d", QUEUE[i]);
  }
}

int main() {
  int option, val;
  system("clear");
  do {
    printf("\n *******MENU******");
    printf("\n 1. INSERT IN QUEUE A");
    printf("\n 2. INSERT IN QUEUE B");
    printf("\n 3. DELETE FROM QUEUE A");
    printf("\n 4. DELETE FROM QUEUE B");
    printf("\n 5. DISPLAY QUEUE A");
    printf("\n 6. DISPLAY QUEUE B");
    printf("\n 7. EXIT");
    printf("\n Enter your option : ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        printf("\n Enter the value to be inserted in Queue A : ");
        scanf("%d", &val);
        insertA(val);
        break;
      case 2:
        printf("\n Enter the value to be inserted in Queue B : ");
        scanf("%d", &val);
        insertB(val);
        break;
      case 3:
        val = deleteA();
        if (val != -1) printf("\n The value deleted from Queue A = %d", val);
        break;
      case 4:
        val = deleteB();
        if (val != -1) printf("\n The value deleted from Queue B = %d", val);
        break;
      case 5:
        printf("\n The contents of Queue A are : \n");
        display_queueA();
        break;
      case 6:
        printf("\n The contents of Queue B are : \n");
        display_queueB();
        break;
    }
  } while (option != 7);
}