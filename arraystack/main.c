#include "arraystack.h"

int main() {

    struct arrayStack* stack;

    for(int i = 0; i < 20; i++) {
        putOnStack(&stack, i);
        printf("capacity: %d\n", stack->capacity);
    }
    showStack(stack);
    int last = takeFromStack(stack);
    showStack(stack);
    printf("%d\n\n", last);
    last = takeFromStack(stack);
    showStack(stack);
    printf("%d\n\n", last);

    deleteStack(stack);

    return 0;
}