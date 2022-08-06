# double linked lists

## Introduction

A double linked list is a linear sequence of nodes, it's a variation of the *Linked List* int which navigation is possible in both ways, forward and backward.

## In memmory

Our implementation of the double linked list first has *one* Structure that holds two pointers, one that points to the **start** node of the DLL and the other to the **end** of the DLL. It also holds the length of the DLL, that increments when a node is added (to avoid iterating through the whole list to get it's length).

The DL itself consists of a sequence of nodes, each node of the list contains a **data** , **a pointer to the next node sequence**  and **another pointer to the previous sequence.** 

![](https://i.imgur.com/M5mUvyA.png)

We can access the list from it's **start** or from it's **end**, using the structure that we defined. 

## Operarations 

The basic operations that can be done on the DLL are the same ones done on the *simple linked lists*.

### Insertion 

In every insertion the length value is incremented.

#### Insert at the end of the list

We begin by making the *next* pointer of the last node of the DLL point to the *new added node* and the *back* pointer of this new node point to the last, they're now linked.

 we then make the new node *the last in the DLL* by making the DLL's *end pointer* point to it.

![](https://i.imgur.com/xF8K8zg.png)

#### Insert at the beginning of the list

We begin by making the *back* pointer of the first node of the DLL points to the *new added node* and the *next *pointer of this new node point to the first, they're now linked. 

We then make it the new node *the first in the DLL* by making the DLL's *start pointer* point to it.

![](https://i.imgur.com/7o6ivSo.png)

### Deletion 

In every deletion the length value is decremented.

#### Delete at the beginning of the list

We start by saving the *start* node's in a temporary pointer, we then assign the *next* (or 2nd) node in the list to be the *start node*. 

We make the back and next of this temp node points to *NULL* and then <code>free</code> it.

![](https://i.imgur.com/tKeVvRK.png)

#### Delete at the end of the list

We start by saving the *end* node's in a temporary pointer, we then assign the *back* (or before last) node in the list to be the *end node*.

We make the back and next of this temp node points to *NULL* and then <code>free</code> it.

![](https://i.imgur.com/0rCB96F.png)







