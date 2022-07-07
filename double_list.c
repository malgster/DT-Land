#include "double_list.h"

double_list* new_double_list(){
    return NULL;
}


int empty_double_list(double_list* dli){
    return (dli = NULL) ? 1 : 0;
}

int double_list_size(double_list* dli){
    return (empty_double_list(dli)) ? 0 : dli->size;
}

int dl_first_node(double_list* dli){
    if (empty_double_list(dli)) exit(1);
    return dli->start->content;
}

int dl_last_node(double_list* dli){
    if (empty_double_list(dli)) exit(1);
    return dli->end->content;
}

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
        dli = malloc(sizeof(*li));
        if (dli == NULL){
            printf("dynamic allocation error : FORCED EXIT");
            exit(1);
        }
        dli->size = 0;
        dli->start = node;
        dli->end = node;
    } else {
        dli->end->next = node;
        element->back = dlil->end;
        li->end = element;
    }
    li->size = li->size + 1;
    return dli;
}

double_list* add_node_end_dl(double_list* dli, int x){

}

double_list* pop_back_dl(double_list* dli){
    if (empty_double_list(dli)){
        printf("the double list is already empty");
        return new_double_list();
    }
    if (dli->start == dli->end){ // si vrai on a un seul élément dans la liste
        free(dli);
        dli = NULL // on sait jamais
        return new_double_list();
    }

    double_list_node* temp_node = dli->end;
    dli->end = dli->end->back;
    dli->end->next = NULL;
    temp_node->next = NULL;
    temp->node->back = NULL;
    free(temp_node); temp_node = NULL;

    dli->length = dli->length-1
    return dli;

}


double_list* pop_front_dl(double_list* dli){
    if (empty_double_list(dli)){
        printf("the double list is already empty");
        return new_double_list();
    }
    if (dli->start == dli->end){ // si vrai on a un seul élément dans la liste
        free(dli);
        dli = NULL // on sait jamais
        return new_double_list();
    }

    double_list_node* temp_node = dli->start;
    dli->start = dli->start->next;
    dli->start->back = NULL;
    temp_node->next = NULL;
    temp_node->back = NULL;
    free(temp_node); temp_node = NULL;

    dli->length = dli->length-1
    return dli;

} 

void print_double_list(double_list* dli){
    if (empty_double_list(dli)){
        printf("la liste est vide");
        return;
    }
    double_list_node* temp_dl_node = dli->start;
    while(temp_dl_node->next != NULL){
        printf("[%d] ", temp_dl_node->content);
        temp_dl_node = temp_dl_node->next
    }
    printf("\n");
}




