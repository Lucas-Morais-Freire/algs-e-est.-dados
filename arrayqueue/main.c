#include "arrayqueue.h"

void printElements(struct arrayQueue* queue) {
    for (int i = 0; i < queue->capacity; i++) {
        if (i == queue->front) {
            printf("f", queue->elements[i]);
        }
        if (i == queue->back) {
            printf("b", queue->elements[i]);
        }
        printf("[%d]", queue->elements[i]);
    }
    printf("\n");
}

int main() {

    struct arrayQueue* queue = inicialize(1);
    addToQueue(&queue, 0);
    printf("cap: %d\n", queue->capacity);
    addToQueue(&queue, 1);
    printf("cap: %d\n", queue->capacity);
    addToQueue(&queue, 2);
    printf("cap: %d\n", queue->capacity);
    addToQueue(&queue, 3);
    printf("cap: %d\n", queue->capacity);
    showQueue(queue);
    printElements(queue);
    takeFromQueue(queue);
    showQueue(queue);
    printElements(queue);
    takeFromQueue(queue);
    showQueue(queue);
    printElements(queue);
    takeFromQueue(queue);
    showQueue(queue);
    printElements(queue);
    addToQueue(&queue, -1);
    showQueue(queue);
    printElements(queue);
    addToQueue(&queue, -2);
    showQueue(queue);
    printElements(queue);
    addToQueue(&queue, -3);
    showQueue(queue);
    printElements(queue);
    addToQueue(&queue, -4);
    showQueue(queue);
    printElements(queue);

    return 0;
}