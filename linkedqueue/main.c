#include "linkedqueue.h"

int main() {

    struct linkedQueue* queue = inicialize();
    for (int i = 0; i < 9; i++) {
        addToQueue(&queue, i);
    }
    showQueue(queue);
    takeFromQueue(queue);
    showQueue(queue);
    takeFromQueue(queue);
    showQueue(queue);
    addToQueue(&queue, -1);
    showQueue(queue);
    addToQueue(&queue, -2);
    showQueue(queue);
    takeFromQueue(queue);
    showQueue(queue);
    takeFromQueue(queue);
    showQueue(queue);

    deleteQueue(queue);
    return 0;
}