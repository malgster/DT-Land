#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"



char* new_array(int taille) {
    char* tab = malloc(taille);
    return tab;
}

super_array_t* new_super_array(int taille){
    super_array_t* tab =  malloc(sizeof(super_array_t));
    string->array = new_array(taille);
    tab->length = taille;
    return tab;
    
}

void initialise_tableau (char* tableau, int taille, char car) {
    for (int i=0; i < taille; i++) {
        *(tableau+i) = car;
    }
}

void affiche_tableau (char* tableau, int taille){
    printf("printing the array : ");
    for (int i=0; i < taille; i++) {
        printf("[%c] ", *(tableau+i));
    }
    printf("\n");
}

void liberation_du_tableau (char* tableau){
    free(tableau);
}

void place_dans_tableau (char* tableau, int taille, int indice, char car){
     if (indice < taille){
         *(tableau+indice) = car;
     } else {
         printf("error for [%c] : the given index is superior to the array's length\n", car);
     }
}

char lecture_du_tableau (char* tableau, int taille, int indice){
    if (indice < taille){
        return *(tableau+indice);
    }
    printf("error : the given index is superior to the array's length\n");
    return '\0';
}

void place_dans_super_tableau (super_array_t* myMfArray, int index, char car){
        if (index < myMfArray->length){
            *(myMfArray->array+index) = car;
        } else {
         printf("error for [%c] : the given index is superior to the array's length\n", car);
        }
}

int length(super_array_t* myMfArray){
    return myMfArray->length;
}

char lecture_du_super_tableau (super_array_t* myMfArray, int index){
    if (index < myMfArray->length){
        return *(myMfArray->array+index);
    }
    printf("error : the given index is superior to the array's length\n");
    return '\0';
}



int main (void){
    super_array_t* mySuperArray = malloc(sizeof(super_array_t)); // accessing through pointers
    mySuperArray->length = 4;
    mySuperArray->array = nouveau_tableau(mySuperArray->length);
    initialise_tableau(mySuperArray->array, mySuperArray->length, 'm');
    affiche_tableau(mySuperArray->array, mySuperArray->length); // prints [m] [m] [m] [m]
    place_dans_super_tableau(mySuperArray, 2, 'h'); // works
    place_dans_super_tableau(mySuperArray, 6, 'u'); // doesn't work
    affiche_tableau(mySuperArray->array, mySuperArray->length); // prints [m] [m] [h] [m]
    free(mySuperArray->array);
    printf("now that the memory of the 'array only' is free : \n");
    affiche_tableau(mySuperArray->array, mySuperArray->length); // prints [m] [m] [m] [m] the array disapeared but the length still exist
    free(mySuperArray);
    printf("now that the memory of the whole struct is free : \n"); 
    affiche_tableau(mySuperArray->array, mySuperArray->length); // prints nothing cuz both the array and the length disapeared with the structure
    return 0;
}

