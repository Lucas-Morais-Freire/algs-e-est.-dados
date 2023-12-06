#include "doublylinkedlist2.hpp"

int main() {
    DoublyLinkedList list;
    
    for (int i = 0; i < 10; i++) {
        list.insertElementAtEnd(i);
    }
    list.showList();

    list.insertElementAtBeginning(-1);
    list.showList();
    list.insertElementAtPosition(-11, 3);
    list.insertElementAtPosition(-14, 8);
    list.showList();
    std::cout << "pos 3: " << list.getElementAtPosition(3) << " pos 8: " << list.getElementAtPosition(8) << std::endl;
    list.updateElementAtPosition(-16, 4);
    list.showList();
    list.removeElementAtPosition(0);
    list.removeElementAtPosition(list.getSize() - 1);
    list.removeElementAtPosition(list.getSize()/2);
    list.showList();
    list.invertList();
    list.showList();
    return 0;
}