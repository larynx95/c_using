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
8.5 Applications of queues
  Josephus problem (Program example 7)
*/

/*
Programming Example
7. Write a program which finds the solution of Josephus problem using a circular
linked list.

* Josephus problem
  https://en.wikipedia.org/wiki/Josephus_problem

                 o  o      kill n-th soldiers
              o        o
             o          o
             o          o
              o        o
                 o  o
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int player_id;
  struct node *next;
};

struct node *start, *ptr, *new_node;

int main() {
  int n, k, i, count;
  system("clear");

  printf("Enter the number of players: ");
  scanf("%d", &n);
  printf("Enter the value of k (every kth player gets eliminated): ");
  scanf("%d", &k);

  // Create circular linked list containing all the players
  start = malloc(sizeof(struct node));
  start->player_id = 1;
  ptr = start;
  for (i = 2; i <= n; i++) {
    new_node = malloc(sizeof(struct node));
    ptr->next = new_node;
    new_node->player_id = i;
    new_node->next = start;
    ptr = new_node;
  }

  for (count = n; count > 1; count--) {
    for (i = 0; i < k - 1; ++i) ptr = ptr->next;
    ptr->next = ptr->next->next;  // Remove the eliminated player from the
                                  // circular linked list
  }
  printf("The Winner is Player %d", ptr->player_id);

  return 0;
}