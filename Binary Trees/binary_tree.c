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
    /* only the root is init */
    bt->node = x; 
    bt->left_tree = NULL;
    bt->right_tree = NULL;
    bt->parent = NULL;
    bt->type = root; // default type

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
        return;
    }
    printf("freeing node [%d]\n", bt->node);

    /*recurcively deleting every branch*/
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
 */
void unite_binary_trees(binary_tree* bt ,binary_tree* lefti, binary_tree* righti){
    clear_binary_tree(bt->left_tree);

    /*uniting*/
    bt->left_tree = lefti;
    bt->right_tree = righti;

    bt->left_tree->type = left;
    bt->right_tree->type = right;

    /* a null tree doesn't have a parent */
    if (lefti != NULL){
        lefti->parent = bt; 

    }

    if (righti != NULL){
        righti->parent = bt;
    }
}

/**
 * @brief print a 2D representation of the binary tree
 * 
 * @param bt 
 * @param node_type 
 * @param level 
 */
void print_tree_2d(binary_tree* bt, Type node_type, int level){
   
    int i;
    if (bt == NULL){
        return;
    }

    print_tree_2d(bt->right_tree, left, level+1);
    
    switch (node_type){
        case 0: // root
        printf("(%d)\n", bt->node);
        break;

        case 1: // right
        for (i = 0; i < level ; i++) printf("\t");
        printf("\\\n");
        for(i =0; i < level; i++) printf("\t");
        printf("(%d)\n", bt->node);
        break;

        case 2: // left
        for(i = 0; i < level; i++) printf("\t");
        printf("(%d)\n", bt->node);
        for (i= 0; i<level; i++) printf("\t");
        printf("/\n");
        break;
    }
    print_tree_2d(bt->left_tree, right, level+1);
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

/**
 * @brief calculate the height of the given tree
 * 
 * @param bt 
 * @return int 
 */
int tree_height(binary_tree* bt){

    if (bt == NULL) return 0;

    int left_height = tree_height(bt->left_tree);
    int right_height = tree_height(bt->right_tree);

    /*longest path*/
    return (left_height > right_height) ? left_height + 1 : right_height + 1;

}

/**
 * @brief traverse the binary tree in inorder traversal
 * 
 * @param bt 
 */
static void raw_inorder_traversal(binary_tree* bt){
    if (bt == NULL) return;
    raw_inorder_traversal(bt->left_tree);
    printf("[%d] ->", bt->node);
    raw_inorder_traversal(bt->right_tree);
}

/**
 * @brief pretty printing inorder
 * 
 * @param bt 
 */
void inorder_traversal(binary_tree* bt){
    printf("Inorder traversal :\n");
    raw_inorder_traversal(bt);
    printf("\n");
}

/**
 * @brief traverse the binary tree in preorder traversal
 * 
 * @param bt 
 */
static void raw_preorder_traversal(binary_tree* bt){
    if (bt == NULL) return;
    printf("[%d] ->", bt->node);
    raw_preorder_traversal(bt->left_tree);
    raw_preorder_traversal(bt->right_tree);
}

/**
 * @brief pretty printing preorder
 * 
 * @param bt 
 */
void preorder_traversal(binary_tree* bt){
    printf("Preorder traversal :\n");
    raw_preorder_traversal(bt);
    printf("\n");
}

/**
 * @brief traverse the binary tree in postorder traversal
 * 
 * @param bt 
 */
static void raw_postorder_traversal(binary_tree* bt){
    if (bt == NULL) return;
    raw_postorder_traversal(bt->left_tree);
    raw_postorder_traversal(bt->right_tree);
    printf("[%d] ->", bt->node);
}

/**
 * @brief 
 * 
 * @param bt 
 */
void postorder_traversal(binary_tree* bt){
    printf("Postorder traversal :\n");
    raw_postorder_traversal(bt);
    printf("\n");
}

int main(void){
    binary_tree* parent = new_binary_tree(0);
    binary_tree* left = new_binary_tree(1);
    binary_tree* right = new_binary_tree(2);
    binary_tree* left_1 = new_binary_tree(3);
    binary_tree* left_2 = new_binary_tree(4);
    binary_tree* right_1 = new_binary_tree(5);
    binary_tree* right_2 = new_binary_tree(6);
    binary_tree* left_1_1 = new_binary_tree(10);
    binary_tree* left_1_2 = new_binary_tree(11);
    binary_tree* left_2_1 = new_binary_tree(12);
    binary_tree* left_2_2 = new_binary_tree(13);
    binary_tree* right_1_1 = new_binary_tree(7);
    binary_tree* right_1_2 = new_binary_tree(8);
    binary_tree* right_2_1 = new_binary_tree(9);
    binary_tree* right_2_2 = new_binary_tree(14);
    unite_binary_trees(parent,left, right);
    unite_binary_trees(left, left_1, left_2);
    unite_binary_trees(right, right_1, right_2);
    unite_binary_trees(left_1, left_1_1, left_1_2);
    unite_binary_trees(left_2, left_2_1, left_2_2);
    unite_binary_trees(right_1, right_1_1, right_1_2);
    unite_binary_trees(right_2, right_2_1, right_2_2);
    print_tree_2d(parent, parent->type, 0);
    printf("\nnumber of nodes : %d\n", number_of_nodes(parent));
    printf("\ntree height : %d\n", tree_height(parent));
    inorder_traversal(parent);
    postorder_traversal(parent);
    preorder_traversal(parent);
    clear_binary_tree(parent);
    return 0;
}