/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
9. Write a program to merge two sorted linked lists.
The resultant list must also be sorted.

https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/

*/

/* C program to merge two sorted linked lists */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

/**********************************************************
 * prototypes
 **********************************************************/

void MoveNode(struct Node** destRef, struct Node** sourceRef);
struct Node* SortedMerge(struct Node* a, struct Node* b);
void push(struct Node** head_ref, int new_data);
void printList(struct Node* node);

/**********************************************************
 * Driver program to test above functions
 **********************************************************/

int main() {
  /* Start with the empty list */
  struct Node* res = NULL;
  struct Node* a = NULL;
  struct Node* b = NULL;

  /* Let us create two sorted linked lists to test the functions
  Created lists, a: 5->10->15, b: 2->3->20 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);

  push(&b, 20);
  push(&b, 3);
  push(&b, 2);

  /* Remove duplicates from linked list */
  res = SortedMerge(a, b);

  printf("Merged Linked List is: \n");
  printList(res);

  return 0;
}

/**********************************************************
 * SortedMerge (recursive) - version 1
 **********************************************************/

struct Node* SortedMerge(struct Node* a, struct Node* b) {
  struct Node dummy;          /* a dummy first node to hang the result on */
  struct Node* tail = &dummy; /* tail points to the last result node */

  /* so tail->next is the place to add new nodes to the result. */
  dummy.next = NULL;
  while (1) {
    /* Base case: if either list runs out, use the other list */
    if (a == NULL) {
      tail->next = b;
      break;
    } else if (b == NULL) {
      tail->next = a;
      break;
    }
    /* recursive case */
    if (a->data <= b->data)
      MoveNode(&(tail->next), &a);
    else
      MoveNode(&(tail->next), &b);

    tail = tail->next;
  }

  return (dummy.next);
}

/**********************************************************
 * MoveNode
    Before calling MoveNode():
    source == {1, 2, 3}
    dest == {1, 2, 3}

    Affter calling MoveNode():
    source == {2, 3}
    dest == {1, 1, 2, 3}
 **********************************************************/

void MoveNode(struct Node** destRef, struct Node** sourceRef) {
  struct Node* newNode = *sourceRef; /* the front source node */
  assert(newNode != NULL);
  *sourceRef = newNode->next; /* Advance the source pointer */
  newNode->next = *destRef;   /* Link the old dest off the new node */
  *destRef = newNode;         /* Move dest to point to the new node */
}

/**********************************************************
 * push
 * Function to insert a node at the beginging of the linked list
 **********************************************************/

void push(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;    /* put in the data */
  new_node->next = (*head_ref); /* link the old list off the new node */
  (*head_ref) = new_node;       /* move the head to point to the new node */
}

/**********************************************************
 * printList
 * Function to print nodes in a given linked list
 **********************************************************/

void printList(struct Node* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}