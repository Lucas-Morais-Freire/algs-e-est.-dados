#include "doublylinkedlist2.h"

int main() {
    struct doublyLinkedList* list = inicialize();
    insertElementAtBeginning(list, 0);
    insertElementAtBeginning(list, 1);
    showList(list);
    invertList(list);
    showList(list);

    deleteList(list);
    return 0;
}