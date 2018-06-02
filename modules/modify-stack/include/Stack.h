// Copyright 2018 Tarakanov Kirill

#ifndef MODULES_MODIFY_STACK_INCLUDE_STACK_H_
#define MODULES_MODIFY_STACK_INCLUDE_STACK_H_

#pragma once

template <typename T>
class Stack;

template <typename T>
class Node {
friend Stack<T>;

 private:
    T val;
    Node<T> *next;

 public:
    explicit Node(T _val = 0, Node<T> *_next = 0);
};

template <typename T>
Node<T>::Node(T _val, Node<T> *_next) {
    val = _val;
    next = _next;
}

template <typename T>
class Stack {
 private:
    Node<T> * currentTop;
    int sizeOfStack;
 public:
    Stack();
    ~Stack();

    bool IsEmpty();
    int Size();
    void Push(T val);
    void Pop();
    T LookTop();
};

template <typename T>
Stack<T>::Stack() {
    sizeOfStack = 0;
    currentTop = 0;
}

template <typename T>
Stack<T>::~Stack() {
    while (Size())
        Pop();
}

template <typename T>
bool Stack<T>::IsEmpty() {
    if (sizeOfStack == 0)
        return 1;
    else
        return 0;
}

template <typename T>
int Stack<T>::Size() {
    return sizeOfStack;
}

template <typename T>
void Stack<T>::Push(T val) {
    Node<T> *new_node = new Node<T>(val, currentTop);
    sizeOfStack++;
    currentTop = new_node;
}

template <typename T>
void Stack<T>::Pop() {
    Node<T> *node = currentTop;
    currentTop = currentTop->next;
    sizeOfStack--;
    delete node;
}

template <typename T>
T Stack<T>::LookTop() {
    return currentTop->val;
}

#endif  // MODULES_MODIFY_STACK_INCLUDE_STACK_H_
