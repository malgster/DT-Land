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
    return NULL; // empty list = 0 elements = NULL
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

    if (element == NULL){ 
        printf("Error in memory allocation : FORCED EXIT\n");
        exit(1); // exit(1) == abort of the function
    }
    // here we add an element in the end, it will then point to null
    element->car = car;
    element->next = NULL;

    if (is_list_empty(myList)){
        return element;
    }
    // pointer to iterate on the list without moving mylist
    list_t* temporary_list_pointer; 
    temporary_list_pointer = myList; 

    while(temporary_list_pointer->next != NULL){ // end of the list = NULL
        temporary_list_pointer = temporary_list_pointer->next;
    }
    temporary_list_pointer->next = element; // adding the new element 
    temporary_list_pointer = NULL; free(temporary_list_pointer);
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
        printf("Error in memory allocation : FORCED EXIT\n");
        exit(1); 
    }

    element->car = car;
    if (is_list_empty(myList)){ 
        element->next = NULL;
    } else {
        element->next = myList; // pointing to the list makes this element the first one of the list
    }

    return element; 


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
        temporary_list_pointer = temporary_list_pointer->next; // next element
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
    if(is_list_empty(myList)){ 
        printf("la liste est vide, rien à afficher");
        return 1;
    }

    while (myList != NULL){
        printf("[%c] ", myList->car);
        myList = myList->next; 
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
 * @brief delete the first element of the list
 * 
 * @param myList 
 * @return list_t* 
 */
list_t* delete_first_element(list_t* myList){
    list_Element* element;
    element = malloc(sizeof(*element));
    if (element == NULL){
        printf("Error in memory allocation : FORCED EXIT\n");
        exit(1); 
    }
    
    if (is_list_empty(myList)) return myList; // OR return NULL OR return new_list()

    element = myList->next; // element is now equal to the list starting from it's second element

    free(myList); 

    return element; 
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief delete the last element of the list
 * 
 * @param myList 
 * @return list_t* 
 */
list_t* delete_last_element(list_t* myList){
    if (is_list_empty(myList) == 1){ // no element to delete
        return new_list(); // return NULL
    }
    if (myList->next == NULL){ // only one element to delete
        free(myList); 
        return new_list(); // OU return myList OU return NULL
    }

    list_Element* temporary_list_pointer = myList;
    list_Element* before_pointer = myList;

    while(temporary_list_pointer->next != NULL){ 

        before_pointer = temporary_list_pointer; //  before_pointer points to the previous element
        temporary_list_pointer = temporary_list_pointer->next;
    }
    // before_pointer now points to the element before the last one
    // we break then the list by pointing before_pointer to null, becoming the last element
    before_pointer->next = NULL;
    free(temporary_list_pointer); temporary_list_pointer = NULL; // we delete the orphan element

    return myList; 
}

/////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief free the entire list in memory
 * 
 * @param myList 
 */
void clear_list(list_t* myList){
    if(is_list_empty(myList) == 1){ // 
        return; 

    } else {                                            //
       list_Element* temporary_pointer = myList->next;  // recursive version
       free(myList);                                    //
       clear_list(temporary_pointer);                   //
    }

    /*else {
        list_Element* p = myList;                       //
        while(p != NULL){                               //  
            myList = p->next;                           // iterative version
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
     if (position > list_length(myList)) { 
        printf("the given index is bigger than the list's length"); 
        exit(1); 
    }
    if (position == 0){
        return add_element_start_of_list(myList, car); // first element
    }

    if (position == list_length(myList)){
        return add_element_end_of_list(myList, car); // last element 
    }

    list_Element* temporary_list_pointer = myList; 
    list_Element* newElement = malloc(sizeof(*newElement)); // allocate a new list element
    newElement->car = car; 
    newElement->next = NULL; // points to NULL for NOW
    int index = 0;
    while (temporary_list_pointer!= NULL && index != position-1){ // we iterate till we arrive to the element in position-1
        temporary_list_pointer = temporary_list_pointer->next;
        index++;
    }
    newElement->next = temporary_list_pointer->next; // we link the element to rest of the list
    temporary_list_pointer->next = newElement; // we insert the element
    return myList; 
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
    if (position > list_length(myList)) {
        printf("the given index is bigger than the list's length"); 
        exit(1); 
    }

    if (position == 0){
        return delete_first_element(myList); // delete first occurence
    }
    list_Element* temporary_list_pointer = myList; // 
    list_Element* temporary_list_pointer_to_free = myList; // pointer that will free the element
    int index = 0;
    while (temporary_list_pointer!= NULL && index != position-1){ // iterate till arriving in position-1 
        temporary_list_pointer = temporary_list_pointer->next;
        index++;
    }

    temporary_list_pointer_to_free = temporary_list_pointer->next; // the pointer to free points  to the element in the position index
    temporary_list_pointer->next = temporary_list_pointer->next->next; // we link the list with element at index poistion+1 
    free(temporary_list_pointer_to_free); 
    return myList; 
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
        temporary_list_pointer = temporary_list_pointer->next; // we go to the next element
        if (temporary_list_pointer->car == car) return 1; // verify if the list contains the character
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
        temporary_list_pointer = temporary_list_pointer->next; // to the next element
    }
    temporary_list_pointer = list2; // pointing to the first element of the second list, linking them


    return list1; // returning the new concatenated list
}


/////////////////////////////////////////////////////////////////////////////////////////

    /**
     * @brief swap the two list elements in param 
     * 
     * @param first 
     * @param second 
     */
    static void swap_Elements(list_Element* first, list_Element* second){
        char tmp_car = first->car;
        first->car = second->car;
        second->car = tmp_car;
    }

    /**
     * @brief bubble sort for the list in parameter
     * 
     * @param myMfList 
     */
    void sort_the_list(list_t* myMfList){
        if (is_list_empty(myMfList)) {
            printf("nothing to sort\n");
            return;
        }
        int swap;
        list_Element* first_tmp;

        do {
            swap = 0;
            first_tmp = myMfList; // pointng to the first element of the list
            while (first_tmp->next != NULL){ // while the last element isn't NULL
                if ((int) first_tmp->car > (int) first_tmp->next->car){ // if you want descending other just swap ">" with "<"
                    swap_Elements(first_tmp, first_tmp->next);
                    swap = 1;
                }
                first_tmp = first_tmp->next; // go to the next element
            }
        } while (swap); // while swap == 1
        free(first_tmp);
    }   

/////////////////////////////////////////////////////////////////////////////////////////

int main(void){
    return 0;
}



