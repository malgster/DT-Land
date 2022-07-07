#include "stack.h"

stack* new_stack(void){ // une liste vide = pas d'éléments = NULL
    return NULL;
}

int stack_is_empty(stack* st){
    return (st == NULL) ? 1 : 0;
}

stack* stack_on_stack(stack* st, int x){ // ajoute un élément au dessus de la pile
    StackElement* element;
    element = malloc(sizeof(*element));
    if (element == NULL){
        printf("error in dynamic allocation : FORCED EXIT");
        exit(1);
    }
    element->content =x;
    element->next = st;
    return element;
}

stack* clear_stack(stack* st){
    while(stack_is_empty(st) == 1){
        st = pop_stack(st);
    }
        return new_stack();
}

void print_stack(stack* st){
    StackElement* temporary_pt = st;
    if (stack_is_empty(st) == 1){
        printf("La pile est vide");
        return;
    }
    while(stack_is_empty(st) != 1){
        printf("[%d]\n", temporary_pt->content);
        temporary_pt = temporary_pt->next;
    }
}

stack* pop_stack(stack* st){
    StackElement* element;
    if(stack_is_empty(st)) return new_stack();
    element = st->next;
    free(st);
    return element;
}

int top_stack_content(stack* st){
    if (stack_is_empty(st)){
        printf("la pile est aussi vide que ton cervo");
        exit(1);
    }
    return st->content;
}

int stack_length(stack* st){
    int size;
    for (size = 0; stack_is_empty(st); size++, st = st->next); // trying a new loop style
    return size;
}

int main(void){
    return 0;
}
