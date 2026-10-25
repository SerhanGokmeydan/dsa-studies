#include "stack-array.hpp"
#include <iostream>

StackArray::StackArray(int cap) {
    this->capacity = cap;
    this->arr = new int[this->capacity];
    this->top = -1;
}

StackArray::~StackArray() { delete[] this->arr; }

void StackArray::push(int data) {
    if (this->isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    this->arr[++top] = data;
}

void StackArray::pop() {
    if (this->isEmpty()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    --this->top;
}

int StackArray::peek() {
    if (this->isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return this->arr[top];
}

bool StackArray::isEmpty() { return this->top == -1; }

bool StackArray::isFull() { return this->top == this->capacity - 1; }

int StackArray::size() { return this->top + 1; }

void StackArray::print() {
    for (int i = 0; i <= this->top; ++i) {
        cout << this->arr[i] << " -> ";
    }
    cout << endl;
}
