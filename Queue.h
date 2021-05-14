#ifndef _QUEUE_H
#define _QUEUE_H
#include "Includes.h"
#include "Graph.h"

struct Queue {
    int front;
    int rear;
    int size;
    int capacity;
    struct Node** array;
};

struct Queue* createQueue(int capacity);

int isEmpty(struct Queue* queue);
int isFull(struct Queue* queue);

void enqueue(struct Queue* queue, struct Node* node);
struct Node* dequeue(struct Queue* queue);

struct Node* front(struct Queue* queue);
struct Node* rear(struct Queue* queue);

void freeQueue(struct Queue* queue);

#endif