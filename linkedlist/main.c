#include <stdio.h>
#include "linkedlist2.h"

int main() {
    struct linkedList* list = inicialize();
    insertAtEnd(list, 8);
    insertAtEnd(list, 3);
    insertAtEnd(list, 2);
    insertAtEnd(list, 1);
    insertAtEnd(list, 0);
    insertAtEnd(list, -5);
    insertElementAtPosition(list, -1, list->size);
    showList(list);

    free(list);
    return 0;
}