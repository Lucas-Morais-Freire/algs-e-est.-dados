#include <stdio.h>
#include "arraylist2.h"

int main() {
    struct linkedList* list = inicialize();
    insertAtEnd(list, 8);
    insertAtEnd(list, 3);
    insertAtEnd(list, 2);
    removeLastValue(list);
    printf("%d\n", getValueAtPosition(list, 2));

    free(list);
    return 0;
}