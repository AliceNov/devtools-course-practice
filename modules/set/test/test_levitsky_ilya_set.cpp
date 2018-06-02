// Copyright 2018 Levitsky Ilya

#include <gtest/gtest.h>

#include "include/set.h"

TEST(Levitsky_Ilya_setTest, Can_Create_Set) {
    // Arrange
    set A;

    // Act
    A.Insert(5);

    // Assert
    EXPECT_EQ(5, A.GetN(5));
}

TEST(Levitsky_Ilya_setTest, Disjunctio_Sets) {
    // Arrange
    set A;
    set B;
    set C;

    // Act
    A.Insert(4);
    B.Insert(7);

    C = A + B;

    // Assert
    EXPECT_EQ(4, C.GetN(4));
    EXPECT_EQ(7, C.GetN(7));
}

TEST(Levitsky_Ilya_setTest, Conjuctio_Sets) {
    // Arrange
    set A;
    set B;
    set C;

    // Act
    A.Insert(2);
    A.Insert(4);
    A.Insert(6);

    B.Insert(3);
    B.Insert(4);
    B.Insert(9);
    B.Insert(6);

    C = A*B;

    // Assert
    EXPECT_EQ(4, C.GetN(4));
    EXPECT_EQ(6, C.GetN(6));
}

TEST(Levitsky_Ilya_setTest, Addition_Set) {
    // Arrange
    set A;
    set C;

    // Act
    A.Insert(5);
    A.Insert(4);
    A.Insert(6);
    A.Insert(3);
    A.Insert(2);

    C = ~A;

    // Assert
    EXPECT_EQ(1, C.GetN(1));
    EXPECT_EQ(7, C.GetN(7));
    EXPECT_EQ(8, C.GetN(8));
    EXPECT_EQ(9, C.GetN(9));
    EXPECT_EQ(10, C.GetN(10));
}

TEST(Levitsky_Ilya_setTest, Can_Get_Bit) {
    // Arrange
    set A;

    // Act
    A.Insert(5);

    // Assert
    EXPECT_EQ(256, A.Get(5));
}

TEST(Levitsky_Ilya_setTest, Can_Assign_Set) {
    // Arrange
    set A;
    set B;

    // Act
    A.Insert(5);
    A.Insert(6);
    A.Insert(2);

    B = A;

    // Assert
    EXPECT_EQ(5, B.GetN(5));
    EXPECT_EQ(6, B.GetN(6));
    EXPECT_EQ(2, B.GetN(2));
}

TEST(Levitsky_Ilya_setTest, Can_Not_Get_Num) {
    // Arrange
    set A;

    // Act
    A.Insert(5);

    // Assert
    EXPECT_EQ(0, A.GetN(4));
}

TEST(Levitsky_Ilya_setTest, Dif_Disjunctio_Sets) {
    // Arrange
    set A;
    set B;
    set C;

    // Act
    A.Insert(4);
    B.Insert(7);
    B.Insert(5);

    C = A + B;

    // Assert
    EXPECT_EQ(4, C.GetN(4));
    EXPECT_EQ(7, C.GetN(7));
    EXPECT_EQ(5, C.GetN(5));
}

TEST(Levitsky_Ilya_setTest, Can_Copy) {
    // Arrange
    set A;

    // Act
    A.Insert(5);
    set B(A);

    // Assert
    EXPECT_EQ(5, B.GetN(5));
}

TEST(Levitsky_Ilya_setTest, Test_BF) {
    // Arrange
    bitfield X(100);
    bitfield Y(X);

    // Act
    Y = X;

    // Assert
    EXPECT_EQ(0, X.GetBit(3));
}
