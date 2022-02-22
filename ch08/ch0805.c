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
*/

/*
Programming Example
5. Write a program to implement a priority queue.

# Priroity queue
- An element with higher priority is processed before an element with a lower
priority.
- Two elements with the same priority are processed on a first-come-first-served
(FCFS) basis

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  int priority;  // priority
  struct node *next;
};

struct node *start = NULL;

struct node *insert(struct node *);
struct node *delete (struct node *);
void display(struct node *);

int main() {
  int option;
  do {
    printf("*****MAIN MENU*****\n");
    printf("1. INSERT\n");
    printf("2. DELETE\n");
    printf("3. DISPLAY\n");
    printf("4. EXIT\n");

    printf("Enter your option : ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        start = insert(start);
        break;
      case 2:
        start = delete (start);
        break;
      case 3:
        display(start);
        break;
    }
  } while (option != 4);
}

struct node *insert(struct node *start) {
  int val, pri;
  struct node *new, *ptr;
  new = (struct node *)malloc(sizeof(struct node));

  printf("Enter the value and its priority: ");
  scanf("%d %d", &val, &pri);
  new->data = val;
  new->priority = pri;

  /* if queue is empty or pri of new node is lower than pri of start
     1) start --> NULL
        add it in front of queue
     2) start --> (data: 10, priority: 2: next --> NULL or another node)
        if pri of new node is lower than 2 (pri of start),
        add it in front of queue
  */
  if (start == NULL || pri < start->priority) {
    new->next = start;
    start = new;
  }
  /* if queue is not empty, compare priority
     TODO: Why `ptr->next->priority`, not ptr->priority`?
     new-->(x, 2)--> NULL
     start-->(a, 1)-->(b, 1)-->(c, 2)-->(d, 3)-->(e, 4)--> NULL
     ptr     1<=2     1<=2     2<=2
             ptr      ptr      ptr    ^ ptr->next

     new->next = ptr->next
     ptr->next = new
  */
  else {
    ptr = start;
    while (ptr->next != NULL && ptr->next->priority <= pri) ptr = ptr->next;
    new->next = ptr->next;
    ptr->next = new;
  }
  return start;
}

struct node *delete (struct node *start) {
  struct node *ptr;
  /* if empty */
  if (start == NULL) {
    printf("UNDERFLOW\n");
    exit(EXIT_FAILURE);
  }
  /* delete the foremost node */
  else {
    ptr = start;
    printf("Deleted item is: %d\n", ptr->data);
    start = start->next;
    free(ptr);
  }
  return start;
}

void display(struct node *start) {
  struct node *ptr;
  ptr = start;
  if (start == NULL)
    printf("QUEUE IS EMPTY\n");
  else {
    printf("PRIORITY QUEUE IS: ");
    while (ptr != NULL) {
      printf("%d[priority=%d]\n", ptr->data, ptr->priority);
      ptr = ptr->next;
    }
  }
}