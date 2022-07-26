#include "stack.h"


/**
 * @brief create a new stack
 * 
 * @return stack*
 */
stack* new_stack(void){ // an empty stack = no elements = NULL;
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
    element->next = st; // the following element is the stack st
    return element; // returns the stacked stack
}
/**
 * @brief free the entire stack
 * 
 * @param st 
 * @return stack*
 */
stack* clear_stack(stack* st){
    while(!stack_is_empty(st)){  
        st = pop_stack(st); // pop every element till the stack is empty
    }
        return new_stack(); // NULL
}
/**
 * @brief print the entire stack
 * 
 * @param st 
 */
void print_stack(stack* st){
    if (stack_is_empty(st)){
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
    element = st->next; // the stack is now equal to itself without it's first element
    free(st); // free the first element
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
        exit(0);
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
    for (size = 0; !stack_is_empty(st); size++, st = st->next); // iterative through the whole stack
    return size;
}

int main(void){
    return 0;
}
