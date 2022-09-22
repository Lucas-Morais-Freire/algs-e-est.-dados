#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct arrayStack {
    int* elements;
    int capacity;
    int size;
};

struct arrayStack* inicialize(int cap) {
    struct arrayStack* newStack = (struct arrayStack*)malloc(sizeof(struct arrayStack));
    newStack->elements = (int*)malloc(cap*sizeof(int));
    newStack->capacity = cap;
    newStack->size = 0;
    return newStack;
}

void duplicarCapacidade(struct arrayStack* stack) {
    stack->elements = (int*)realloc(stack->elements, 2*stack->capacity*sizeof(int));
    stack->capacity *= 2;
}

void putOnStack(struct arrayStack** pToStack, int value) {
    if ((*pToStack)->capacity == 0) {
        *pToStack = inicialize(10);
    }
    if ((*pToStack)->capacity == (*pToStack)->size) {
        duplicarCapacidade(*pToStack);
    }
    ((*pToStack)->elements)[(*pToStack)->size] = value;
    (*pToStack)->size++;
}

bool isEmpty(struct arrayStack* stack)  {
    if (stack->capacity || stack->size) {
        return true;
    }
    return false;
}

void removeFromStack(struct arrayStack* stack) {
    if (!isEmpty(stack)) {
        printf("This stack is empty.\n");
        return;
    }
    stack->size--;
}

int takeFromStack(struct arrayStack* stack) {
    if (!isEmpty(stack)) {
        printf("This stack is empty.\n");
        return INT_MIN;
    }
    stack->size--;
    return stack->elements[stack->size];
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct arrayStack* pilha) {
    //TODO
}

void deleteStack(struct arrayStack* stack) {
    free(stack->elements);
    free(stack);
}

void showStack(struct arrayStack* stack) {
    printf("_\n");
    for(int i = stack->size - 1; i >= 0; i--){
        printf("%d\n",stack->elements[i]);
    }
    printf("_\n\n");
}

#endif //ARRAYSTACK_H