#include "../linkedlist/linkedlist2.h"

void invertList(struct linkedList* list) {
    struct node* aux1 = list->head;
    struct node* aux2;
    for (int i = 0; i < list->size/2; i++) {
        aux2 = aux1;
        for (int j = 0; j < list->size - 2*i - 1; j++) {
            aux2 = aux2->next;
        }
        int A = aux1->val;
        aux1->val = aux2->val;
        aux2->val = A;
        aux1 = aux1->next;
    }
}

int main() {
    struct linkedList* list = inicialize();
    for (int i = 0; i < 0; i++) {
        insertElementAtEnd(list, i);
    }
    showList(list);

    invertList(list);

    showList(list);

    deleteList(list);

    return 0;
}