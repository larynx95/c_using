/* Data Structures Using C, 2nd, Reema Thareja
Chapter 08. Queues

Programming Exercises
1. What is a priority queue? Give its applications.

data + priority + pointer

TODO: What is real world example for priority queue?
  https://stackoverflow.com/questions/48364680/what-is-real-world-example-for-priority-queue
  Dijkstra's Shortest Path Algorithm
  https://www.thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html
*/

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main() {
  int i, j, n, u;
  /*
  // for user input
  printf("Enter no. of vertices:");
  scanf("%d", &n);
  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", &G[i][j]);
  */

  // using 2D array aleady defined
  int G[MAX][MAX] = {{0, 10, 0, 30, 100},
                     {10, 0, 50, 0, 0},
                     {0, 50, 0, 20, 10},
                     {30, 0, 20, 0, 60},
                     {100, 0, 10, 60, 0}};

  printf("Enter the starting node: ");
  scanf("%d", &u);

  dijkstra(G, n, u);

  return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // pred[] stores the predecessor of each node
  // count gives the number of nodes seen so far
  // create the cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (G[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = G[i][j];

  // initialize pred[],distance[] and visited[]
  for (i = 0; i < n; i++) {
    distance[i] = cost[startnode][i];
    pred[i] = startnode;
    visited[i] = 0;
  }

  distance[startnode] = 0;
  visited[startnode] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    // nextnode gives the node at minimum distance
    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    // check if a better path exists through nextnode
    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // print the path and distance of each node
  for (i = 0; i < n; i++)
    if (i != startnode) {
      printf("Distance of node %d = %d\n", i, distance[i]);
      printf("Path=%d\n", i);

      j = i;
      do {
        j = pred[j];
        printf("<-%d", j);
      } while (j != startnode);
    }
}