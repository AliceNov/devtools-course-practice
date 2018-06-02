// Copyright 2017 Tarakanov Kirill

#include <gtest/gtest.h>
#include "include/Modify_Stack.h"

TEST(Tarakanov_Kirill_ModifyStackTest, Can_Create_ModifyStack) {
    // Arrange

    // Act

    // Assert
    ASSERT_NO_THROW(ModifyStack<int>());
}

TEST(Tarakanov_Kirill_ModifyStackTest, ModifyStack_Can_Push_Val) {
    // Arrange
    ModifyStack<int> *stack = new ModifyStack<int>();

    // Act

    // Assert
    ASSERT_NO_THROW(stack->Push(10));
}

TEST(Tarakanov_Kirill_ModifyStackTest, ModifyStack_Is_Empty) {
    // Arrange
    ModifyStack<int> *stack = new ModifyStack<int>();

    // Act
    stack->Push(10);
    bool empty = stack->IsEmpty();

    // Assert
    EXPECT_EQ(empty, 0);
}

TEST(Tarakanov_Kirill_ModifyStackTest, ModifyStack_Can_LookTop) {
    // Arrange
    ModifyStack<int> *stack = new ModifyStack<int>();

    // Act
    stack->Push(10);
    stack->Push(20);
    int onTop = stack->LookTop();

    // Assert
    EXPECT_EQ(onTop, 20);
}

TEST(Tarakanov_Kirill_ModifyStackTest, ModifyStack_Can_Pop) {
    // Arrange
    ModifyStack<int> *stack = new ModifyStack<int>();

    // Act
    stack->Push(10);
    stack->Push(-5);
    stack->Pop();
    int onTop = stack->LookTop();

    // Assert
    EXPECT_EQ(onTop, 10);
}

TEST(Tarakanov_Kirill_ModifyStackTest, ModifyStack_Can_KnewSize) {
    // Arrange
    ModifyStack<int> *stack = new ModifyStack<int>();

    // Act
    stack->Push(10);
    stack->Push(-5);
    stack->Push(4);
    stack->Push(0);
    stack->Push(3);

    // Assert
    EXPECT_EQ(stack->Size(), 5);
}

TEST(Tarakanov_Kirill_ModifyStackTest, ModifyStack_Can_FindMin) {
    // Arrange
    ModifyStack<int> *stack = new ModifyStack<int>();

    // Act
    stack->Push(10);
    stack->Push(20);
    int onTop = stack->FindMin();

    // Assert
    EXPECT_EQ(onTop, 10);
}
