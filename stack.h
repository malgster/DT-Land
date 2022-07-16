#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct StackElement {
int content;
struct StackElement* next;
} StackElement, stack;


stack* new_stack(void);
int stack_is_empty(const stack* st);
stack* stack_on_stack(stack* st, int x);
stack* clear_stack(stack* st);
stack* pop_stack(stack* st);
int top_stack_content(const stack* st);
int stack_length(stack* st);
void print_stack(stack* st);

#endif