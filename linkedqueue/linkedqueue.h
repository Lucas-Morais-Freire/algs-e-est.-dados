#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node* next;
};

struct linkedQueue {
    struct node* front;
    struct node* back;
    int size;
};

struct linkedQueue* inicialize() {
    struct linkedQueue* queue = (struct linkedQueue*)malloc(sizeof(struct linkedQueue));
    queue->size = 0;
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

struct node* allocateNewNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(struct linkedQueue* queue) {
    if (queue->size == 0) {
        return true;
    }
    return false;
}

//se a fila estiver nula, instancie a fila
//por causa da possibilidade de instanciacao usamos struct linkedQueue**
void addToQueue(struct linkedQueue** pToQueue, int val) {
    if (*pToQueue == NULL) {
        *pToQueue = inicialize();
    }
    struct node* newNode = allocateNewNode(val);
    if ((*pToQueue)->size == 0) {
        (*pToQueue)->back = newNode;
        (*pToQueue)->front = newNode;
        (*pToQueue)->size++;
        return;
    }
    (*pToQueue)->back->next = newNode;
    (*pToQueue)->back = newNode;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
//lembrem de desalocar o n� removido (free)
int takeFromQueue(struct linkedQueue* queue) {
    if (queue == NULL || isEmpty(queue)) {
        printf("This queue is empty.\n");
        return INT_MIN;
    }
    int val = queue->front->val;
    if (queue->size == 1) {
        free(queue->back);
        queue->size = 0;
        queue->front = NULL;
        queue->back = NULL;
        return val;
    }
    struct node* aux = queue->front;
    queue->front = queue->front->next;
    free(aux);
    queue->size--;
    return val;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int inspectFrontOfQueue(struct linkedQueue* queue) {
    if (queue == NULL || isEmpty(queue)) {
        printf("This queue is empty.\n");
        return INT_MIN;
    }
    return queue->front->val;
}

void deleteQueue(struct linkedQueue* queue) {
    struct node* temp = queue->front;
    struct node* aux;
    for (int i = 0; i < queue->size; i++) {
        aux = temp->next;
        free(temp);
        temp = aux;
    }
    free(queue);
}

#endif //LINKEDQUEUE_H