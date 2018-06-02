// Copyright 2018 Dvorjanchikov Evgeniy

#include <gtest/gtest.h>

#include <math.h>

#include "include/area_calculation.h"

TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Constructor_test_1) {
    // Arrange
    int _size = 3;
    double x_mas[3]{ 1, 2, 3 };
    double y_mas[3]{ 1, 2, 1 };

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    EXPECT_EQ(_size, A.GetSize());
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Constructor_test_2) {
    // Arrange
    int _size = 3;
    double x_mas[3]{ 1, 2, 3 };
    double y_mas[3]{ 1, 2, 1 };
    bool flag = true;
    double* x_res;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    x_res = A.GetX();
    for (int i = 0; i < _size; i++) {
        if (fabs(x_mas[i] - x_res[i]) > 0.0001)
            flag = false;
    }
    EXPECT_TRUE(flag);
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Constructor_test_3) {
    // Arrange
    int _size = 3;
    double x_mas[3]{ 1, 2, 3 };
    double y_mas[3]{ 1, 2, 1 };
    bool flag = true;
    double* y_res;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    y_res = A.GetY();
    for (int i = 0; i < _size; i++) {
        if (fabs(y_mas[i] - y_res[i]) > 0.0001)
            flag = false;
    }
    EXPECT_TRUE(flag);
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Area_test_1) {
    // Arrange
    int _size = 4;
    double x_mas[4]{ 1, 1, 2, 2 };
    double y_mas[4]{ 1, 2, 2, 1};
    double res = 1;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    EXPECT_EQ(res, A.GetArea());
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Area_test_2) {
    // Arrange
    int _size = 8;
    double x_mas[8]{ 1, 1, 2, 2, 3, 3, 4, 4};
    double y_mas[8]{ -3, -2, -2, -1, -1, -2, -2, -3};
    double res = 4;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    EXPECT_EQ(res, A.GetArea());
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Area_test_3) {
    // Arrange
    int _size = 8;
    double x_mas[8]{ -1, -1, -2, -2, -3, -3, -4, -4};
    double y_mas[8]{ -3, -2, -2, -1, -1, -2, -2, -3};
    double res = 4;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);
    A.GetArea();

    // Assert
    EXPECT_EQ(res, A.GetArea());
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Area_test_4) {
    // Arrange
    int _size = 4;
    double x_mas[4]{ 5, 5, 4, 4};
    double y_mas[4]{ 6, 5, 5, 6};
    double res = 1;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    EXPECT_EQ(res, A.GetArea());
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Zero_area_test_1) {
    // Arrange
    int _size = 4;
    double x_mas[4]{ 1, 1, 1, 1};
    double y_mas[4]{ 1, 2, 3, 4};
    double res = 0;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    EXPECT_EQ(res, A.GetArea());
}
TEST(Dvorjanchikov_Evgeniy_Area_Calculation_Test, Zero_area_test_2) {
    // Arrange
    int _size = 4;
    double x_mas[4]{ 1, 2, 3, 4 };
    double y_mas[4]{ 1, 1, 1, 1 };
    double res = 0;

    // Act
    AreaCalculation A(_size, x_mas, y_mas);

    // Assert
    EXPECT_EQ(res, A.GetArea());
}
