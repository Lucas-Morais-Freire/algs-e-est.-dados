#include <stdio.h>
#include <stdlib.h>

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

void insertAtEnd(struct linkedList* list, int value) {
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

void removeLastValue(struct linkedList* list) {
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

int getValueAtPosition(struct linkedList* list, int pos) {
    if (pos >= list->size) {
        printf("Invalid list position.\n");
        exit(0);
    }
    struct node* temp = list->head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    return temp->val;
}

int main() {
    struct linkedList* list = inicialize();
    insertAtEnd(list, 8);
    insertAtEnd(list, 3);
    insertAtEnd(list, 2);
    removeLastValue(list);
    printf("%p\n", list->head->val);

    free(list);
    return 0;
}