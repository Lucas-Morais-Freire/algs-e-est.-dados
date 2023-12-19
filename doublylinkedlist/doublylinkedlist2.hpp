#ifndef DOUBLYLINKEDLIST2_H
#define DOUBLYLINKEDLIST2_H

#include <iostream>

struct node {
	int val;
    node* prev;
    node* next;
};

class DoublyLinkedList {
    private:
        int size;
        node* head;
        node* tail;
        
        node* allocateNewNode(int value);
    public:
        DoublyLinkedList();
        int getSize();
        void insertElementAtBeginning(int value); // O(1)
        void insertElementAtEnd(int value);       // O(1)
        void insertElementAtPosition(int value, int pos); // O(n)
        int getElementAtPosition(int pos);                // O(n)
        void updateElementAtPosition(int value, int pos); // O(n)
        void removeElementAtPosition(int pos);            // O(n)
        void showList();
        void invertList();
        ~DoublyLinkedList();
};

node* DoublyLinkedList::allocateNewNode(int value) {
    node* newNode = new node;
    newNode->val = value;
    return newNode;
}

DoublyLinkedList::DoublyLinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

int DoublyLinkedList::getSize() {
    return size;
}

void DoublyLinkedList::insertElementAtBeginning(int value) {
    node* newNode = allocateNewNode(value);
    if (size == 0) {
        head = newNode;
        tail = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        size++;
        return;
    }
    newNode->next = head;
    newNode->prev = nullptr;
    head->prev = newNode;
    head = newNode;
    size++;
}

void DoublyLinkedList::insertElementAtEnd(int value) {
    if (size == 0) {
        this->insertElementAtBeginning(value);
        return;
    }
    node* newNode = allocateNewNode(value);
    tail->next = newNode;
    newNode->next = nullptr;
    newNode->prev = tail;
    tail = newNode;
    size++;
}

void DoublyLinkedList::insertElementAtPosition(int value, int pos) {
    if (pos > size || pos < 0) {
        std::cout << "invalid list position\n";
        exit(-1);
    }

    if (pos == 0) {
        this->insertElementAtBeginning(value);
    } else if (pos == size) {
        this->insertElementAtEnd(value);
    } else {
        node* temp;
        node* newNode = allocateNewNode(value);
        if (size > pos << 1) { // pos < size/2
            temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = size - 1; i > pos; i--) {
                temp = temp->prev;
            }
        }
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
        size++;
    }
}

int DoublyLinkedList::getElementAtPosition(int pos) {
    if (pos >= size || pos < 0) {
        std::cout << "Invalid list position.\n";
        exit(-1);
    }
    if (pos == 0) {
        return head->val;
    } else if (pos == size - 1) {
        return tail->val;
    } else {
        node* temp;
        if (size > pos << 1) { // pos < size/2
            temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            return temp->val;
        } else {
            temp = tail;
            for (int i = size - 1; i > pos; i--) {
                temp = temp->prev;
            }
            return temp->val;
        }
    }
}

void DoublyLinkedList::updateElementAtPosition(int value, int pos) {
    if (pos >= size || pos < 0) {
        std::cout << "Invalid list position.\n";
        exit(-1);
    }
    if (pos == 0) {
        head->val = value;
    } else if (pos == size - 1) {
        tail->val = value;
    } else {
        node* temp;
        if (size > pos << 1) { // pos < size/2
            temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            temp->val = value;
        } else {
            temp = tail;
            for (int i = size - 1; i > pos; i--) {
                temp = temp->prev;
            }
            temp->val = value;
        }
    }
}

void DoublyLinkedList::removeElementAtPosition(int pos) {
    if (pos >= size || pos < 0) {
        std::cout << "Invalid list position.\n";
        exit(-1);
    }
    if (pos == 0) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    } else if (pos == size - 1) {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    } else {
        node* temp;
        if (size > pos << 1) { // pos < size/2
            temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = size - 1; i > pos; i--) {
                temp = temp->prev;
            }
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    size--;
}

void DoublyLinkedList::showList() {
    std::cout << "(";
    node* temp = head;
    for (int i = 0; i < size - 1; i++) {
        std::cout << temp->val << ")<->(";
        temp = temp->next;
    }
    std::cout << temp->val << ")\n";
}

DoublyLinkedList::~DoublyLinkedList() {
    node* temp = head;
    node* aux;
    for (int i = 0; i < size; i++) {
        aux = temp->next;
        delete temp;
        temp = aux;
    }
}

void DoublyLinkedList::invertList() {
    node* temp = head;
    head = tail;
    tail = temp;
    node* aux;
    for (int i = 0; i < size; i++) {
        aux = temp->next;
        temp->next = temp->prev;
        temp->prev = aux;
        temp = temp->prev;
    }
}

#endif //DOUBLYLINKEDLIST2_H