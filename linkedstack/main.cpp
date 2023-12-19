#include "linkedstack.hpp"

int main() {
    LinkedStack stack;

    for (int i = 0; i < 11; i++) {
        stack.putOnStack(i);
    }
    stack.showStack();
    int last = stack.inspectTopOfStack();
    stack.showStack();
    std::cout << last << "\n";

    for (int i = 0; i < 4; i++) {
        stack.removeFromStack();
    }
    stack.showStack();

    return 0;
}