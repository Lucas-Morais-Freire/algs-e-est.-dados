#include <stdbool.h>
#include "../arraystack/arraystack.h"

bool balancear(const char* par, int size) {
    struct arrayStack* stack = inicialize(size);
    for (int i = 0; i < size; i++) {
        if (par[i] == ')' && stack->size == 0) {
            return false;
        }
        if (par[i] == '(') {
            putOnStack(&stack, 0);
        } else {
            removeFromStack(stack);
        }
    }
    if (stack->size == 0) {
        return true;
    }
    return false;
}

int main() {
    const char* word = "(()())(()";

    if (balancear(word, 8)) {
        printf("hell ye\n");
    } else {
        printf("oh hell nah\n");
    }

    return 0;
}