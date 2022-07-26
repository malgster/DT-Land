# Stacks

## Introduction 

A *stack* is a linear data structure that follows the **LIFO (Last In First Out)** methodology, which means that *the last element pushed inside is the one that will be removed first*. 

![](https://i.imgur.com/ZC2uUsf.png)

## In memory 

Our implementation of stacks in memory are structured exactly like **linked lists** : multiple elements consisting of a *value* and *pointer* that points to the next element, the bottom element points to *NULL* and the top element is the one used to *access the stack*

## Operations 

A stack's main operations are *push* and *pop*

### push 

Pushing an new element in a stack is the equivalant of *stacking* it on top of it. We make the pointer of this new element points to top element of the stack, making it the new top element. 

![](https://i.imgur.com/QJmqLdp.png)

### pop 

Poping an element in a stack is the equivalant of deleting it, to pop a certain element in a stack, it is required to delete all the ones on top of it first.

![](https://i.imgur.com/n1XYIeB.jpg)



