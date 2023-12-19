#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include <iostream>

class ArrayStack {
    private:
        int* elements;
        int capacity;
        int size;
    public:
        ArrayStack(int cap);
        int getSize();
        int getCapacity();
        void duplicarCapacidade();  // O(n)
        void putOnStack(int value); // O(n) teta(1)
        bool isEmpty(); 
        void removeFromStack(); // O(1)
        int takeFromStack();    // O(1)
        int inspectTopOfStack(); // O(1)
        void showStack();
       ~ArrayStack(); 
};

ArrayStack::ArrayStack(int cap) {
    elements = new int[cap];
    capacity = cap;
    size = 0;
}

int ArrayStack::getSize() {
    return size;
}

int ArrayStack::getCapacity() {
    return capacity;
}

void ArrayStack::duplicarCapacidade() {
    int* newElements = new int[2*capacity];
    for (int i = 0; i < capacity; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity *= 2;
}

void ArrayStack::putOnStack(int value) {
    if (capacity == size) {
        this->duplicarCapacidade();
    }
    elements[size] = value;
    size++;
}

bool ArrayStack::isEmpty()  {
    if (size == 0) {
        return true;
    }
    return false;
}

void ArrayStack::removeFromStack() {
    if (this->isEmpty()) {
        std::cout << "This stack is empty.\n";
        return;
    }
    size--;
}

int ArrayStack::takeFromStack() {
    if (this->isEmpty()) {
        std::cout << "This stack is empty.\n";
        return INT_MIN;
    }
    size--;
    return elements[size];
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int ArrayStack::inspectTopOfStack() {
    if (this->isEmpty()) {
        std::cout << "This stack is empty.\n";
        return INT_MIN;
    }
    return elements[size - 1];
}

ArrayStack::~ArrayStack() {
    delete[] elements;
}

void ArrayStack::showStack() {
    std::cout << "_\n";
    for(int i = size - 1; i >= 0; i--){
        std::cout << elements[i] << "\n";
    }
    std::cout << "_\n\n";
}

#endif //ARRAYSTACK_HPP