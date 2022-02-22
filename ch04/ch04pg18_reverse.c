/* Data Structures Using C, 2nd, Reema Thareja
Chapter 04. Strings

Programming exercises
18. Write a program to convert the given string "hello world" to "dlrow olleh"

TODO: Use stack
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 20
char stack[MAX];
int top = -1;

void push(char st[], char val);
char pop(char st[]);
char peek(char st[]);
void display(char st[]);

int main() {
  char str[12] = "hello world";
  for (int i = 0; i < 11; i++) {
    push(stack, str[i]);
  }

  for (int i = 0; i < 11; i++) {
    printf("%c", pop(stack));
  }

  return 0;
}

void push(char st[], char val) {
  if (top == MAX - 1) {
    /* top == the last index of stack (array) */
    printf("stack overflow\n");
  } else {
    /* there's some free space, so we can push more */
    top++;
    st[top] = val;
  }
}

char pop(char st[]) {
  char val;
  if (top == -1) {
    /* stack is empty */
    printf("stack underflow\n");
    return -1;
  } else {
    val = st[top];
    top--;
    return val;
  }
}

void display(char st[]) {
  int i;
  if (top == -1)
    printf("STACK IS EMPTY\n");
  else {
    for (i = top; i >= 0; i--) printf("%d ", st[i]);
    printf("\n");  // Added for pretty format
  }
}

char peek(char st[]) {
  if (top == -1) {
    printf("STACK IS EMPTY\n");
    return -1;
  } else
    return (st[top]);
}