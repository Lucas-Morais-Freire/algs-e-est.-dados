#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

#include <iostream>

struct node {
    int val;
    node* next;
};

class LinkedStack {
    private:
        node* top;
        int size;
        node* allocateNewNode(int value);
    public:
        LinkedStack();
        bool isEmpty();
        void putOnStack(int value);
        void removeFromStack();
        int takeFromStack();
        int inspectTopOfStack();
        void showStack();
        ~LinkedStack();
};

LinkedStack::LinkedStack() {
    size = 0;
    top = nullptr;
}

node* LinkedStack::allocateNewNode(int value){
    struct node* newNode = new node;
    newNode->val = value;
    newNode->next = nullptr;
    return newNode;
}

//retornar true se a pilha for nula ou vazia
bool LinkedStack::isEmpty() {
    if (size == 0) {
        return true;
    }
    return false;
}

void LinkedStack::putOnStack(int value) {
    node* newNode = allocateNewNode(value);
    node* aux = this->top;
    this->top = newNode;
    newNode->next = aux;
    size++;
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void LinkedStack::removeFromStack() {
    if (size == 0) {
        std::cout << "The stack is empty.\n";
        return;
    }

    node* aux = top;
    top = top->next;
    size--;
    delete aux;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int LinkedStack::takeFromStack() {
    if (size == 0) {
        std::cout << "This stack is empty.\n";
        return INT_MIN;
    }
    node* aux = top;
    top = top->next;
    int value = aux->val;
    size--;
    delete aux;
    return value;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int LinkedStack::inspectTopOfStack(){
    if (size == 0) {
        std::cout << "This stack is empty.\n";
        return INT_MIN;
    }

    return top->val;
}

void LinkedStack::showStack() {
    //usamos o aux para percorrer a lista
    if (!this->isEmpty()) {
        node* aux = top;
        //navega partindo do topo até chegar NULL
       std::cout << "_\n";
        do {
            std::cout << aux->val << "\n";
            aux = aux->next;
        } while (aux != NULL);
        std::cout << "_\n\n";
    }
    else {
        std::cout << "A pilha está vazia!";
    }
}

LinkedStack::~LinkedStack() {
    node* temp = top;
    node* aux;
    for (int i = 0; i < size; i++) {
        aux = temp->next;
        delete temp;
        temp = aux;
    }
}

#endif // LINKEDSTACK_HPP