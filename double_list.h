#ifndef _DOUBLE_LIST_
#define _DOUBLE_LIST_

#include <stdio.h>
#include <stdlib.h>


typedef struct double_list_node{
    int content;
    struct double_list_node* back;
    struct double_list_node* next;
} double_list_node;

typedef struct double_list{
    int size;
    struct double_list_node* start;
    struct double_list_node* end;
} double_list;

double_list* new_double_list();
int empty_double_list(double_list* dli);
int double_list_size(double_list* dli);
int dl_first_node(double_list* dli);
int dl_last_node(double_list* dli);
double_list* add_node_front_dl(double_list* dli, int x);
double_list* add_node_end_dl(double_list* dli, int x);
double_list* pop_back_dl(double_list* dli);
double_list* pop_front_dl(double_list* dli);
double_list* clear_double_list(double_list* dli);


#endif