#include "linkedstack.h"

int main() {

    struct linkedStack* stack = inicialize();

    for (int i = 0; i < 11; i++) {
        putOnStack(&stack, i);
    }
    showStack(stack);
    int last = inspectTopOfStack(stack);
    showStack(stack);
    printf("%d\n", last);

    return 0;
}