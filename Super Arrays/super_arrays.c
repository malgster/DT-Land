/**
 * @file super_arrays.c
 * @author malgster
 * @brief better array implementation in c (i guess)
 * 
 */

#include "super_arrays.h"
#include <string.h>

/**
 * @brief allocation the needed memory to create an array
 * 
 * @param size
 * @return the created array
 */
char* new_array(const int size) {
    char* myArray = malloc(sizeof(char) * size);
    if (myArray == NULL){
        printf("Error in memory allocation : FORCED EXIT\n");
        exit(1);
    }
    return myArray;
}

/**
 * @brief create a the super array structure
 * 
 * @param length
 * @return the created super array
 */
super_array_t* new_super_array(const int length){
    super_array_t* mySuperArray =  malloc(sizeof(super_array_t));
    if (mySuperArray == NULL){
        printf("Error in memory allocation : FORCED EXIT\n");
        exit(1);
    }
    mySuperArray->array = new_array(length);
    mySuperArray->length = length;
    return mySuperArray;
    
}

/**
 * @brief fill the whole array with the caractere in parameter
 * 
 * @param superArray 
 * @param car 
 */
void fill_array(super_array_t* superArray, const char car) {
    for (int i=0; i < superArray->length; i++) {
        *(superArray->array+i) = car;
    }
}
/**
 * @brief print the super array 
 * 
 * @param superArray 
 */
void print_array(const super_array_t* superArray){
    if (length(superArray) == 0){
        printf("array is empty\n");
        return;
    }
    for (int i=0; i < superArray->length; i++) {
        printf("[%c] ", *(superArray->array+i));
    }
    printf("\n");
}
/**
 * @brief prints the super array with a end of line character at the end
 * 
 * @param superArray 
 */
void println_array(const super_array_t* superArray){
    if (length(superArray) == 0){
        printf("array is empty\n");
        return;
    }
    for (int i=0; i < superArray->length; i++) {
        printf("%c", *(superArray->array+i));
    }
    printf("\n");
}
/**
 * @brief add the number of indexes in the array passed in parameter
 * 
 * @param superArray 
 * @param more 
 */
void wider_array(super_array_t* superArray, const int more){ // makes a bigger space for the string's array
    superArray->length = (superArray->length)+more; 
}

/**
 * @brief insert an element in a given index inside the array
 * 
 * @param mySuperArray 
 * @param index 
 * @param car 
 */
void insert_in_array(super_array_t* mySuperArray, const int index,const char car){ // include the argument char in the string's array at the given index
        if (index < mySuperArray->length){
            *(mySuperArray->array+index) = car;
        } else {
            *(mySuperArray->array+(mySuperArray->length)) = car;
            wider_array(mySuperArray, 1);
            *(mySuperArray->array+(mySuperArray->length)) = '\0';
        }
}

/**
 * @brief gives the length of the array in param
 * 
 * @param myMfArray 
 * @return length of the array
 */
int length(const super_array_t* myMfArray){
    return myMfArray->length;
}

/**
 * @brief puts a input chain of character in a super array 
 * 
 * @return the super array with the input in it
 */
super_array_t* read_array(void){            
    super_array_t* mySuperArray = new_super_array(1);
    char c; int i = 0;
    while((c = getchar()) != '\n'){
            insert_in_array(mySuperArray, i, c);
            i++;
    }
    return mySuperArray;
}

/**
 * @brief compare two strings 
 *          if sa_one < sa_two => return a negative integer
 *          if sa_one > sa_two => return a positive integer
 *          if sa_one = sa_two => return 0
 * 
 * @param sa_one 
 * @param sa_two 
 * @return int 
 */
int super_array_compare(super_array_t* s1, super_array_t* s2){
    char* tmp_s1 = s1->array; char* tmp_s2 = s2->array;
    while((*(tmp_s1) == *(tmp_s2))) { // while both characters are the same
        (tmp_s1)++; (tmp_s2)++; // we go to the next character
    }
    return *(tmp_s1) - *(tmp_s2); // the different between both character's position in the ASCII table
}
/**
 * @brief  return the  first index of the char in the super Array, -1 if the index is not found
 * 
 * @param sa 
 * @param car 
 * @return int 
 */
int char_index(const super_array_t* sa,const char car) { 
    int i = 0; int res = -1;
    for (i=0; i <=length(sa); i++){
        if(sa->array[i]== car) {
            res = i;
            return res;
        }
    }
    return res;
}

/**
 * @brief  return the last index of the char in the super Array, -1 if the index is not found
 * 
 * @param sa 
 * @param car 
 * @return int 
 */
int char_last_index(const super_array_t* sa, const char car){
    int i; int res = -1;
    for (i= sa->length; i >= 0; i--){
        if(sa->array[i]== car) {
            res = i;
            return res;
        }
    }
    return res;
}

/**
 * @brief returns the first occurence of char in the super array at the given index
 * 
 * @param sa 
 * @param index 
 * @return char 
 */
char charAt(const super_array_t* sa, const int index) { 
    return *(sa->array+index);
}

/**
 * @brief copies the content of super array src in dest
 * 
 * @param src 
 * @param dest 
 * @return super_array_t* 
 */
super_array_t* super_array_copy(const super_array_t* src, super_array_t* dest){
        int i = 0; char* tmp_one = src->array; char* tmp_two = dest->array; // to access the arrays not in read-only
        dest->length = src->length;
        free(dest->array); // delete the last array and the create a new one with the new size
        dest->array = new_array(dest->length);
        while (i < dest->length){
            tmp_two[i] = tmp_one[i];
            i++;
        }
    return dest;
}

/**
 * @brief free the whole super array structure
 * 
 * @param mySuperArray 
 */
void free_super_array(super_array_t* mySuperArray){
    free(mySuperArray->array);
    free(mySuperArray);
}

int main (void){
    // testing this, you shall
    return 0;
}
