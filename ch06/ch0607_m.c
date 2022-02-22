/* Data Structures Using C, 2nd, Reema Thareja
Chapter 06. Linked Lists
6.1 Introduction
  6.1.1 Basic terminology
  6.1.2 Linked lists versus arrays
  6.1.3 Memory allocation and de-allocation for a linked list
6.2 Singly linked lists
  6.2.1 Traversing a linked list
  6.2.2 Searching fir a value in a linked list
  6.2.3 Inserting a new node in a linked list
    Inserting a node at the beginning of a linked list
    Inserting a node at the end of a linked list
    Inserting a node after a given node in a linked list
    Inserting a node before a given node in a linked list
  6.2.4 Deleting a node from a linked list
    Deleting the first node from a linked list
    Deleting the last node from a linked list
    Deleting the node after a given node in a linked list (Program example 1)
6.3 Circular linked lists
  6.3.1 Inserting a new node in a circular linked list
    Inserting a node at the beginning of a circular linked list
    Inserting a node at the end of a circular linked list
  6.3.2 Deleting a node from a circular linked list
    Deleting the first node from a circular linked list
    Deleting the last node from a circular linked list (Program example 2)
6.4 Doubly linked lists
  6.4.1 Inserting a new node in a doubly linked list
    Inserting a node at the beginning of a doubly linked list
    Inserting a node at the end of a doubly linked list
    Inserting a node after a given node in a doubly linked list
    Inserting a node before a given node in a doubly linked list
  6.4.2 Deleting a node from a doubly linked list
    Deleting the first node from a doubly linked list
    Deleting the last node from a doubly linked list
    Deleting the node after a given node in a doubly linked list
    Deleting the node before a given node in a doubly linked list
    (Program example 3)
6.5 Circular doubly linked lists
  6.5.1 Inserting a new node in a circular doubly linked list
    Inserting a node at the beginning of a circular doubly linked list
    Inserting a node at the end of a circular doubly linked list
  6.5.2 Deleting a node from a circular doubly linked list
    Deleting the first node from a circular doubly linked list
    Deleting the last node from a circular doubly linked list
    (Program example 4)
6.6 Header linked lists (Program example 5)
6.7 Multi-linked lists
6.8 Applications of linked lists
  6.8.1 Polynomial representation (Program example 6)
*/

/*
Multi-linked list

https://webdocs.cs.ualberta.ca/~holte/T26/top.realTop.html
https://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/

1) Take "cur" pointer, which will point to head of the fist level of the list
2) Take "tail" pointer, which will point to end of the first level of the list
3) Repeat the below procedure while "curr" is not NULL.
    I) if current node has a child then
    a) append this new child list to the "tail"
        tail->next = cur->child
    b) find the last node of new child list and update "tail"
        tmp = cur->child;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tail = tmp;
    II) move to the next node. i.e. cur = cur->next

*/

// Program to flatten list with next and child pointers
#include <stdio.h>
#include <stdlib.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// A linked list node has data, next pointer and child pointer
struct Node {
  int data;
  struct Node *next;
  struct Node *child;
};

struct Node *createList(int *arr, int n);
void printList(struct Node *head);
struct Node *createLists(void);
void flattenList(struct Node *head);

/**********************************************************
 * main function
 **********************************************************/

int main(void) {
  struct Node *head = NULL;
  head = createLists();
  flattenList(head);
  printList(head);

  return 0;
}

/**********************************************************
 * A utility function to create a linked list with n nodes.
 * The data * of nodes is taken from arr[].
 * All child pointers are set as NULL
 *
 * TODO:
   https://stackoverflow.com/questions/51009229/c-malloc-for-a-pointer-to-struct
   Do I cast the result of malloc?
   https://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc
 **********************************************************/

struct Node *createList(int *arr, int n) {
  struct Node *head = NULL;
  struct Node *ptr;

  for (int i = 0; i < n; ++i) {
    if (head == NULL)
      head = ptr = (struct Node *)malloc(sizeof(*ptr));
    else {
      ptr->next = (struct Node *)malloc(sizeof(*ptr));
      ptr = ptr->next;
    }
    ptr->data = arr[i];
    ptr->next = ptr->child = NULL;
  }
  return head;
}

/**********************************************************
 * A utility function to print all nodes of a linked list
 **********************************************************/
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

/**********************************************************
 * This function creates the input list.
 * The created list is same as shown in the above figure
 **********************************************************/
struct Node *createLists(void) {
  int arr1[] = {10, 5, 12, 7, 11};
  int arr2[] = {4, 20, 13};
  int arr3[] = {17, 6};
  int arr4[] = {9, 8};
  int arr5[] = {19, 15};
  int arr6[] = {2};
  int arr7[] = {16};
  int arr8[] = {3};

  /* create 8 linked lists */
  struct Node *head1 = createList(arr1, SIZE(arr1));
  struct Node *head2 = createList(arr2, SIZE(arr2));
  struct Node *head3 = createList(arr3, SIZE(arr3));
  struct Node *head4 = createList(arr4, SIZE(arr4));
  struct Node *head5 = createList(arr5, SIZE(arr5));
  struct Node *head6 = createList(arr6, SIZE(arr6));
  struct Node *head7 = createList(arr7, SIZE(arr7));
  struct Node *head8 = createList(arr8, SIZE(arr8));

  /* modify child pointers to create the list shown above
  https://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/

    * head2
  head1 --> 10 - 5 - 12 - 7 - 11
                          * head3 --> 17 - 6
                              * head4 --> 9 -- 8
                                  * head5 --> 19 - 15

                         * head8 --> 3
                     * head7 --> 16
  head2 --> 4 - 20 - 13
                * head6 --> 2

  */
  head1->child = head2;
  head1->next->next->next->child = head3;
  head3->child = head4;
  head4->child = head5;
  head2->next->child = head6;
  head2->next->next->child = head7;
  head7->child = head8;

  /* Return head pointer of first linked list. Note that all nodes are
  reachable from head1 */
  return head1;
}

/**********************************************************
 * The main function that flattens a multilevel linked list
 **********************************************************/
void flattenList(struct Node *head) {
  /*Base case*/
  if (head == NULL) return;

  struct Node *tmp;

  /* Find tail node of first level linked list */
  struct Node *tail = head;
  while (tail->next != NULL) tail = tail->next;

  // One by one traverse through all nodes of first level
  // linked list till we reach the tail node
  struct Node *cur = head;
  while (cur != tail) {
    // If current node has a child
    if (cur->child) {
      // then append the child at the end of current list
      tail->next = cur->child;

      // and update the tail to new last node
      tmp = cur->child;
      while (tmp->next) tmp = tmp->next;
      tail = tmp;
    }

    // Change current node
    cur = cur->next;
  }
}