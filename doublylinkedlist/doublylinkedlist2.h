#ifndef DOUBLYLINKEDLIST2_H
#define DOUBLYLINKEDLIST2_H

#include <stdlib.h>
#include <stdio.h>

struct node {
	int val;
    struct node* prev;
    struct node* next;
};

struct doublyLinkedList {
    int size;
    struct node* head;
    struct node* tail;
};

struct doublyLinkedList* inicialize() {
    struct doublyLinkedList* list = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

struct node* allocateNewNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = value;
    return newNode;
}

void insertElementAtBeginning(struct doublyLinkedList* list, int value) {
    struct node* newNode = allocateNewNode(value);
    if (list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        list->size++;
        return;
    }
    newNode->next = list->head;
    newNode->prev = NULL;
    list->head->prev = newNode;
    list->head = newNode;
    list->size++;
}

void insertElementAtEnd(struct doublyLinkedList* list, int value) {
    if (list->size == 0) {
        insertElementAtBeginning(list, value);
        return;
    }
    struct node* newNode = allocateNewNode(value);
    list->tail->next = newNode;
    newNode->next = NULL;
    newNode->prev = list->tail;
    list->tail = newNode;
    list->size++;
}

void insertElementAtPosition(struct doublyLinkedList* list, int value, int pos) {
    if (pos > list->size || pos < 0) {
        printf("invalid list position");
        exit(0);
    }
    if (pos == 0) {
        insertElementAtBeginning(list, value);
    } else if (pos == list->size) {
        insertElementAtEnd(list, value);
    } else {
        struct node* temp;
        struct node* newNode = allocateNewNode(value);
        if (list->size > pos << 1) {
            temp = list->head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
        } else {
            temp = list->tail;
            for (int i = list->size - 1; i > pos; i--) {
                temp = temp->prev;
            }
        }
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
        list->size++;
    }
}

int getElementAtPosition(struct doublyLinkedList* list, int pos) {
    if (pos >= list->size || pos < 0) {
        printf("Invalid list position.");
        exit(0);
    }
    if (pos == 0) {
        return list->head->val;
    } else if (pos == list->size - 1) {
        return list->tail->val;
    } else {
        struct node* temp;
        if (list->size > pos << 1) {
            temp = list->head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            return temp->val;
        } else {
            temp = list->tail;
            for (int i = list->size - 1; i > pos; i--) {
                temp = temp->prev;
            }
            return temp->val;
        }
    }
}

void removeElementAtPosition(struct doublyLinkedList* list, int pos) {
    if (pos >= list->size || pos < 0) {
        printf("Invalid list position.");
        exit(0);
    }
    if (pos == 0) {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
    } else if (pos == list->size - 1) {
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
    } else {
        struct node* temp;
        if (list->size > pos << 1) {
            temp = list->head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
        } else {
            temp = list->tail;
            for (int i = list->size - 1; i > pos; i--) {
                temp = temp->prev;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    list->size--;
}

void showList(struct doublyLinkedList* list) {
    printf("(");
    struct node* temp = list->head;
    for (int i = 0; i < list->size - 1; i++) {
        printf("%d)<->(", temp->val);
        temp = temp->next;
    }
    printf("%d)\n", temp->val);
}

void deleteList(struct doublyLinkedList* list) {
    struct node* temp = list->head;
    struct node* aux;
    for (int i = 0; i < list->size; i++) {
        aux = temp->next;
        free(temp);
        temp = aux;
    }
    free(list);
}

#endif //DOUBLYLINKEDLIST2_H