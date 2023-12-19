#include "arraystack.hpp"

int main() {
    ArrayStack stack(10);

    for(int i = 0; i < 20; i++) {
        stack.putOnStack(i);
        std::cout << "capacity: " << stack.getCapacity() << "\n";
    }
    stack.showStack();
    std::cout << stack.inspectTopOfStack() << "\n";
    stack.showStack();

    for (int i = 0; i < 7; i++) {
        stack.removeFromStack();
    }
    stack.showStack();

    return 0;
}