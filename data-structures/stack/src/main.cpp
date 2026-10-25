#include "stack-array.hpp"
#include "stack-list.hpp"
#include <iostream>

int main() {
    // Stack with array implementation
    StackArray *stackArray = new StackArray(10);

    cout << "-----Stack with array implementation-----" << endl;

    stackArray->push(10);
    stackArray->push(20);
    stackArray->push(30);

    stackArray->print();

    cout << "Stack size is " << stackArray->size() << endl;

    if (stackArray->isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    if (stackArray->isFull()) {
        cout << "Stack is full" << endl;
    } else {
        cout << "Stack is not full" << endl;
    }

    cout << "-----push-----" << endl;
    stackArray->push(100);
    stackArray->print();

    cout << "-----pop-----" << endl;
    stackArray->pop();
    stackArray->print();

    cout << "-----peek-----" << endl;
    cout << "The top is " << stackArray->peek() << endl;

    delete stackArray;

    // Stack with linked list implementation
    StackLinkedList *stackLinkedList = new StackLinkedList();

    cout << "-----Stack with linked list implementation-----" << endl;

    stackLinkedList->push(1);
    stackLinkedList->push(2);
    stackLinkedList->push(3);

    stackLinkedList->print();

    cout << "Stack size is " << stackLinkedList->size() << endl;

    if (stackLinkedList->isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    cout << "-----push-----" << endl;
    stackLinkedList->push(100);
    stackLinkedList->print();

    cout << "-----pop-----" << endl;
    stackLinkedList->pop();
    stackLinkedList->print();

    cout << "-----peek-----" << endl;
    cout << "The top is " << stackLinkedList->peek() << endl;

    delete stackLinkedList;

    return 0;
}
