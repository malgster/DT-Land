#ifndef SUPER_ARRAY_T
#define SUPER_ARRAY_T

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char* array;
    int length;
} super_array_t, string_t;

char* new_array(const int size);
super_array_t* new_super_array(int length);
void fill_array(super_array_t* superArray,const char car);
void print_array(const super_array_t* superArray);
void println_array(const super_array_t* superArray);
void wider_array(super_array_t* superArray, const int more);
void insert_in_array(super_array_t* mySuperArray, const int index,const char car);
int length(const super_array_t* myMfArray);
super_array_t* read_array(void);
void free_super_array(super_array_t* mySuperArray);
char charAt(const super_array_t* sa, const int index);
int char_index(const super_array_t* sa,const char car);







#endif
