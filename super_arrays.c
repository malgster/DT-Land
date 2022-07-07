#include "arrays.h"


char* new_array(int taille) {
    char* tab = malloc(taille);
    return tab;
}

super_array_t* new_super_array(int taille){
    super_array_t* tab =  malloc(sizeof(super_array_t));
    tab->array = new_array(taille);
    tab->length = taille;
    return tab;
    
}

void fill_array(super_array_t* superArray,char car) {
    for (int i=0; i < superArray->length; i++) {
        *(superArray->array+i) = car;
    }
}

void print_array(super_array_t* superArray){
    printf("printing the array : ");
    for (int i=0; i < superArray->length; i++) {
        printf("[%c] ", *(superArray->array+i));
    }
    printf("\n");
}

void println_array(super_array_t* superArray){
    printf("printing the array : ");
    for (int i=0; i < superArray->length; i++) {
        printf("%c", *(superArray->array+i));
    }
    printf("\n");
}

void wider_array(super_array_t* superArray, int more){ // makes a bigger space for the string's array
    superArray->length = (superArray->length)+more; 
}


void insert_in_array(super_array_t* mySuperArray, int index, char car){ // include the argument char in the string's array at the given index
        if (index < mySuperArray->length){
            *(mySuperArray->array+index) = car;
        } else {
            *(mySuperArray->array+(mySuperArray->length)) = car;
            wider_array(mySuperArray, 1);
            *(mySuperArray->array+(mySuperArray->length)) = '\0';
        }
}

int length(super_array_t* myMfArray){
    return myMfArray->length;
}

super_array_t* read_array(void){            
    super_array_t* mySuperArray = new_super_array(1);
    char c; int i = 0;
    while((c = getchar()) != '\n'){
            insert_in_array(mySuperArray, i, c);
            i++;
    }
    return mySuperArray;
}

void free_super_array(super_array_t* mySuperArray){
    free(mySuperArray->array);
    free(mySuperArray);
}

int main (void){
    super_array_t* mySuperArray = read_array(); 
    print_array(mySuperArray); 
    insert_in_array(mySuperArray, 2, 'h'); 
    insert_in_array(mySuperArray, 6, 'u'); 
    print_array(mySuperArray); 
    free_super_array(mySuperArray);
    printf("finished");
    return 0;
}

/// print if array is empty
