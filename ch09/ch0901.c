/* Data Structures Using C, 2nd, Reema Thareja
Chapter 09. Trees
9.1 Introduction
  9.1.1 Basic terminology
*/

/*
* Basic terminology
  - root, sub-trees, leaf node, path, ancestor node
    descendant node, level number, degreee
    in-degree, out-degree, forest
* Binary trees
  - parent, level number, degree of a node, sibling
    leaf node, edge, path, deepth, height of a tree
    in-degree, out-degree
* Complete binary trees
  - every level, except possibly the last, is completely filled
  - all nodes appears as far left as possible
  - T(n) tree, n nodes, level r of T,
    then, the number of nodes >= at most 2^r nodes
  - H_n = | log_2 (n + 1) |
* Extended binary trees
  - each node has either no child or exactly two children
* Representation of binary trees in the memory
  - linked representation of binary trees

                     [L 1 R]
                    /       \
             [L 2 R]         [L 3 X]
            /       \       /
        [X 4 X]  [X 5 X] [X 6 X]

*/