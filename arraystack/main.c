#include "arraystack.h"

int main() {

    struct arrayStack* stack = inicialize(5);

    for(int i = 0; i < 20; i++) {
        putOnStack(&stack, i);
        printf("capacity: %d\n", stack->capacity);
    }

    showStack(stack);

    deleteStack(stack);

    return 0;
}