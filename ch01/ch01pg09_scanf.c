/* Data Structures Using C, 2nd, Reema Thareja
Chapter 01. Introduction to C

Program Exercise 9.
Write a program to prepare a grocery bill. Enter
the name of the items purchased, quantity in which
it is purchased, and its price per unit. Then display
the bill in the following format:

    ************ B I L L ************
    Item Quantity Price Amount
    ––––––––––––––––––––––––––––––––––––––––––––––––
    –––––––––––––––––––––––––––––––––––––––––––––––––
    Total Amount to be paid
    ––––––––––––––––––––––––––––––––––––––––––––––––

https://fresh2refresh.com/c-programming/c-passing-struct-to-function/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define MAX_ITEMS 2

struct item {
  char item[NAME_LEN];
  int quantity;
  float price;
  float amount;
};

void buy_val(struct item);
void get_name(char arr[NAME_LEN]);
void print_name(char *);
void print_items(struct item its[MAX_ITEMS], int num);

int main() {
  int num_items;                 // the number of items actually entered
  struct item items[MAX_ITEMS];  // list of structure (items)
  float totalPayment = 0.0;      // total cost

  for (int i = 0; i < MAX_ITEMS; i++) {
    printf("Do you wanna continue shopping? [Y/N] ");
    char yesOrNo;
    scanf(" %c%*c", &yesOrNo);
    if (yesOrNo == 'N' || yesOrNo == 'n') break;

    char itname[20];
    int qnt;
    float prc;
    float amt;

    printf("Enter item name (max 20 characters): ");
    get_name(itname);

    printf("Enter quantity: ");
    scanf(" %d", &qnt);
    printf("Enter price: ");
    scanf(" %f", &prc);
    amt = qnt * prc;
    totalPayment += amt;
    num_items++;

    strcpy(items[i].item, itname);
    items[i].quantity = qnt;
    items[i].price = prc;
    items[i].amount = amt;
  }
  printf("You've aleady purchased max number of items.\n");

  printf("************ B I L L ************\n");
  printf("%-20s %8s %10s %10s\n", "Item", "Quantity", "Price", "Amount");
  printf("––––––––––––––––––––––––––––––––––––––––––––––––---\n\n");
  print_items(items, num_items);
  printf("\n––––––––––––––––––––––––––––––––––––––––––––––––---\n");
  printf("Total Amount to be paid:           %.3f\n", totalPayment);
  printf("––––––––––––––––––––––––––––––––––––––––––––––––---\n");
  return 0;
}

/* function for buying item */
void buy_val(struct item it) {}

/* helper function for get item name
   TODO: Can you do this by double pointer?
*/
void get_name(char *arr) {
  char c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    arr[i] = c;
    i++;
  }
  arr[i] = '\0';
}

/* helper function for test: printing string argument */
void print_name(char *arr) {
  while (*arr) {
    printf("%c", *arr);
    arr++;
  }
}

/* helper function for print grocery bill */
void print_items(struct item its[MAX_ITEMS], int num) {
  for (int i = 0; i < num; i++)
    printf("%-20s %8d %10.3f %10.3f\n", its[i].item, its[i].quantity,
           its[i].price, its[i].amount);
}

/* TODO: To be improved:
- printf + scanf problem (solved)
- check the number of items in the structure list (solved)
- check whether item name is alread exist in the structure list (solved)
- print only inserted items (solved)
*/