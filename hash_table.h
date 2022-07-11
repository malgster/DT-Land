#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct ht_item{
    char* key;
    char* value;
    int hc; // for tests 
} ht_item; 

typedef struct hash_table{
    int size; // how much items it can hold
    int base_size; // size at it's creation
    int count; // how many items in it
    ht_item** items; // array of pointers to the table's items
} hash_table;


hash_table* new_hash_table(void);
void clear_hash_table(hash_table* ht);
void ht_insert(hash_table* ht, const char* key, const char* value);
char* ht_search(hash_table* ht, const char* key);
void ht_delete(hash_table* h, const char* key);

#endif