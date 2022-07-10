#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct NodeListElement{
    int value;
    struct Node* next;
} NodeListElement, *NodeList;


// for each node there is a adjency list containing all the nodes linked to him 
typedef struct AdjencyList{
    int numbrOfElements;
    NodeListElement head; // head of the adjency list 
} AdjencyList;

typedef struct Graph{
    int isOriented; // 1 if yes : 0 if no (i know i can define bools but kinda don't want to)
    int nbrVertices; // direct "links" between nodes 
    AdjencyList* neighbours;
} GraphElement, *Graph; 

Graph new_graph(int vertices, int isOriented);
int graph_is_empty(Graph gr);
void free_graph(Graph gr);

#endif