#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct arrayStack {
    int* elements;
    int capacity;    //tam do array
    int size;     //qtdade de elementos no array
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

//se a pilha estiver nula, instancie a pilha com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arrayStack**
//se a pilha encher, duplique a capacidade do array
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

//retornar true se a pilha for nula ou vazia
bool vazia(struct arrayStack* pilha)  {
    //TODO
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct arrayStack* pilha) {
    //TODO
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct arrayStack* pilha) {
    //TODO
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