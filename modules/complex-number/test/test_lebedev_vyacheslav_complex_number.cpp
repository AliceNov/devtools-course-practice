// Copyright 2018 Lebedev Vyacheslav

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Lebedev_Vyacheslav_ComplexNumberTest, Integer_is_Equal_to_double) {
    // Arrange
    ComplexNumber z1(4, 5);
    ComplexNumber z2(4.0, 5.0);

    // Act

    // Assert
    ASSERT_TRUE(z1 == z2);
}

TEST(Lebedev_Vyacheslav_ComplexNumberTest, Is_Equal_to_Zero) {
    // Arrange
    ComplexNumber z1(0, 0);
    ComplexNumber z2(0.0, 0.0);

    // Act

    // Assert
    ASSERT_TRUE(z1 == z2);
}

TEST(Lebedev_Vyacheslav_ComplexNumberTest, Multiply_by_Zero_is_Correct) {
    // Arrange
    ComplexNumber z1(16.0, 15.0);
    ComplexNumber z2(0.0, 0.0);

    // Act
    ComplexNumber z = z1*z2;

    // Assert
    EXPECT_EQ(z2, z);
}

TEST(Lebedev_Vyacheslav_ComplexNumberTest, NumberIsEqualToItself) {
    // Arrange
    ComplexNumber z1(16.0, 15.0);

    // Act

    // Assert
    ASSERT_TRUE(z1 == z1);
}

TEST(Lebedev_Vyacheslav_ComplexNumberTest, CanCalculateFlow) {
    // Arrange
    ComplexNumber z1(16.0, 15.0);
    ComplexNumber z2(5.0, 4.0);
    ComplexNumber z3(3.0, 1.0);
    ComplexNumber z4(1.0, 2.0);
    ComplexNumber res(61.0, 17.0);

    // Act
    ComplexNumber z = (z1 + z2)*(z3 - z4);

    // Assert
    EXPECT_EQ(z, res);
}
