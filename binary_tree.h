#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree{
    int node;
    struct binary_tree* left_tree;
    struct binary_tree* right_tree;
    struct binary_tree* parent;
} binary_tree;

binary_tree* new_binary_tree(int x);
void clear_binary_tree(binary_tree* bt);
binary_tree* unite_binary_trees(binary_tree* lefti, binary_tree* righti, int node);
void print_binary_tree_prefix(binary_tree* bt);
int number_of_nodes(binary_tree* bt);


#endif
