#include "hash_table.h"

#define HT_NUMBER_ONE 133
#define HT_NUMBER_TWO 145

static ht_item* new_ht_item(const char* keyu, const char* val){ // static cuz only accessible here
    ht_item* item = malloc(sizeof(ht_item));
    item->key = strdup(keyu); // strdup copy the entire string in "key" til '\0'
    item->value = stardup(val);
    return item;
}

hash_table* new_hash_table(void){
    hash_table* ht = malloc(sizeof(hash_table));

    ht->size = 53; // initializing at 53 items
    ht->count = 0; // no items in it for now
    ht->items = calloc((size_t)*ht->size, sizeof(ht_item)); // in memory : hashtable = size*items
    return ht;
}

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
        hash += (long)pow(num, str_len - (i+1)) * str[i]; // str[i] = son char code dans la table ASCII
    }
    return (int)hash
}

static int get_hashcode(const char* str, const int num_items, const int attempt){
        const int first_hash = hashcode(str, HT_NUMBER_ONE, num_items);
        const int second_hash = hashcode(str, HT_NUMBER_TWO, num_items);
        return (first_hash + (attempt * (second_hash + 1))) % num_items;
}

void ht_insert(hash_table* ht, const char* key, const char* value){
    ht_item* item = new_ht_item(key, value);
    int index = get_hashcode(item->key, ht->size, 0);
    ht_item* temp_item = ht->items[index];
    int i = 1;
    while (temp_item != NULL){
        index = get_hashcode(item->key, ht->size, i);
        temp_item = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

char* ht_search(hash_table* ht, const char* key){
    int index = get_hashcode(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL){
        if (strcmp(item->key, key) == 0){
            return item->value;
        }
        index = get_hashcode(key, ht->size, i);
        item = ht->items[index];
        i++;
    }

    return NULL;
}



int main(void){
    return 0;
}



