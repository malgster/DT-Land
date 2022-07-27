# Queues 

## Introduction 

A queue is a linear data structure, similar to Stacks, but unlike them a queue is open at it's ends. It follows the **FIFO (First In First Out)** methodology, which means that *the first element to enter the queue is the one that will be removed first.* 

the first element to enter the queue is called the **head** and the last element to enter is called the **head**.

## In memory

Our implementation of queues in memory are structured exactly like **Linked lists** multiple elements consisting of a *value* and *pointer* that points to the next element. 

## Operations 

A queue's main operations are *enqueue* and *dequeue*

### Enqueue

To enqueue is to add new element element to the queue, metaphorically, it is like putting beads in a necklace. 

We begin by making the tail of the list points to this new element to link them, the new element become then the *new tail*. If the list is empty this new element *also becomes the head*.

![](https://i.imgur.com/UQmDqMv.png)


### Dequeue

To Dequeue is to delete the *head* element from the list. 

We begin by saving this element in a *temporary pointer*, then make the element it's pointing to the new head, if it's NULL, then there was one element and the queue is now empty. We then <code>free</code> the temporary pointer in memory.

![](https://i.imgur.com/ndL2hFf.png)






