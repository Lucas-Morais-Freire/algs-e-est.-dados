#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arrayQueue {
    int front;
    int back;
    int* elements;
    int capacity;    //tam do array
    int size;     //qtdade de elementos no array    
};

struct arrayQueue* inicialize(int cap) {
    if (cap < 1) {
        printf("Invalid queue size.\n");
        exit(0);
    }
    struct arrayQueue* newQueue = (struct arrayQueue*)malloc(sizeof(struct arrayQueue));
    newQueue->elements = (int*)malloc(cap*sizeof(int));
    newQueue->capacity = cap;
    newQueue->size = 0;
    newQueue->front = -1;
    newQueue->back = -1;
    return newQueue;
}

void doubleCapacity(struct arrayQueue* queue) {
    int* newArray = (int*)malloc(2*queue->capacity*sizeof(int));
    int i = queue->front; int j = 0;
    while (j < queue->size) {
        newArray[j] = queue->elements[i];
        i = (i + 1) % queue->capacity;
        j++;
    }
    queue->capacity <<= 1;
    queue->front = 0;
    queue->back = queue->size - 1;
    int* aux = queue->elements;
    queue->elements = newArray;
    free(aux);
}

//se a fila estiver nula, instancie a fila com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arrayQueue**
//se a fila encher, simplesmente não enfileire
void addToQueue(struct arrayQueue** pToQueue, int val) {
    if ((*pToQueue) == NULL) {
        (*pToQueue) = inicialize(10);
    }
    if ((*pToQueue)->size == 0) {
        (*pToQueue)->front = 0;
        (*pToQueue)->back = 0;
        (*pToQueue)->elements[0] = val;
        (*pToQueue)->size = 1;
        return;
    } else if ((*pToQueue)->size == (*pToQueue)->capacity) {
        doubleCapacity(*pToQueue);
    }
    (*pToQueue)->back = ((*pToQueue)->back + 1) % (*pToQueue)->capacity;
    (*pToQueue)->elements[(*pToQueue)->back] = val;
    (*pToQueue)->size++;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int takeFromQueue(struct arrayQueue* queue) {
    if (queue == NULL || queue->size == 0) {
        printf("This queue is empty.\n");
        return INT_MIN;
    }
    int aux = queue->elements[queue->front];
    if (queue->size == 1) {
        queue->front = -1;
        queue->back = -1;
        queue->size = 0;
        return aux;
    }
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return aux;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int inspectFrontOfQueue(struct arrayQueue* queue) {
    if (queue == NULL || queue->size == 0) {
        printf("This queue is empty.\n");
        return INT_MIN;
    }
    return queue->elements[queue->front];
}

void showQueue(struct arrayQueue* queue) {
    if (queue->size == 0) {
        printf("This queue is empty.\n");
        return;
    }
    printf("->");
    int i = queue->back; int j = 0;
    while (j < queue->size - 1) {
        printf("[%d] ", queue->elements[i]);
        i = (i + 2*queue->capacity - 1) % queue->capacity;
        j++;
    }
    printf("[%d]->\n", queue->elements[i]);
}

void deleteQueue(struct arrayQueue* queue) {
    free(queue->elements);
    free(queue);
}

#endif //ARRAYQUEUE_H