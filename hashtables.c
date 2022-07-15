/**
 * @file hashtables.c
 * @author malgster [highly influenced by https://github.com/bloominstituteoftechnology/C-Hash-Tables]
 * @brief implementing hashtables
 *  
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Hash table key/value pair with linked list pointer.

  Note that an instance of `LinkedPair` is also a node in a linked list.
  the `next` field is a pointer pointing to the the 
  next `LinkedPair` in the list of `LinkedPair` nodes. 
 */
typedef struct LinkedPair {
  char *key;
  char *value;
  struct LinkedPair *next;
} LinkedPair;

/*
  Hash table with linked pairs.
 */
typedef struct HashTable {
  int capacity;
  LinkedPair **storage;
} HashTable;

/**
 * @brief  Create a key/value linked pair to be stored in the hash table.
 * 
 * @param key 
 * @param value 
 * @return LinkedPair* 
 */
LinkedPair *create_pair(char *key, char *value)
{
  LinkedPair *pair = malloc(sizeof(LinkedPair));
  pair->key = strdup(key);
  pair->value = strdup(value);
  pair->next = NULL;

  return pair;
}

/**
 * @brief destroys a hashtable pair
 * 
 * @param pair 
 */
void destroy_pair(LinkedPair *pair)
{
  if (pair != NULL) {
    free(pair->key);
    free(pair->value);
    free(pair);
  }
}

/**
 * @brief djb2 hash function, returns an index -> index = hashcode % hashtable's capacity
 * 
 * @param str 
 * @param max 
 * @return unsigned int 
 */
unsigned int hash(char *str, int max)
{
  unsigned long hash = 5381;
  int c;
  unsigned char * u_str = (unsigned char *)str;

  while ((c = *u_str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash % max;
}

/**
 * @brief Create a hash table 
 * 
 * @param capacity 
 * @return HashTable* 
 */
HashTable *create_hash_table(int capacity)
{
  HashTable* ht = malloc(sizeof(HashTable));
  ht->capacity = capacity;
  ht->storage = (LinkedPair**) calloc(capacity, sizeof(LinkedPair));

  return ht;
}


/*
  Inserting values to the same index with different keys should be
  added to the corresponding LinkedPair list.

  Inserting values to the same index with existing keys can overwrite
  the value in th existing LinkedPair list.
 */

  /**
   * @brief insert a new pair in the hashtable
   * 
   * @param ht 
   * @param key 
   * @param value 
   */
void hash_table_insert(HashTable *ht, char *key, char *value)
{
  unsigned int index = hash(key, ht->capacity);
  LinkedPair *current_pair = ht->storage[index];
  LinkedPair *last_pair;

  while (current_pair != NULL && strcmp(current_pair->key, key) != 0) 
  {
    last_pair = current_pair;
    current_pair = last_pair->next;
  }
  if (current_pair != NULL) 
  {
    current_pair->value = value;
  } 
  else 
  {
    LinkedPair *new_pair = create_pair(key, value);
    new_pair->next = ht->storage[index];
    ht->storage[index] = new_pair;
  }
}

/**
 * @brief search the entire list of LinkedPairs for existing keys and remove matching LinkedPairs safely.
 * 
 * @param ht 
 * @param key 
 */
void hash_table_remove(HashTable *ht, char *key) {

  unsigned int index = hash(key, ht->capacity);
  LinkedPair *current_pair = ht->storage[index];
  LinkedPair *last_pair = NULL;

  if (ht->storage[index]){
    while (current_pair != NULL && strcmp(current_pair->key, key) != 0) {
      last_pair = current_pair;
      current_pair = current_pair->next;
    }

    if (last_pair != NULL) {
      last_pair->next = current_pair->next;
    } else {
      ht->storage[index] = current_pair->next;
    }
      current_pair = NULL;
  } else {
      printf("No value found at key [%s]\n", key);
  }
}

/**
 * @brief search the entire list of LinkedPairs for existing keys. Return NULL if the key is not found.
 * 
 * @param ht 
 * @param key 
 * @return char* 
 */

char *hash_table_retrieve(HashTable *ht, const char *key) {
  unsigned int index = hash(key, ht->capacity);
  LinkedPair* current_pair = ht->storage[index];
  LinkedPair* last_pair;

  if (current_pair == NULL) {
    printf("this is a NULL value...\n");
    return NULL;
  }
  
  if (strcmp(current_pair->key, key) == 0) {
    printf("the value assigned to the key {%s} is [%s]\n", key, current_pair->value);
    return current_pair->value;
  } else {
    while (current_pair != NULL && strcmp(current_pair->key, key) != 0) {
      last_pair = current_pair;
      current_pair = last_pair->next;
    }
    if (strcmp(current_pair->key, key) == 0) {
    printf("the value assigned to the key {%s} is [%s]\n", key, current_pair->value);
      return current_pair->value;
    } else {
      return NULL;
    }
    
  }
}

/**
 * @brief holy destruction of the hash table
 * 
 * @param ht 
 */
void destroy_hash_table(HashTable *ht) {
  int i;
  for (i=0; i < ht->capacity; i++){
    if (ht->storage[i] != NULL) {
      LinkedPair* pair = ht->storage[i];
      while (pair != NULL){
        LinkedPair* nextPair = pair->next;
        destroy_pair(pair);
        pair = nextPair;
      }
    }
  }
  free(ht->storage);
  free(ht);
  printf("hash table freed in memory\n");

}

/**
 * @brief create a new hash table with double the capacity of the original and copy all elements into the new hash table.
 * 
 * @param ht 
 * @return HashTable* 
 */

 HashTable* hash_table_resize(HashTable* ht) {
  HashTable* newHT = malloc(sizeof(HashTable*));
  newHT->capacity = ht->capacity * 2;
  newHT->storage = calloc(newHT->capacity, sizeof(LinkedPair));
  for(int i = 0; i < ht->capacity; i++){
    if(ht->storage[i] != NULL){
      hash_table_insert(newHT, ht->storage[i]->key, ht->storage[i]->value);
      while(ht->storage[i]->next != NULL){
        hash_table_insert(newHT, ht->storage[i]->next->key, ht->storage[i]->next->value);
        ht->storage[i] = ht->storage[i]->next;
      }
    }
  }
  destroy_hash_table(ht);
  return newHT;
 }


int main(void)
{
return 0;
}
