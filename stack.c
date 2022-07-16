#include "stack.h"


/**
 * @brief create a new stack
 * 
 * @return stack*
 */
stack* new_stack(void){ // une liste vide = pas d'éléments = NULL
    return NULL;
}
/**
 * @brief return 1 if the stack is empty : 0 if not
 * 
 * @param st 
 * @return int
 */
int stack_is_empty(const stack* st){
    return (st == NULL) ? 1 : 0;
}
/**
 * @brief stack a new element on the top of the given stack
 * 
 * @param st 
 * @param x 
 * @return stack*
 */
stack* stack_on_stack(stack* st, int x){ 
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
/**
 * @brief free the entire stack
 * 
 * @param st 
 * @return stack*
 */
stack* clear_stack(stack* st){
    while(stack_is_empty(st) == 1){
        st = pop_stack(st);
    }
        return new_stack();
}
/**
 * @brief print the entire stack
 * 
 * @param st 
 */
void print_stack(stack* st){
    if (stack_is_empty(st) == 1){
        printf("La pile est vide");
        return;
    }
    while(!stack_is_empty(st)){
        printf("[%d]\n", st->content);
        st = st->next;
    }
}
/**
 * @brief pop the first element of the stack
 * 
 * @param st 
 * @return stack*
 */
stack* pop_stack(stack* st){
    StackElement* element;
    if(stack_is_empty(st)) return new_stack();
    element = st->next;
    free(st);
    return element;
}
/**
 * @brief gives the top element of the stack
 * 
 * @param st 
 * @return int
 */
int top_stack_content(const stack* st){
    if (stack_is_empty(st)){
        printf("the stack is empty\n");
        exit(1);
    }
    return st->content;
}
/**
 * @brief gives the stack's length
 * 
 * @param st 
 * @return int 
 */
int stack_length(stack* st){
    int size;
    for (size = 0; !stack_is_empty(st); size++, st = st->next); // trying a new loop style
    return size;
}

int main(void){
    stack* st = new_stack();
    st = stack_on_stack(st, 10);
    st = stack_on_stack(st, 21);
    st = stack_on_stack(st, 3);
    st = stack_on_stack(st, 42);
    st = stack_on_stack(st, 1);
    print_stack(st);
    print_stack(st);
    printf("the size is : %d\n", stack_length(st));
    free(st);
    printf("stack freed successfully\n");
    return 0;
}
