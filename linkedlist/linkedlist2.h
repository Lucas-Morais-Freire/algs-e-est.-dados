#ifndef LINKEDLIST2_H
#define LINKEDLIST2_H

#include <stdlib.h>
#include <stdio.h>

struct node {
    int val;
    struct node* next;
};

struct linkedList {
    int size;
    struct node* head;
};

struct linkedList* inicialize() {
    struct linkedList* list = (struct linkedList*)malloc(sizeof(struct linkedList));
    list->size = 0;
    list->head = 0;
    return list;
}

void insertElementAtEnd(struct linkedList* list, int value) {
    if (list->size == 0) {
        list->head = (struct node*)malloc(sizeof(struct node));
        list->head->next = 0;
        list->head->val = value;
    } else {
        struct node* temp = list->head;
        for (int i = 1; i < list->size; i++) {
            temp = temp->next;
        }
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp->next->next = 0;
        temp->next->val = value;
    }
    list->size++;
}

void removeLastElement(struct linkedList* list) {
    if (list->size == 0) {
        printf("this list is already empty.\n");
        exit(0);
    }
    struct node* temp = list->head;
    for (int i = 1; i < list->size; i++) {
        temp = temp->next;
    }
    free(temp);
    list->size--;
}

int getElementAtPosition(struct linkedList* list, int pos) {
    if (pos >= list->size || pos < 0) {
        printf("Invalid list position.\n");
        exit(0);
    }
    struct node* temp = list->head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    return temp->val;
}

void insertElementAtPosition(struct linkedList* list, int value, int pos) {
    if (pos > list->size || pos < 0) {
        printf("Invalid list position.\n");
        return;
    }
    struct node* target = (struct node*)malloc(sizeof(struct node));
    target->val = value;
    struct node* temp = list->head;
    if (pos == 0) {
        target->next = list->head;
        list->head = target;
        list->size++;
        return;
    }
    for (int i = 0; i < pos; i++) {
        if (i == pos - 1) {
            target->next = temp->next;
            temp->next = target;
            list->size++;
            return;
        }
        temp = temp->next;
    }
}

void updateElementAtPosition(struct linkedList* list, int value, int pos) {
    if (pos >= list->size || pos < 0) {
        printf("Invalid list position.\n");
        return;
    }
    struct node* temp = list->head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    temp->val = value;
}

void removeElementAtPosition(struct linkedList* list, int pos) {
    if (pos >= list->size || pos < 0) {
        printf("Invalid list position.\n");
        return;
    }
    struct node* temp = list->head;
    if (pos == 0) {
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    struct node* aux = temp->next;
    temp->next = temp->next->next;
    free(aux);
    list->size--;
}

void showList(struct linkedList* list) {
    printf("(");
    struct node* temp = list->head;
    for (int i = 0; i < list->size - 1; i++) {
        printf("%d)->(", temp->val);
        temp =temp->next;
    }
    printf("%d)\n", temp->val);
}

#endif //LINKEDLIST2_H