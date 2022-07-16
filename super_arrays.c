/**
 * @file super_arrays.c
 * @author malgster
 * @brief better array implementation in c 
 * 
 */

#include "super_arrays.h"

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
 * @brief free the whole super array structure
 * 
 * @param mySuperArray 
 */
void free_super_array(super_array_t* mySuperArray){
    free(mySuperArray->array);
    free(mySuperArray);
}

int main (void){
    return 0;
}

/// print if array is empty
