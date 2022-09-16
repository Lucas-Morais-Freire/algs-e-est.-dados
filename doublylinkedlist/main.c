#include "doublylinkedlist2.h"

int main() {
    struct doublyLinkedList* list = inicialize();
    for (int i = 0; i < 11; i++) {
        insertElementAtEnd(list, i);
    }
    showList(list);
    removeElementAtPosition(list, 0);
    showList(list);
    removeElementAtPosition(list, list->size - 1);
    showList(list);
    removeElementAtPosition(list, 5);
    showList(list);
    
    return 0;
}