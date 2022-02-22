/* Data Structures Using C, 2nd, Reema Thareja
Chapter 07. Stack: LIFO (Last-In-First-Out) data structure
7.1 Introduction
7.2 Array refresentation of stacks
7.3 Operations on a stack
  7.3.1 Push operation
  7.3.2 pop operation
  7.3.3 Peek operation (Program example 1)
7.4 Linked representation of stacks
7.5 Operations ona linked stack
  7.5.1 Push operation
  7.5.2 Pop operation (Program example 2)
7.6 Multiple stacks (Program example 3)
7.7 Applications of stacks
  7.7.1 Reversing a list (Program example 4)
  7.7.2 Implementing parentheses checker (Program example 5)
  7.7.3 Evaluation of arithmetic expressions
    Polish notations
    Conversion of an infix expression into a postfix expression (Example 7.3)
    (Program example 6)
    Evaluation of a postfix expression (Program example 7)
*/

/*
Programming Example
7. Write a program to evaluate a postfix expression.

# Algorithm
  Step 1. Add a ")" at the end of the postfix expression
  Step 2. Scan every character of the postfix expression and repeat
          Step 3 and 4 until ")" encountered
  Step 3. If an operand is encountered,
          push it on the stack
          If an operator X is encountered, then
          a. Pop the top elements from the stack as A and B as A and B
          b. Evaluate B X A, where A is the topmost element and
            B is the element below A.
          c. Push the result of evaluation on the stack
          [END of IF]
  Step 4. Set result equal to the topmost element of the stack
  Step 5. Exit

  character stack       explanation
  --------------------------------
  9         9           digit -> push
  3         9, 3        digit -> push
  4         9, 3, 4     digit -> push
  *         9, 12       op    -> pop <op> pop
  8         9, 12, 8    digit -> push
  +         9, 20       op    -> pop <op> pop
  4         9, 20, 4    digit -> push
  /         9, 5        op    -> pop2 <op> pop1
  -         4           op    -> pop2 <op> pop1
*/

/**********************************************************
 * headers
 **********************************************************/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()

/**********************************************************
 * macros
 **********************************************************/

#define MAXOP 2     // max size of operand or operator
#define NUMBER '0'  // signal that a number wes found
#define MAXVAL 5
#define BUFFSIZE 10

/**********************************************************
 * headers
 **********************************************************/

int sp = 0;
double val[MAXVAL];
char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;        // next free posotion in buf

/**********************************************************
 * function prototypes
 **********************************************************/

void push(double);
double pop(void);
int getop(char[]);
int getch(void);
void ungetch(int);

void print_valstack();
void print_buf();

/**********************************************************
 * reverse Polish calculator, Not inifx to postfix
 *    ex)   4 5 -       ==> -1
 *          30 4 5 * -  ==> 10
 **********************************************************/

int main(void) {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));  // convert string to float number
        break;
      case '+':
        push(pop() + pop());  // push result into 'val' stack
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) push(pop() / op2);
        break;
      case '\n':
        printf("\t%.8g\n", pop());  // pop the last result from 'val' stack
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

/**********************************************************
 * push: push f onto value stack, 'val'
 * - sp :: global int
 *         index of the last elem of 'val'
 * - val :: global [double]
 **********************************************************/

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, con't push %g\n", f);
}

/**********************************************************
 * pop: pop and return top value from stack 'val'
 **********************************************************/

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/**********************************************************
 * getop: get next operator or numberic operand
 * - modifying parameter array
 * - return operator or signal (number or not)
 * param: char array
 * return: (type int or char)
 *  if neither digit nor period (op) ==> character (op)
 *  if floating point number         ==> NUMBER, signal
 * Side Effect: modify parameter array
 **********************************************************/

int getop(char exp[]) {
  int i, c;

  /* Step 1. Starting with space or tab, skip it!
     if empty space or tab, skip
     after this part, c will be assigned with some character
     which is meither space nor tab. Because
     `s[0] = c = getch()` is executed before comparison part
     `(c == ' ' || c == '\t')`
  */
  while ((exp[0] = c = getch()) == ' ' || c == '\t')
    ;
  exp[1] = '\0';
  /*
     TODO: Is this required?
     What is the meaning of array termination?
     Without line above, this program works.
     At this point, c is neither space nor tab, but ONE character
  */

  /* Step 2. If c is operator (+, -, *, /)
     if not a digit && not a period => return it
  */
  if (!isdigit(c) && c != '.') return c;
  // At this point, c is a operator character

  /* Step 3. If digit
     It can be integer or floating number.
  */
  i = 0;
  if (isdigit(c))  // collect integer part
    while (isdigit(exp[++i] = c = getch()))
      ;
  if (c == '.')  // collect fraction part
    while (isdigit(exp[++i] = c = getch()))
      ;
  exp[i] = '\0';
  // At this point, array exp is stringified number
  // For example, "123", "123.345", ".345"

  /* Step 4. If c met Ctrl-z (EOF)
     then,  bufp++ (bufp = 1)
  */
  if (c != EOF) ungetch(c);

  return NUMBER;
}

/**********************************************************
 * get a (possibly pushed back) character
 * - buf :: global [char]
 * - bufp :: global int, inital value is 0
 *
 * TODO: Are these necessary?
 * - Actually, getch and getchar is not necessary.
 * - These functions are for the situation the array exceed MAXOP
 * - With these functions, this program can do ops more than MAXOP
 **********************************************************/

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

/**********************************************************
 * push back on input
 **********************************************************/

void ungetch(int c) {
  if (bufp >= BUFFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/**********************************************************
 * just for testing
 **********************************************************/

void print_valstack() {
  for (int i = 0; i < MAXVAL; i++) {
    if (val[i] != 0.0) printf("%d: %.1f \n", i, val[i]);
  }
}

void print_buf() {
  for (int i = 0; i < BUFFSIZE; i++) {
    if (buf[i] != ' ') printf("%d: %c ", i, buf[i]);
  }
}