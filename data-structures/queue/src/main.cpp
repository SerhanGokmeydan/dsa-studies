#include "queue-array.hpp"
#include "queue-list.hpp"
#include <iostream>

int main() {
    QueueArray *queueArray = new QueueArray(5);
    QueueList *queueList = new QueueList();

    cout << "-----Queue with array implementation-----" << endl;

    queueArray->enqueue(10);
    queueArray->enqueue(20);
    queueArray->enqueue(30);
    queueArray->enqueue(40);
    queueArray->enqueue(50);
    queueArray->print();

    cout << "front: " << queueArray->peekFront()
         << " rear: " << queueArray->peekRear() << endl;

    queueArray->dequeue();
    queueArray->print();

    cout << "front: " << queueArray->peekFront()
         << " rear: " << queueArray->peekRear() << endl;

    cout << "Queue size is " << queueArray->size() << endl;

    cout << "-----Queue with list implementation-----" << endl;

    queueList->enqueue(10);
    queueList->enqueue(20);
    queueList->enqueue(30);
    queueList->enqueue(40);
    queueList->enqueue(50);
    queueList->print();

    cout << "front: " << queueList->peekFront()
         << " rear: " << queueList->peekRear() << endl;

    queueList->dequeue();
    queueList->print();

    cout << "front: " << queueList->peekFront()
         << " rear: " << queueList->peekRear() << endl;

    cout << "Queue size is " << queueList->size() << endl;
}
