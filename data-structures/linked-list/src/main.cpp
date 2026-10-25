#include "linked-list.hpp"
#include <iostream>

int main() {
    LinkedList *linkedList = new LinkedList();

    linkedList->insertEnd(10);
    linkedList->insertEnd(20);
    linkedList->insertEnd(30);

    cout << "List length is " << linkedList->getNodeCount() << endl;
    linkedList->printLinkedList();

    if (linkedList->searchNode(2)) {
        cout << "List includes node with data 2" << endl;
    } else {
        cout << "List does not include node with data 2" << endl;
    }

    if (linkedList->searchNode(10)) {
        cout << "List includes node with data 10" << endl;
    } else {
        cout << "List does not include node with data 10" << endl;
    }

    linkedList->getNthFromBeginning(1);
    linkedList->getNthFromEnd(2);

    cout << "-------------" << endl;

    linkedList->insertBeginnig(4);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->insertAfterNode(10, 5);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->insertBeforeNode(30, 6);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->insertAtPoint(5, 7);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->insertEnd(60);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->deleteBeginning();
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->deleteAfterNode(10);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->deleteBeforeNode(30);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->deleteAtPoint(3);
    linkedList->printLinkedList();

    cout << "-------------" << endl;

    linkedList->deleteEnd();
    linkedList->printLinkedList();

    delete linkedList;
}
