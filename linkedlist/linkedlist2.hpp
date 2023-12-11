#ifndef LINKEDLIST2_H
#define LINKEDLIST2_H

#include <iostream>

template <class T, class W>
struct node {
    T* dst;
    W weight;
    node* next;
};

template <class T, class W>
class LinkedList {
    private:
        int size;
        node<T, W>* head;
    public:
        LinkedList::LinkedList() {
            size = 0;
            head = nullptr;
        }

        void LinkedList::insertElementAtEnd(T* dst, W& weight) {
            if (size == 0) {
                head = new node<T, W>;
                head->next = nullptr;
                head->dst = dst;
                head->weight = weight;
            } else {
                node<T, W>* temp = head;
                // for (int i = 1; i < size; i++) { // size = 1
                //     temp = temp->next;
                // }

                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                
                temp->next = new node<T, W>;
                temp->next->next = nullptr;
                temp->next->dst = dst;
                temp->next->weight = weight;
            }
            size++;
        }

        void LinkedList::removeLastElement() {
            if (size == 0) {
                std::cout << "this list is already empty.\n";
                exit(0);
            }
            node<T, W>* temp = head;
            // for (int i = 1; i < size; i++) {
            //     temp = temp->next;
            // }

            if (head->next == nullptr) {
                delete head;
                size--;
                head = nullptr;
                return;
            }

            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
            size--;
        }

        int LinkedList::getElementAtPosition(int pos) {
            if (pos >= size || pos < 0) {
                std::cout << "Invalid list position.\n";
                exit(-1);
            }
            node<T, W>* temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            return temp->val;
        }

        void LinkedList::insertElementAtPosition(int value, int pos) {
            if (pos >= size || pos < 0) {
                std::cout << "Invalid list position.\n";
                return;
            }
            node* target = new node;
            target->val = value;
            node* temp = head;
            if (pos == 0) {
                target->next = head;
                head = target;
                size++;
                return;
            }
            for (int i = 1; i < pos; i++) {
                if (i == pos - 1) {
                    target->next = temp->next;
                    temp->next = target;
                    size++;
                    return;
                }
                temp = temp->next;
            }
        }

        void LinkedList::updateElementAtPosition(int value, int pos) {
            if (pos >= size || pos < 0) {
                std::cout << "Invalid list position.\n";
                return;
            }
            node* temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            temp->val = value;
        }

        void LinkedList::removeElementAtPosition(int pos) {
            if (pos >= size || pos < 0) {
                std::cout << "Invalid list position.\n";
                return;
            }
            node* temp = head;
            if (pos == 0) {
                head = head->next;
                delete temp;
                size--;
                return;
            }
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }
            node* aux = temp->next;
            temp->next = temp->next->next;
            delete aux;
            size--;
        }

        void LinkedList::showList() {
            if (size == 0) {
                std::cout << "This list is empty.\n";
                return;
            }
            std::cout << "(";
            node* temp = head;
            for (int i = 0; i < size - 1; i++) {
                std::cout << temp->val << ")->(";
                temp =temp->next;
            }
            std::cout << temp->val << ")\n";
        }

        LinkedList::~LinkedList() {
            node* temp = head;
            node* aux;
            for (int i = 0; i < size; i++) {
                aux = temp->next;
                delete temp;
                temp = aux;
            }
        }
}

#endif //LINKEDLIST2_H