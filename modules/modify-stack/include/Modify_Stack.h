// Copyright 2018 Tarakanov Kirill

#ifndef MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_H_
#define MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_H_

#pragma once
#include "Stack.h"
#include <math.h>

template <typename T>
class ModifyStack {
 private:
    Stack<T>* stack1;
    Stack<T>* stack2;
 public:
    ModifyStack();
    ~ModifyStack();

    bool IsEmpty();
    int Size();
    void Push(T val);
    void Pop();
    T LookTop();
    T FindMin();
};

template <typename T>
ModifyStack<T>::ModifyStack() {
    stack1 = new Stack<T>();
    stack2 = new Stack<T>();
}

template <typename T>
ModifyStack<T>::~ModifyStack() {
    delete stack1;
    delete stack2;
}

template <typename T>
bool ModifyStack<T>::IsEmpty() {
    if (stack1->IsEmpty())
        return 1;
    else
        return 0;
}

template <typename T>
int ModifyStack<T>::Size() {
    return stack1->Size();
}

template <typename T>
void ModifyStack<T>::Push(T val) {
    if (stack1->IsEmpty()) {
        stack1->Push(val);
        stack2->Push(val);
    } else {
        stack1->Push(val);
        T curVal = stack2->LookTop();
        if (val < curVal)
            curVal = val;
        stack2->Push(curVal);
    }
}

template <typename T>
void ModifyStack<T>::Pop() {
    stack1->Pop();
    stack2->Pop();
}

template <typename T>
T ModifyStack<T>::LookTop() {
    return stack1->LookTop();
}

template <typename T>
T ModifyStack<T>::FindMin() {
    return stack2->LookTop();
}

#endif  // MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_H_
