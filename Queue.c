#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "Graph.h"

/*
* My pride and joy: a circular queue implementation for my weird nodes in C.
* This was the source of a great deal of headaches but it seems to now
* work just fine.
*/

struct Queue* createQueue(int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

    queue->capacity = capacity;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;

    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue* queue, struct Node* node){
    if (!isFull(queue)){
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = node;
        queue->size++;
    }
}

struct Node* dequeue(struct Queue* queue){
    struct Node* node;
    if (!isEmpty(queue)){
        node = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size = queue->size - 1;
    } 
    else {
        node = NULL;
    }
    return node;
}

struct Node* front(struct Queue* queue){
    return !isEmpty(queue) ? queue->array[queue->front] : NULL;
}

struct Node* rear(struct Queue* queue){
    return !isEmpty(queue) ? queue->array[queue->rear] : NULL;
}

void freeQueue(struct Queue* queue) {
    free(queue->array);
    free(queue);
}
