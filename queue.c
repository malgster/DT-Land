#include "queue.h"


/* [head]-->[node]-->[node]-->[node]-->[tail]*/

queue* init_queue(){
    queue* q = malloc(sizeof(queue*));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

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

queue* dequeue(queue* q){
    if (q->head == NULL) {
        printf("can't dequeue an empty queue");
        return NULL;
    } 
    node* tmp_head_ptr = q->head;
    q->head = q->head->next; // remove the element
    if (q->head == NULL){
        q->tail = NULL;
    }
    free(tmp_head_ptr);
    q->size--;
    return q;
}

void print_queue(queue* q){
    if (q->head == NULL){
        printf("The queue is empty");
        return;
    }
    node* n = q->head;
    while(n != NULL){
        printf("[%d] ", n->content);
        n = n->next;
    }
    printf("\n");
    free(n);

}

node* get_rear(queue* q){
    return q->head;
}

node* get_front(queue* q){
    return q->tail;
}

int is_queue_empty(queue* q){
    return (q->size == 0 || q == NULL) ? 1 : 0;
}

void clear_queue(queue* q){
    while (is_queue_empty(q) == 0) dequeue(q);
}

int main(void){
    queue* myQueue = init_queue();
    myQueue = enqueue(myQueue, 12);
    myQueue = enqueue(myQueue, 11);
    myQueue = enqueue(myQueue, 10);
    myQueue = enqueue(myQueue, 2);
    print_queue(myQueue);
    printf("size of the queue : %d\n", myQueue->size);
    myQueue = dequeue(myQueue);
    print_queue(myQueue);
    printf("size of the queue : %d\n", myQueue->size);
    printf("front node : %d\n", get_front(myQueue)->content);
    printf("rear node : %d\n", get_rear(myQueue)->content);
    clear_queue(myQueue);
    printf("queue cleared\n");
    print_queue(myQueue);
    printf("size of the queue : %d\n", myQueue->size);
    return 0;
}

