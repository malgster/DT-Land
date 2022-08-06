/**
 * @file double_list.c
 * @author malgster
 * @brief implementation of the double lists
 * 
 * 
 */

#include "double_list.h"


/**
 * @brief create a NULL double list
 * 
 * @return double_list* 
 */
double_list* new_double_list(){
    return NULL;
}

/**
 * @brief returns 1 if the dl is empty : 0 if not
 * 
 * @param dli 
 * @return int 
 */
int empty_double_list(double_list* dli){
    return (dli == NULL) ? 1 : 0;
}

/**
 * @brief return the dl's size
 * 
 * @param dli 
 * @return int 
 */
int double_list_size(double_list* dli){
    return (empty_double_list(dli)) ? 0 : dli->size;
}
/**
 * @brief returns the first node of the dl
 * 
 * @param dli 
 * @return int 
 */
int dl_first_node(double_list* dli){
    if (empty_double_list(dli)) {
        printf("the list is empty");
        exit(0);
    }
    return dli->start->content;
}

/**
 * @brief return the last node of the dl
 * 
 * @param dli 
 * @return int 
 */
int dl_last_node(double_list* dli){
    if (empty_double_list(dli)) {
        printf("the list is empty");
        exit(0);
    }
    return dli->end->content;
}

/**
 * @brief adds a node at the end of the list
 * 
 * @param dli 
 * @param x 
 * @return double_list* 
 */
double_list* add_node_end_dl(double_list* dli, int x){
    double_list_node* node;
    node = malloc(sizeof(*node));
    if (node == NULL){
        printf("dynamic allocation error : FORCED EXIT");
        exit(1);

    }
    node->content = x;
    node->next = NULL;
    node->back = NULL;

    if (empty_double_list(dli)){ 
        dli = malloc(sizeof(*dli));
        if (dli == NULL){
            printf("dynamic allocation error : FORCED EXIT");
            exit(1);
        }
        /*the first only node in the list*/
        dli->size = 0;
        dli->start = node;
        dli->end = node;
    } else {
        dli->end->next = node; // the end of the list is linked to the next new element
        node->back = dli->end; // the back of the new node needs to point to the last element
        dli->end = node; // the new node is now the last element
    }
    dli->size++; // increments the length
    return dli;
}

/**
 * @brief adds a node a the end of the dl
 * 
 * @param dli 
 * @param x 
 * @return double_list* 
 */
double_list* add_node_front_dl(double_list* dli, int x){
    double_list_node* node;
    node = malloc(sizeof(*node));
    if (node == NULL){
        printf("dynamic allocation error : FORCED EXIT");
        exit(1);

    }
    node->content = x;
    node->next = NULL; 
    node->back = NULL;

    if (empty_double_list(dli)){ 
        dli = malloc(sizeof(*dli));
        if (dli == NULL){
            printf("dynamic allocation error : FORCED EXIT");
            exit(1);
        }
        dli->size = 0;
        /*start and end are the added node*/
        dli->start = node;
        dli->end = node;
    } else {
        dli->start->back = node; // the start of the list is linked to the new element
        node->next = dli->start; // the next pointer of the new node needs to point to the first element
        dli->start = node; // the new node is now the first element
    }
    dli->size++;

    return dli;
}

/**
 * @brief delete the element at the back of the dl
 * 
 * @param dli 
 * @return double_list* 
 */
double_list* pop_back_dl(double_list* dli){
    if (empty_double_list(dli)){
        printf("the double list is already empty");
        return new_double_list();
    }
    if (dli->start == dli->end){ // if true we only have on element in the list
        free(dli);
        dli = NULL;
        return new_double_list();
    }

    double_list_node* temp_node = dli->end;
    dli->end = dli->end->back;
    dli->end->next = NULL;
    temp_node->next = NULL;
    temp_node->back = NULL;
    free(temp_node); temp_node = NULL;

    dli->size--;
    return dli;

}

/**
 * @brief delete the element at the front of the dl
 * 
 * @param dli 
 * @return double_list* 
 */
double_list* pop_front_dl(double_list* dli){
    if (empty_double_list(dli)){
        printf("the double list is already empty");
        return new_double_list();
    }
    if (dli->start == dli->end){ // if true we only have one element in the list
        free(dli);
        dli = NULL; // we never know
        return new_double_list();
    }

    double_list_node* temp_node = dli->start;
    dli->start = dli->start->next;
    dli->start->back = NULL;
    temp_node->next = NULL;
    temp_node->back = NULL;
    free(temp_node); temp_node = NULL;

    dli->size = dli->size-1;
    return dli;

} 


/**
 * @brief prints the dl from it's start element
 * 
 * @param dli 
 */
void print_from_start(double_list* dli){
    if (empty_double_list(dli)){
        printf("the list is empty");
        return;
    }
    double_list_node* temp_dl_node = dli->start;
    while(temp_dl_node != NULL){
        printf("[%d] ", temp_dl_node->content);
        temp_dl_node = temp_dl_node->next;
    }
    printf("\n");
}

/**
 * @brief prints the dl from it's end element
 * 
 * @param dli 
 */
void print_from_end(double_list* dli){
    if (empty_double_list(dli)){
        printf("the list is empty");
        return;
    }
    double_list_node* temp_dl_node = dli->end;
    while(temp_dl_node != NULL){
        printf("[%d] ", temp_dl_node->content);
        temp_dl_node = temp_dl_node->back;
    }
    printf("\n");
}

/**
 * @brief free the entire dl structure in memory
 * 
 * @param dli 
 * @return double_list* 
 */
double_list* clear_double_list(double_list* dli){
    while (!empty_double_list(dli)){
        dli = pop_back_dl(dli);
    }
    printf("DL cleared successfully\n");
    return new_double_list();
}

int main(void) {
    double_list* dli = new_double_list();
    dli = add_node_front_dl(dli, 1);
    dli = add_node_front_dl(dli, 2);
    dli = add_node_front_dl(dli, 3);
    dli = add_node_front_dl(dli, 4);
    print_from_start(dli);
    print_from_end(dli);
    clear_double_list(dli);
    return 0;
}




