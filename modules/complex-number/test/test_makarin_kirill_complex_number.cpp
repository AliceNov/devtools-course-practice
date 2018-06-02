// Copyright 2018 Makarin Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Makarin_Kirill_ComplexNumberTest, Correct_Multilication) {
    // Arrange
    double r = 2.0, r1 = 3.0;
    double i = 1.0, i1 = 1.0;

    // Act
    ComplexNumber c(r, i);
    ComplexNumber c1(r1, i1);
    ComplexNumber c_mult = c * c1;
    ComplexNumber true_res(5.0, 5.0);

    // Assert
    EXPECT_EQ(true_res, c_mult);
}

TEST(Makarin_Kirill_ComplexNumberTest, Not_Equals_Zero) {
    // Arrange
    double r = 2.0, zr = 0.0;
    double i = 1.0, zi = 0.0;

    // Acr
    ComplexNumber c(r, i);
    ComplexNumber z(zr, zi);

    // Assert
    ASSERT_FALSE(z == c);
}

TEST(Makarin_Kirill_ComplexNumberTest, Correct_Assignment) {
    // Arrange
    double r = 2.0, r1 = 3.0;
    double i = 1.0, i1 = 1.0;

    // Act
    ComplexNumber c(r, i);
    ComplexNumber c1(r1, i1);
    c = c1;

    // Assert
    EXPECT_EQ(c, c1);
}

TEST(Makarin_Kirill_ComplexNumberTest, Create_Copy) {
    // Arrange
    double r = 1.11;
    double i = 2.02;

    // Act
    ComplexNumber x(r, i);
    ComplexNumber xCopy(x);

    // Assert
    EXPECT_EQ(x, xCopy);
}

TEST(Makarin_Kirill_ComplexNumberTest, Correct_Set) {
    // Arrange
    double r = 2.0;
    double i = 2.0;

    // Act
    ComplexNumber a(r, i);
    ComplexNumber d(0.0, 0.0);
    d.setRe(r);
    d.setIm(i);

    // Assert
    EXPECT_EQ(a, d);
}
