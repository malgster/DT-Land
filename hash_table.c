#include "hash_table.h"
#include "prime.h"

#define HT_NUMBER_ONE 131 // random prime numbers
#define HT_NUMBER_TWO 139
#define HT_INITIAL_BASE_SIZE 50
static ht_item _DELETED_ITEM_ = {NULL, NULL}; // structure of deleted item 

static ht_item* new_ht_item(const char* keyu, const char* val){ // static cuz only accessible here
    ht_item* item = malloc(sizeof(ht_item));
    item->key = strdup(keyu); // strdup copy the entire string in "key" til '\0'
    item->value = strdup(val);
    return item;
}

static hash_table* ht_new_sized(const int base_size){
    hash_table* ht = malloc(sizeof(hash_table*)); 
    ht->base_size = base_size;

    ht->size = next_prime(ht->base_size);

    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}

hash_table* new_hash_table(void){
    return ht_new_sized(HT_INITIAL_BASE_SIZE);
}

/*

// old version

hash_table* new_hash_table(void){
    hash_table* ht = malloc(sizeof(hash_table));

    ht->size = 53; // initializing at 53 items
    ht->count = 0; // no items in it for now
    ht->items = calloc((size_t)ht->size, sizeof(ht_item)); // in memory : hashtable = size*items
    return ht;
}*/

// delete one item
static void delete_ht_item(ht_item* item){
    free(item->key);
    free(item->value);
    free(item);
}

// clear the whole table
void clear_hash_table(hash_table* ht){
    int i;
    for (i=0; i < ht->size; i++){
        ht_item* item = ht->items[i];
        if (item != NULL) delete_ht_item(item);
    }
    free(ht->items);
    free(ht);
}

static int hashcode(const char* str, const int num, const int size_of_ht){
    long hashcode = 0; int i;
    const int str_len = strlen(str);
    for (i=0; i < str_len; i++){
        hashcode += (long)pow(num, str_len - (i+1)) * str[i]; // str[i] = son char code dans la table ASCII
    }
    return (int)hashcode;
}

static int get_hashcode(const char* str, const int num_items, const int attempt){
        const int first_hash = hashcode(str, HT_NUMBER_ONE, num_items);
        const int second_hash = hashcode(str, HT_NUMBER_TWO, num_items);
        return (first_hash + (attempt * (second_hash + 1))) % num_items;
}

static void resize_hash_table(hash_table* ht, const int base_size){
    if (base_size < ht->base_size){
        return;
    }
    hash_table* new_ht = ht_new_sized(base_size);
    int i;
    for (i=0; i < ht->size; i++){
        ht_item* item = ht->items[i];
        if (item != NULL && item != &_DELETED_ITEM_){
            ht_insert(new_ht, item->key, item->value);
        }
    }
    ht->base_size = new_ht->base_size;
    ht->count = new_ht->count;

    // we give new_ht the items and size of ht before deleting it

    // size
    const int temp_size = ht->size;
    ht->size = new_ht->size;
    new_ht->size = temp_size;

    // items
    ht_item** tmp_items = ht->items;
    ht->items = new_ht->items;
    new_ht->items = tmp_items;

    clear_hash_table(new_ht);

}

static void resize_ht_up(hash_table* ht){
    const int new_size = ht->base_size * 2; // new size = two time it's initial size
    resize_hash_table(ht, new_size);
}

static void resize_ht_down(hash_table* ht){
    const int new_size = ht->base_size / 2; // new size = initial size divided by two
    resize_hash_table(ht, new_size);
}

void ht_insert(hash_table* ht, const char* key, const char* value){
    const int loading = ht->count * 100 / ht->size; // if more than 70% of the map is filled, we resize it up
    if (loading > 70) {
        resize_ht_up(ht);
    }
    ht_item* item = new_ht_item(key, value);
    int index = get_hashcode(item->key, ht->size, 0);
    ht_item* temp_item = ht->items[index];
    int i = 1;
    while (temp_item != NULL) {
        if (temp_item != &_DELETED_ITEM_){
            if (strcmp(temp_item->key, key) == 0) {
                delete_ht_item(temp_item);
                ht->items[index] = item;
                return;
            }
            index = get_hashcode(item->key, ht->size, i);
            temp_item = ht->items[index];
            i++;
        }
    ht->items[index] = item;
    ht->count++;
    }
}

char* ht_search(hash_table* ht, const char* key){
    int index = get_hashcode(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL){
        if (item != &_DELETED_ITEM_){
            if (strcmp(item->key, key) == 0){
                return item->value;
            }
            index = get_hashcode(key, ht->size, i);
            item = ht->items[index];
            i++;
        }
    }
    return NULL;
}

void ht_delete(hash_table* ht, const char* key) {
    const int loading = ht->count * 100 / ht->size;
    if (loading < 10) { // if less than 10% of the ht is filled, we resize it down
        resize_ht_down(ht);
    }
     int index = get_hashcode(key, ht->size, 0);
     ht_item* item = ht->items[index];
     int i = 1;
     while (item != NULL) {
        if (item != &_DELETED_ITEM_) { // verifying that the item we want to delete doesn't have the same address as _DELETED_ITEM
            if (strcmp(item->key, key) == 0) { // if the two strings are equals
                delete_ht_item(item);
                ht->items[index] = &_DELETED_ITEM_;
            }
        }
        index = get_hashcode(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    ht->count--;
}




void print_hash_table(hash_table* ht){
    int i;
    for (i = 0; i < ht->size; i++){
        if (ht->items[i] != NULL && ht->items[i] != &_DELETED_ITEM_){
            printf("key : %s | value : %s\n", ht->items[i]->key, ht->items[i]->value);
        }
    }
}






