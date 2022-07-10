#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node {
    int content;
    struct node* next;
} node;

typedef struct queue{
    node* head;
    node* tail;
    int size;
} queue;




#endif