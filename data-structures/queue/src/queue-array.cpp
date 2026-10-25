#include "queue-array.hpp"
#include <iostream>

QueueArray::QueueArray(int cap) {
    count = 0;
    this->cap = cap;
    arr = new int[this->cap];
    front = rear = 0;
}

QueueArray::~QueueArray() { delete[] arr; }

int QueueArray::circArr(int index) {
    if (index < 0) {
        cout << "Invalid index" << endl;
        return -1;
    }

    index %= cap;
    return index;
}

bool QueueArray::isEmpty() { return count == 0; }

bool QueueArray::isFull() { return count == cap; }

void QueueArray::enqueue(int data) {
    if (isFull()) {
        cout << "The queue is already full" << endl;
        return;
    }
    arr[rear] = data;
    rear = circArr(rear + 1);
    count++;
}

void QueueArray::dequeue() {
    if (isEmpty()) {
        cout << "The queue is already empty" << endl;
        return;
    }
    front = circArr(front + 1);
    count--;
}

int QueueArray::peekFront() {
    if (isEmpty()) {
        cout << "The queue is empty" << endl;
    }
    return arr[front];
}

int QueueArray::peekRear() {
    if (isEmpty()) {
        cout << "The queue is empty" << endl;
    }
    // rear sıranın sonundaki elemanın sağında kaldığı için bir gerisini işaret
    // etmemiz gerekiyor
    return arr[circArr(rear + (cap - 1))];
}

int QueueArray::size() { return count; }

void QueueArray::print() {
    if (isEmpty()) {
        cout << "The queue is empty" << endl;
        return;
    }
    // sadece sıradaki eleman sayısı kadarını ekrana yazdır
    for (int i = 0; i < count; i++) {
        int index = circArr(front + i);
        cout << arr[index] << " <- ";
    }
    cout << endl;
}
