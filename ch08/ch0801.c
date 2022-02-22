/* Data Structures Using C, 2nd, Reema Thareja
Chapter 08. Queues
8.1 Introduction
8.2 Array representation of queues
  Operations on queues (Program example 1)
*/

/*
Programming Example
1. Write a program to implement a linear queue. (array)

# linear vs. linked
- linear queue: array
- linked queue: linked list

# visualization
idx      0 1 2 3 4 5
empty:   -            front = rear = -1
insert:  e            front = rear = 0
delete:  -            front = -1, rear = 0 --> -1

TODO: What is the condition for `front > rear`
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // Changing this value will change length of array
int queue[MAX];
int front = -1, rear = -1;

/**********************************************************
Function Prototypes
**********************************************************/

void insert(void);
int delete_element(void);
int peek(void);
void display(void);

/**********************************************************
Main Function
**********************************************************/

int main(int argc, char *argv[]) {
  int option, val;
  do {
    printf("* ****MAIN MENU * ****\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Peek\n");
    printf("4. Display the queue\n");
    printf("5. EXIT\n");

    printf("Enter your option: \n");
    scanf("%d", &option);

    switch (option) {
      case 1:
        insert();
        break;
      case 2:
        val = delete_element();
        if (val != -1) printf("The number deleted is : % d\n", val);
        break;
      case 3:
        val = peek();
        if (val != -1) printf("The first value in queue is : % d\n", val);
        break;
      case 4:
        display();
        break;
    }
  } while (option != 5);

  return 0;
}

/**********************************************************
Function Definitions
**********************************************************/

void insert() {
  int num;
  printf("Enter the number to be inserted in the queue: ");
  scanf("%d", &num);

  /* if queue is full */
  if (rear == MAX - 1) printf("OVERFLOW.\n");
  /* if queue is empty */
  else if (front == -1 && rear == -1)
    front = rear = 0;
  /* else move rear to the next position */
  else
    rear++;
  queue[rear] = num;
}

int delete_element() {
  int val;
  /* if queue is empty */
  if (front == -1 || front > rear) {  // TODO: front > rear??
    printf("UNDERFLOW.\n");
    return -1;
  } else {
    val = queue[front];
    front++;
    if (front > rear) front = rear = -1;
    return val;
  }
}

int peek() {
  if (front == -1 || front > rear) {
    printf("QUEUE IS EMPTY.\n");
    return -1;
  } else {
    return queue[front];
  }
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