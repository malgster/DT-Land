/**
 * @file list.c
 * @author malgster
 * @brief simple linked list implementation 
 */


#include "list.h"

/**
 * @brief created a new NULL list
 * 
 * @return list_t* 
 */
list_t* new_list(){
    return NULL; // une liste vide = pas d'éléments = NULL
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief adds an element at the end of the given list
 * 
 * @param myList 
 * @param car 
 * @return list_t* 
 */
list_t* add_element_end_of_list(list_t* myList, char car){ 
    list_Element* element;
    element = malloc(sizeof(*element));

    if (element == NULL){ // une ptite sécu si jamais l'allocation marche pas (optionnel)
        printf("Error in memory allocation : FORCED EXIT\n");
        exit(1); // exit(1) == arrêt et sortie anormale de la fonction
    }
    // ici on ajoute un élément à la fin, donc il pointera sur NULL vu que ça sera le DERNIER élément
    element->car = car;
    element->next = NULL;

    if (is_list_empty(myList) == 0){
        return element;
    }
    // pointeur va nous permettre de faire le parcours sur la liste sans bouger le pointeur myList :
    list_t* temporary_list_pointer; 
    temporary_list_pointer = myList; // myList et temporary_list_pointer pointe A CE MOMENT LA au même endroit

    while(temporary_list_pointer->next != NULL){ // tant qu'on est pas à la fin de la liste on se déplace
        temporary_list_pointer = temporary_list_pointer->next;
    }
    temporary_list_pointer->next = element; // le prochain élément (donc le DERNIER) c'est celui qu'on a alloué
    // on s'est déplacé dans myList avec temporary_list_pointer et on a ajouté un element à sa fin, on retourne donc celle ci :
    return myList;  
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief adds an element at the start of the given list
 * 
 * @param myList 
 * @param car 
 * @return list_t* 
 */
list_t* add_element_start_of_list(list_t* myList, char car){
    list_Element* element;
    element = malloc(sizeof(*element));

    if (element == NULL){
        printf("petite sécurité : allocation avortée \n");
        exit(1); // nous fait sortir de la fonction et nous protège des seg fault ;))
    }

    element->car = car;
    if (is_list_empty(myList) == 0){ // si la liste est vide alors l'élément ajouté en PREMIER pointe vers NULL
        element->next = NULL;
    } else {
        element->next = myList; // si la liste est remplie alors on place cet element au début en le faisant pointer vers le début de la précédente liste
    }

    return element; // on return "element"  car le faisant pointer vers le début de la dernière liste, il est devenu la nouvelle liste


}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief returns 1 if the list is empty : 0 if not
 * 
 * @param myList 
 * @return int 
 */
int is_list_empty(list_t* myList){ 
    return (myList == NULL) ? 1 : 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief returns the list's length
 * 
 * @param myList 
 * @return int 
 */
int list_length(list_t* myList){
    int size = 0;
    if (is_list_empty(myList) == 1) return size;
    list_t* temporary_list_pointer; temporary_list_pointer = myList;
    while(temporary_list_pointer != NULL){
        size++;
        temporary_list_pointer = temporary_list_pointer->next; // on passe à l'élément suivant par le pointeur
    }
    return size;
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief prints the list
 * 
 * @param myList 
 * @return int 
 */
int print_list(list_t* myList){
    if(is_list_empty(myList) == 1){ // si myList == NULL
        printf("la liste est vide, rien à afficher");
        return 1;
    }

    while (myList != NULL){
        printf("[%c] ", myList->car);
        myList = myList->next; // on passe à l'élément suivant
    }
    printf("\n");
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief return the value of the list's first element
 * 
 * @param myList 
 * @return char 
 */
char first_element_value(list_t* myList){
    return myList->car; 
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief return a pointer to the next element after the one in param
 * 
 * @param myList 
 * @return list_t* 
 */
list_t* next_element(list_t* myList){
    return myList->next; 
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief delete the first element of the list
 * 
 * @param myList 
 * @return list_t* 
 */
list_t* delete_first_element(list_t* myList){
    list_Element* element;
    element = malloc(sizeof(*element));
    if (element == NULL){
        printf("petite sécurité : allocation avortée \n");
        exit(1); // nous fait sortir de la fonction et nous protège des seg fault ;))
    }
    
    if (is_list_empty(myList) == 0) return myList; // OU return NULL OU return new_list()

    element = myList->next; // element est ainsi égale à myList à partir de son DEUXIEME element, le premier est donc dégagé de la liste

    free(myList); // on a plus besoin de cette ancienne liste
    myList = NULL; // même sécurité tmtc

    return element; // la liste sans le premier element, perfect.
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief delete the last element of the list
 * 
 * @param myList 
 * @return list_t* 
 */
list_t* delete_last_element(list_t* myList){
    if (is_list_empty(myList) == 1){ // il y'a pas d'éléments à supprimer
        return new_list(); // on aurait pu mettre "return NULL", ça revient au même
    }
    if (myList->next == NULL){ // si la liste contient UN SEUL element
        free(myList); // on a supprimé le seul élément de la liste, on la libère donc vu qu'elle est vide
        myList = NULL; // petite sécurité pour s'assurer que la liste n'est plus (bonne pratique pour éviter que le compilateur vienne mettre une valeur au hasard dedans après)
        return new_list(); // OU return myList OU return NULL
    }

    list_Element* temporary_list_pointer = myList;
    list_Element* before_pointer = myList;

    while(temporary_list_pointer->next != NULL){ // on parcoure la liste jusqu'au dernier élément

        before_pointer = temporary_list_pointer; // on affecte à before_pointer la valeur qu'on avait juste avant de passer la suivante
        temporary_list_pointer = temporary_list_pointer->next;
    }
    // before_pointer est à présent L'AVANT DERNIER élément de la liste
    // en le faisant pointer vers NULL, on casse la liste à cette éléments (vu qu'il pointe plus vers le dernier élément), et before devient LE DERNIER ELEMENT de la liste
    before_pointer->next = NULL;
    free(temporary_list_pointer); temporary_list_pointer = NULL; // on supprime le dernier élémenent orphelin (même façon que tt à l'heure)

    return myList; // on return la liste débarrassée de son dernier élément
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief free the entire list in memory
 * 
 * @param myList 
 */
void clear_list(list_t* myList){
    if(is_list_empty(myList) == 1){ // si la liste est vide de base on sort de la fonction
        return; // on sort de la fonction, vu qu'il n'y a rien d'alloué de toute façon

    } else {                                            //
       list_Element* temporary_pointer = myList->next;  // version récursive
       free(myList);                                    //
       clear_list(temporary_pointer);                   //
    }

    /*else {
        list_Element* p = myList;                       //
        while(p != NULL){                               //  
            myList = p->next;                           // version itérative
            free(p);                                    //
            p = myList;                                 //   
        }*/
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief insert an element in a given index of the list
 * 
 * @param myList 
 * @param car 
 * @param position 
 * @return list_t* 
 */
list_t* insert_char(list_t* myList, char car, int position){ 
     if (position > list_length(myList)) { // on se protège d'une sorte de "indexOutOfBoundException" ;)
        printf("the given index is bigger than the list's length"); // la position donnée est supérieur à la longueur de la liste
        exit(1); // on sort de la fonction
    }
    if (position == 0){
        return add_element_start_of_list(myList, car); // l'élément inséré en position 0 est le premier élément
    }

    if (position == list_length(myList)){
        return add_element_end_of_list(myList, car); // l'élément inséré en position = longueur de la liste : est le dernier élément
    }

    list_Element* temporary_list_pointer = myList; // le pointeur qui parcourera la liste 
    list_Element* newElement = malloc(sizeof(*newElement)); // on alloue un nouvel élément (ou instancie si vous êtes des obssédés du java..)
    newElement->car = car; 
    newElement->next = NULL; // POUR L'INSTANT il pointe sur null
    int index = 0;
    while (temporary_list_pointer!= NULL && index != position-1){ // on parcours jusqu'à s'arrêter à l'élement en indice position-1 
        temporary_list_pointer = temporary_list_pointer->next;
        index++;
    }
    newElement->next = temporary_list_pointer->next; // on relie l'élément à la liste
    temporary_list_pointer->next = newElement; // on insère l'élément 
    return myList; // on return la nouvelle liste
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief delete an the element of the list at the given index
 * 
 * @param myList 
 * @param position 
 * @return list_t* 
 */
list_t* delete_element(list_t* myList, int position){
    if (position > list_length(myList)) { // on se protège d'une sorte de "indexOutOfBoundException" ;)
        printf("the given index is bigger than the list's length"); // la position donnée est supérieur à la longueur de la liste
        exit(1); // on sort de la fonction
    }

    if (position == 0){
        return delete_first_element(myList); // supprime la première occurence et donc celle à la position 0
    }
    list_Element* temporary_list_pointer = myList; // le pointeur qui parcourera la liste
    list_Element* temporary_list_pointer_to_free = myList; // le pointeur qui servira à supprimer l'element
    int index = 0;
    while (temporary_list_pointer!= NULL && index != position-1){ // on parcours jusqu'à s'arrêter à l'élement en indice position-1 
        temporary_list_pointer = temporary_list_pointer->next;
        index++;
    }

    temporary_list_pointer_to_free = temporary_list_pointer->next; // le pointeur à libérer devient le pointeur à l'indice posistion
    temporary_list_pointer->next = temporary_list_pointer->next->next; // on renoue la liste avec l'élément à l'indice poistion+1 
    free(temporary_list_pointer_to_free); // on libère ce pointeur
    return myList; // on return notre nouvelle liste avec l'élément supprimé
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief returns 1 if the list have the same lenght : 0 if not
 * 
 * @param liste1 
 * @param liste2 
 * @return int 
 */
int list_are_equals(list_t* liste1, list_t* liste2){
    return (list_length(liste1) == list_length(liste2)) ? 1 : 0; 
    /*c'est l'équavalant de 
    if (list_length(liste1) == list_length(liste2)) return 1;
    return 0;*/
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief returns 1 if the given element is in the list : 0 if not
 * 
 * @param myList 
 * @param car 
 * @return int 
 */
int is_in_list(list_t* myList, char car){
    list_Element* temporary_list_pointer = myList;
    while (temporary_list_pointer != NULL){
        temporary_list_pointer = temporary_list_pointer->next; // on passe à l'élément suivant
        if (temporary_list_pointer->car == car) return 1; //on vérifie si la liste contient le caratère
    }
    printf("Le caractère n'est pas dans la liste");
    return 0;
}

/**
 * @brief concatenates the lists in param
 * 
 * @param list1 
 * @param list2 
 * @return list_t* 
 */
list_t* concatenate_lists(list_t* list1, list_t* list2){
    list_Element* temporary_list_pointer = list1;
    while (temporary_list_pointer != NULL){
        temporary_list_pointer = temporary_list_pointer->next; // on passe à l'élément suivant
    }
    temporary_list_pointer = list2; // on pointe vers le premier élément de la deuxième, les reliant ainsi

    return list1; // on retourne la nouvelle liste concaténé
}


/////////////////////////////////////////////////////////////////////////////////////////

int main(void){
    return 0;
}



