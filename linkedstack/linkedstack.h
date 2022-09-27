#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node{
    int val;
    struct node *next;
};

struct linkedStack {
    struct node* top;
    int size;
};

struct linkedStack* inicialize() {
    struct linkedStack* stack = (struct linkedStack*)malloc(sizeof(struct linkedStack));
    stack->size = 0;
    stack->top = 0;
    return stack;
}

struct node* allocateNewNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

//retornar true se a pilha for nula ou vazia
bool isEmpty(struct linkedStack* stack) {
    if (stack->size == 0 || stack == NULL) {
        return true;
    }
    return false;
}

//se a pilha estiver nula, instancie a pilha
//por causa da possibilidade de instanciacao usamos struct linkedStack**
void putOnStack(struct linkedStack** pToStack, int value){
    if ((*pToStack) == NULL) {
        *pToStack = inicialize();
    }
    struct node* newNode = allocateNewNode(value);
    struct node* aux = (*pToStack)->top;
    (*pToStack)->top = newNode;
    newNode->next = aux;
    (*pToStack)->size++;
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void removeFromStack(struct linkedStack* stack) {
    if (stack->size == 0) {
        printf("The stack is empty.\n");
        return;
    }

    struct node* aux = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    free(aux);
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int takeFromStack(struct linkedStack* stack) {
    if (stack->size == 0 || stack == NULL) {
        printf("This stack is empty.\n");
        return INT_MIN;
    }
    struct node* aux = stack->top;
    stack->top = stack->top->next;
    int value = aux->val;
    stack->size--;
    free(aux);
    return value;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int inspectTopOfStack(struct linkedStack* stack){
    if (stack->size == 0 || stack == NULL) {
        printf("This stack is empty.\n");
        return INT_MIN;
    }

    return stack->top->val;
}

void showStack(struct linkedStack* stack) {
    //usamos o aux para percorrer a lista
    if (!isEmpty(stack)) {
        struct node* aux = stack->top;
        //navega partindo do topo até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->val);
            aux = aux->next;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A pilha está vazia!");
    }
}

void deleteStack(struct linkedStack* stack) {
    struct node* temp = stack->top;
    struct node* aux;
    for (int i = 0; i < stack->size; i++) {
        aux = temp->next;
        free(temp);
        temp = aux;
    }
    free(stack);
}

#endif // LINKEDSTACK_H