#include "arraystack.h"

int main() {

    struct arrayStack* stack;

    for(int i = 0; i < 20; i++) {
        putOnStack(&stack, i);
        printf("capacity: %d\n", stack->capacity);
    }
    showStack(stack);
    int last = inspectTopOfStack(stack);
    printf("%d\n", last);
    showStack(stack);

    deleteStack(stack);

    return 0;
}