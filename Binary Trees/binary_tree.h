#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <stdio.h>
#include <stdlib.h>

typedef enum Type{
    root, right, left // root = 0 | right = 1 | left = 2
}Type;

typedef struct binary_tree{
    int node;
    struct binary_tree* left_tree;
    struct binary_tree* right_tree;
    struct binary_tree* parent;
    Type type;
} binary_tree;

binary_tree* new_binary_tree(const int x);
void clear_binary_tree(binary_tree* bt);
void unite_binary_trees(binary_tree* bt ,binary_tree* lefti, binary_tree* righti);
void print_binary_tree_prefix(binary_tree* bt);
int number_of_nodes(binary_tree* bt);
void print_tree_2d(binary_tree* bt, Type node_type, int level);
int tree_height(binary_tree* bt);
void inorder_traversal(binary_tree* bt);
void preorder_traversal(binary_tree* bt);
void postorder_traversal(binary_tree* bt);



#endif
