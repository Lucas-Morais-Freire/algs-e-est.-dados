#include "doublylinkedlist2.h"

int main() {
    struct doublyLinkedList* list = inicialize();
    for (int i = 0; i < 11; i++) {
        insertElementAtBeginning(list, i);
    }
    showList(list);

    return 0;
}