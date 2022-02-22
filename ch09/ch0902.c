/* Data Structures Using C, 2nd, Reema Thareja
Chapter 09. Trees
9.1 Introduction
9.2 Types of trees
  general trees, Forest, Binary trees, Binary search trees
  Expression trees, Tournament trees
*/

/*
* Example 9.2
  Given an expression, Exp = ((a + b) – (c * d)) % ((e ^f) / (g – h)),
  construct the corresponding binary tree.

                     %
                  /     \
                -         /
             /  \       /  \
            +    *     ^    -
           /\    /\   /\    /\
          a  b  c  d f  g   h  i

* Example 9.3
  Given the binary tree, write down the expression that it represents.
  [{(a/b) + (c*d)} ^ {(f % g)/(h – i)}]

                     ^
                  /     \
                +         /
             /  \       /  \
            /    *     %    -
           /\    /\   /\    /\
          a  b  c  d f  g   h  i

* Example 9.4
  Given the expression, Exp = a + b / c * d – e,
  construct the corresponding binary tree.
  Exp = ((a + ((b/c) * d)) – e)
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  //
  return 0;
}