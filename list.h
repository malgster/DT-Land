#include <stdio.h>
#include <stdlib.h>
typedef struct list_t {
    char car;
    struct list_t* next;
} list_t, list_Element;

list_t* new_list(void);
int list_length(list_t* myList);
int print_list(list_t* myList);
int is_list_empty(list_t* myList);
list_t* add_element_end_of_list(list_t* myList, char car);
list_t* delete_first_element(list_t* myList);
list_t* delete_last_element(list_t* myList);
list_t* next_element(list_t* myList);
char first_element_value(list_t* myList);
void clear_list(list_t* myList);
list_t* insert_char(list_t* myList, char car, int position);
list_t* delete_element(list_t* myList, int position);
int list_are_equals(list_t* liste1, list_t* liste2);
int is_in_list(list_t* myList, char car);
list_t* concatenate_lists(list_t* list1, list_t* list2);
