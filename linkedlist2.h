#ifndef LINKEDLIST2_H
#define LINKEDLIST2_H

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct linkedList {
    int size;
    struct node* next;
};

struct linkedList* inicialize() {
    struct linkedList* list = (struct linkedList*)malloc(sizeof(struct linkedList));
    list->size = 0;
    list->next = 0;
    return list;
}

void insertAtEnd(struct linkedList* list, int value) {
    struct node** temp = list->
    for (int i = 0; i < list->size; i++) {
        temp = &((*temp)->next);
    }
    temp = (struct node*)malloc(sizeof(struct node));
    temp->val = value;
    temp->next = 0;
    list->size++;
}

int getLastValue(struct linkedList* list) {
    struct node* temp = list->next;
    for (int i = 0; i < list->size; i++) {
        temp = temp->next;
    }
    return temp->val;
}

#endif //LINKEDLIST2_H