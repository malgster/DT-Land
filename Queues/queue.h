#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int content;
    struct node* next;
} node;

typedef struct queue{
    node* head;
    node* tail;
    int size;
} queue;

queue* init_queue(void);
queue* enqueue(queue* q, int content);
queue* dequeue(queue* q);
void print_queue(queue* q);
node* get_head(queue* q);
node* get_tail(queue* q);
int is_queue_empty(queue* q);
void clear_queue(queue* q);





#endif