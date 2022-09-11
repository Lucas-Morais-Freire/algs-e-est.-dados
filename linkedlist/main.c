#include <stdio.h>
#include "linkedlist2.h"

int main() {
    struct linkedList* list = inicialize();
    insertElementAtEnd(list, 8);
    insertElementAtEnd(list, 3);
    insertElementAtEnd(list, 2);
    insertElementAtEnd(list, 1);
    insertElementAtEnd(list, 0);
    insertElementAtEnd(list, -5);
    showList(list);
    removeElementAtPosition(list, 2);
    showList(list);

    free(list);
    return 0;
}