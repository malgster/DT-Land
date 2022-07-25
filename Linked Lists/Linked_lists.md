# Linked Lists 

## Introduction :

A linked list is a linear sequence of nodes. The order and indexes of theses nodes isn't given by their placement in memory like array. Every node is linked to the next one, and we can iterate on it, add and insert elements to it, and delete from it. 

## In memory :

In it's most simple form, each node of the list contains a **data** and **a pointer to the next node sequence**  

* The first node's pointer is called the **head** it's the one used to access the whole list

* the last node's pointer is a **NULL pointer** and indicates that the end of the list (if the *head* is itself a NULL pointer that means that the list is empty)
 
![](https://i.imgur.com/4hPy3Sf.jpg)

Because pointers are the things used to link the nodes, there is no requirement for the data to be stored contiguously in memory.

## Operations :

A quick explanation of the main operation that can be done on the lists, further explanation of the exact things done in order to achieve them are in the *code comments that i left*
 

### Insertion

Inserting an element in a linked list is an easy operation, due to the fact that unlike the array, a list doesn't have a reserved memory space that should be reallocated, we can insert as much element to it as the memory capacity allows.

#### Insert in the beginning of the list 

Inserting an element at the beginning consists of making it's pointer point to the **head** of the list, becoming the new head used *to access the list*

![](https://i.imgur.com/K7GydTL.png)

#### Insert in the end of the list 

Inserting an element at the end consists of iterating through the list until the last element, we then make the pointer of this element points to the new element , then we make it's pointer point to **NULL** *to mark the end of the list*

![](https://i.imgur.com/jXbhHKs.jpg)

#### Insert at a given index in the list 

Inserting an element at a given index consist of iterating through the list with until we arrive to the element at *index-1* we make that pointer point to the new element, and make it's pointer point to the next element at *index+1*, 

![](https://i.imgur.com/PBZcETF.jpg)


### Deletion

Deleting an element in a list means deallocating the memory previously allocated for it using the <code>free</code> function while keeping the list perfectly *linked* (:]).

#### Delete at the beginning of the list

Deleting an element at the beginning consists of freeing the *head* and returning the next element to it as the new head used to access the list with it.

![](https://i.imgur.com/S4vkzqy.jpg)

#### Delete at the end of the list

Deleting an element at the end consists of iterating through the list util we find the *last element* and the *element before the last* (that we save in two temporary pointers) we then make the *before-last's* pointer point to NULL, then *free the last element*

![](https://i.imgur.com/ypgqSON.jpg)


#### Delete at a given index in the list

Inserting an element at a given index consist of iterating through the list with until we arrive to the element at *index-1* we make that pointer point to the element at *index+1*, then *free the element at index*. 

![](https://i.imgur.com/kR3kXAG.jpg)

#### Delete the whole list : 

As said earlier, the first element *(head)* is the one used to acess the whole list, *but it isn't the whole list itself* so in order to delete it completely, we need to iterate through it and <code>free</code> every element until we arrive to the **NULL** pointer.

![](https://i.imgur.com/4Bi9wW4.png)


