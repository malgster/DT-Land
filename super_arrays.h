#ifndef SUPER_ARRAY_T
#define SUPER_ARRAY_T

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char* array;
    int length;
} super_array_t, string_t;

char* new_array(int size);
super_array_t* new_super_array(int length);
void fill_array(super_array_t* superArray,char car);
void print_array(super_array_t* superArray);
void println_array(super_array_t* superArray);
void wider_array(super_array_t* superArray, int more);
void insert_in_array(super_array_t* mySuperArray, int index, char car);
int length(super_array_t* myMfArray);
super_array_t* read_array(void);
void free_super_array(super_array_t* mySuperArray);







#endif
