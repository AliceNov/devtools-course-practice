// Copyright 2017 Tarakanov Kirill

#include <gtest/gtest.h>
#include "include/Stack.h"

TEST(Tarakanov_Kirill_StackTest, Can_Create_Node_withINT) {
    // Arrange

    // Act

    // Assert
    ASSERT_NO_THROW(Node<int>());
}

TEST(Tarakanov_Kirill_StackTest, Can_Create_Node_withFLOAT) {
    // Arrange

    // Act

    // Assert
    ASSERT_NO_THROW(Node<float>());
}

TEST(Tarakanov_Kirill_StackTest, Can_Create_Node_withParametrs) {
    // Arrange
    int val = 10;
    Node<int> _node(val, 0);

    // Act

    // Assert
    ASSERT_NO_THROW(Node<int>(6, &_node));
}

TEST(Tarakanov_Kirill_StackTest, Can_Create_Stack) {
    // Arrange

    // Act

    // Assert
    ASSERT_NO_THROW(Stack<int>());
}

TEST(Tarakanov_Kirill_StackTest, Stack_Can_Push_Val) {
    // Arrange
    Stack<int> *stack = new Stack<int>();

    // Act

    // Assert
    ASSERT_NO_THROW(stack->Push(10));
}

TEST(Tarakanov_Kirill_StackTest, Stack_Is_Empty) {
    // Arrange
    Stack<int> *stack = new Stack<int>();

    // Act
    stack->Push(10);
    bool empty = stack->IsEmpty();

    // Assert
    EXPECT_EQ(empty, 0);
}

TEST(Tarakanov_Kirill_StackTest, Stack_Can_LookTop) {
    // Arrange
    Stack<int> *stack = new Stack<int>();

    // Act
    stack->Push(10);
    stack->Push(20);
    int onTop = stack->LookTop();

    // Assert
    EXPECT_EQ(onTop, 20);
}

TEST(Tarakanov_Kirill_StackTest, Stack_Can_Pop) {
    // Arrange
    Stack<int> *stack = new Stack<int>();

    // Act
    stack->Push(10);
    stack->Push(-5);
    stack->Pop();
    int onTop = stack->LookTop();

    // Assert
    EXPECT_EQ(onTop, 10);
}

TEST(Tarakanov_Kirill_StackTest, Stack_Can_KnewSize) {
    // Arrange
    Stack<int> *stack = new Stack<int>();

    // Act
    stack->Push(10);
    stack->Push(-5);
    stack->Push(4);
    stack->Push(0);
    stack->Push(3);

    // Assert
    EXPECT_EQ(stack->Size(), 5);
}
