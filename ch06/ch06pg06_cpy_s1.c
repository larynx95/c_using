/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists

Programming exercises
6 - optional. Write a program that copies a singly linked list.

http://www.dailyfreecode.com/code/copy-linked-list-another-recursion-2824.aspx
https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/
*/

#include <stdio.h>
#include <stdlib.h>

/* structure containing a data part and link part */
struct node {
  int data;
  struct node *link;
};

void append(struct node **, int);
void copy(struct node *, struct node **);
void display(struct node *);

int main() {
  struct node *first, *second;
  first = second = NULL; /* empty linked lists */

  append(&first, 1);
  append(&first, 2);
  append(&first, 3);
  append(&first, 4);
  append(&first, 5);
  append(&first, 6);
  append(&first, 7);

  system("clear");
  display(first);

  copy(first, &second);

  display(second);

  return 0;
}

/* adds a node at the end of the linked list */
void append(struct node **q, int num) {
  struct node *temp;
  temp = *q;
  /* if the list is empty, create first node */
  if (*q == NULL) {
    *q = malloc(sizeof(struct node));
    temp = *q;
  } else {
    /* go to last node */
    while (temp->link != NULL) temp = temp->link;

    /* add node at the end */
    temp->link = malloc(sizeof(struct node));
    temp = temp->link;
  }

  /* assign data to the last node */
  temp->data = num;
  temp->link = NULL;
}

/* copies a linked list into another */
void copy(struct node *q, struct node **s) {
  if (q != NULL) {
    *s = malloc(sizeof(struct node));

    (*s)->data = q->data;
    (*s)->link = NULL;

    copy(q->link, &((*s)->link));
  }
}

/* displays the contents of the linked list */
void display(struct node *q) {
  printf("\n");

  /* traverse the entire linked list */
  while (q != NULL) {
    printf("%d ", q->data);
    q = q->link;
  }
}