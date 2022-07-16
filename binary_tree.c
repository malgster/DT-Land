/**
 * @file binary_tree.c
 * @author malgster
 * @brief implementation of binary trees
 * 
 */

#include "binary_tree.h"

/**
 * @brief create a new binary tree with a node
 * 
 * @param x 
 * @return binary_tree* 
 */
binary_tree* new_binary_tree(const int x){
    binary_tree* bt = malloc(sizeof(*bt));
    if (bt == NULL){
        printf("error in memory allocation : FORCED EXIT\n");
        exit(1);
    }

    bt->node = x;
    bt->left_tree = NULL;
    bt->right_tree = NULL;
    bt->parent = NULL;

    printf("node [%d] created\n", bt->node);
    return bt;
}

/**
 * @brief clear the entire binary tree (we loving recursion)
 * 
 * @param bt 
 */
void clear_binary_tree(binary_tree* bt){
    if (bt == NULL){
        printf("the tree is already empty");
        return;
    }
    printf("freeing node [%d]\n", bt->node);

    clear_binary_tree(bt->left_tree);
    clear_binary_tree(bt->right_tree);
    free(bt);
}

/**
 * @brief join the two binary trees in param
 * 
 * @param lefti 
 * @param righti 
 * @param node 
 * @return binary_tree* 
 */
binary_tree* unite_binary_trees(binary_tree* lefti, binary_tree* righti, int node){
    binary_tree* bt = new_binary_tree(node);
    clear_binary_tree(bt->left_tree);
    bt->left_tree = lefti;
    bt->right_tree = righti;

    if (lefti != NULL){
        lefti->parent = bt;
    }

    if (righti != NULL){
        righti->parent = bt;
    }
    return bt;
}

/**
 * @brief prints the entire binary tree
 * 
 * @param bt 
 */
void print_binary_tree(binary_tree* bt){
    if (bt == NULL){
        printf("nothing to print, the tree is empty");
        return;
    }

    printf("printing the tree :\n");

    if (bt->parent != NULL){ // if it's the root
        printf("(%d) -> %d\n", bt->parent->node, bt->node);
    } else {
        printf("(%d)\n", bt->node);
    }
    if (bt->left_tree != NULL) print_binary_tree(bt->left_tree);
    if (bt->left_tree != NULL) print_binary_tree(bt->right_tree);
}

/**
 * @brief returns the nodes's number in the bt
 * 
 * @param bt 
 * @return int 
 */
int number_of_nodes(binary_tree* bt){
        return (bt == NULL) ? 0 : (number_of_nodes(bt->left_tree) + number_of_nodes(bt->right_tree) + 1);
}

int main(void){
    return 0;
}