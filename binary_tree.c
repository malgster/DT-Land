#include "binary_tree.h"

binary_tree* new_binary_tree(int x){
    binary_tree* bt = malloc(sizeof(*bt));
    if (bt == NULL){
        printf("error in memory allocation : FORCED EXIT");
        exit(1);
    }

    bt->node = x;
    bt->left_tree = NULL;
    bt->right_tree = NULL;
    bt->parent = NULL;

    printf("node [%d] created\n", bt->node);
    return bt;
}

void clear_binary_tree(binary_tree* bt){
    if (bt == NULL){
        printf("the binary tree is already empty");
        return;
    }
    printf("freeing node [%d]\n", bt->node);

    clear_binary_tree(bt->left_tree);
    clear_binary_tree(bt->right_tree);
    free(bt);
}

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

int main(void){
    return 0;
}