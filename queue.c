/**
 * @file queue.c
 * @author malgster
 * @brief implementation of queues
 * 
 * 
 */


#include "queue.h"



/**
 * @brief creates a new queue
 * 
 * @return queue* 
 */
queue* init_queue(void){
    queue* q = malloc(sizeof(queue*));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}
/**
 * @brief add a new element in a queue
 * 
 * @param q 
 * @param content 
 * @return queue* 
 */
queue* enqueue(queue* q, int content){
    node* newnode = malloc(sizeof(node));
    if (newnode == NULL){
        printf("error in memory allocation : FORCED EXIT");
        exit(1);
    }
    newnode->content = content;
    newnode->next = NULL;
    if (q->tail != NULL){
        q->tail->next = newnode;  // if there's a tail we connect it to the new node we created
    }
    q->tail = newnode; // the node is now the tail

    if (q->head == NULL){ // if the list is empty and newnode is the first element we point head to new node
        q->head = newnode;
    }
    q->size++;
    return q;
}
/**
 * @brief remove the last element of the queue
 * 
 * @param q 
 * @return queue* 
 */
queue* dequeue(queue* q){
    if (q->head == NULL) {
        printf("can't dequeue an empty queue");
        return NULL;
    } 
    node* tmp_head_ptr = q->head; // save the element to delete in an a tmp pointer
    q->head = q->head->next; // head becomes the next element 
    if (q->head == NULL){
        q->tail = NULL; // queue is empty
    }
    free(tmp_head_ptr); // delete the element
    q->size--;
    return q;
}
/**
 * @brief print the given queue
 * 
 * @param q 
 */
void print_queue(queue* q){
    if (q->head == NULL){
        printf("The queue is empty");
        return;
    }
    node* n = q->head;
    while(n != NULL){
        printf("[%d] ", n->content);
        n = n->next; // iterate through the queue
    }
    printf("\n");
    free(n);

}
/**
 * @brief Get the head of the queue
 * 
 * @param q 
 * @return node* 
 */
node* get_head(queue* q){
    return q->head;
}
/**
 * @brief Get the tail of the queue
 * 
 * @param q 
 * @return node* 
 */
node* get_tail(queue* q){
    return q->tail;
}
/**
 * @brief returns 1 if the queue is empty : 0 if not
 * 
 * @param q 
 * @return int 
 */
int is_queue_empty(queue* q){
    return (q->size == 0 || q == NULL) ? 1 : 0;
}
/**
 * @brief free the entire queue
 * 
 * @param q 
 */
void clear_queue(queue* q){
    while (!is_queue_empty(q)) dequeue(q);
    printf("the queue is now clear\n");
}

int main(void){
    queue* monQ = init_queue();
    monQ = enqueue(monQ, 1);
    monQ = enqueue(monQ, 2);
    monQ = enqueue(monQ, 3);
    print_queue(monQ);
    clear_queue(monQ);
    return 0;
}

