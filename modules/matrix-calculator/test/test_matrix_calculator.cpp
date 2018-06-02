// Copyright 2018 Fedorova Olga

#include <gtest/gtest.h>
#include <vector>
#include "include/matrix_calculator.h"

TEST(MatrixCalculatorTest, can_create_default_and_with_sizes) {
    MatrixCalculator matrix1;
    MatrixCalculator matrix2(1, 1);

    EXPECT_EQ(matrix1, matrix2);
}

TEST(MatrixCalculatorTest, can_create_copy) {
    MatrixCalculator matrix1(2, 2);
    MatrixCalculator matrix2(matrix1);

    EXPECT_EQ(matrix1, matrix2);
}

TEST(MatrixCalculatorTest, cant_create_with_negativ_sizes) {
    EXPECT_ANY_THROW(MatrixCalculator matrix(-1, -1));
}

TEST(MatrixCalculatorTest, correct_set) {
    std::vector<std::vector<double>> vect(3, std::vector<double>(3, 0.0));
    for (size_t i = 0; i < vect.size(); i++) {
        vect[i][i] = 3;
    }
    MatrixCalculator matrix1(1, 2);
    MatrixCalculator matrix2(matrix1);

    matrix1.SetMatrix(vect);
    matrix2.SetMatrix(vect);

    EXPECT_EQ(matrix1, matrix2);
}

TEST(MatrixCalculatorTest, size_error_in_set) {
    std::vector<std::vector<double>> vect(2);
    vect[0] = std::vector<double>(1);
    vect[1] = std::vector<double>(3);

    MatrixCalculator matrix1;

    EXPECT_ANY_THROW(matrix1.SetMatrix(vect));
}

TEST(MatrixCalculatorTest, correct_are_sizes_equal) {
    std::vector<std::vector<double>> vect1(3, std::vector<double>(3, 0.0));
    std::vector<std::vector<double>> vect2(3, std::vector<double>(5, 0.0));

    MatrixCalculator matrix1;
    MatrixCalculator matrix2;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);

    EXPECT_FALSE(matrix1.AreSizesEqual(matrix2));
}

TEST(MatrixCalculatorTest, correct_equal_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(2, std::vector<double>(2, 2));

    MatrixCalculator matrix1, matrix2;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);

    matrix1 = matrix2;

    EXPECT_EQ(matrix1, matrix2);
}

TEST(MatrixCalculatorTest, correct_plus_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(1, 2));
    std::vector<std::vector<double>> vect3(1, std::vector<double>(1, 3));

    MatrixCalculator matrix1, matrix2, sum, real_res;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);
    real_res.SetMatrix(vect3);

    sum = matrix1 + matrix2;

    EXPECT_EQ(sum, real_res);
}

TEST(MatrixCalculatorTest, correct_minus_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(1, 2));
    std::vector<std::vector<double>> vect3(1, std::vector<double>(1, -1));

    MatrixCalculator matrix1, matrix2, res, real_res;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);
    real_res.SetMatrix(vect3);

    res = matrix1 - matrix2;

    EXPECT_EQ(res, real_res);
}

TEST(MatrixCalculatorTest, correct_multiply_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(1, 2));
    std::vector<std::vector<double>> vect3(1, std::vector<double>(1, 2));

    MatrixCalculator matrix1, matrix2, res, real_res;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);
    real_res.SetMatrix(vect3);

    res = matrix1 * matrix2;

    EXPECT_EQ(res, real_res);
}

TEST(MatrixCalculatorTest, operator_plus_error_with_not_equal_size) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(2, 2));

    MatrixCalculator matrix1, matrix2;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);

    EXPECT_ANY_THROW(matrix1 + matrix2);
}

TEST(MatrixCalculatorTest, operator_minus_error_with_not_equal_size) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(2, 2));

    MatrixCalculator matrix1, matrix2;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);

    EXPECT_ANY_THROW(matrix1 - matrix2);
}

TEST(MatrixCalculatorTest, operator_multiply_error_with_wrong_size) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(2, 1));
    std::vector<std::vector<double>> vect2(3, std::vector<double>(2, 2));

    MatrixCalculator matrix1, matrix2;
    matrix1.SetMatrix(vect1);
    matrix2.SetMatrix(vect2);

    EXPECT_ANY_THROW(matrix1 * matrix2);
}

TEST(MatrixCalculatorTest, correct_determinant) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 3, 4 } };
    double real_res = -2;

    MatrixCalculator matrix1;
    matrix1.SetMatrix(vect);

    EXPECT_EQ(matrix1.determinant(), real_res);
}

TEST(MatrixCalculatorTest, correct_determinant_with_zero_row) {
    std::vector<std::vector<double>> vect = {
    { 1, 2, 5 },
    { 0, 0, 0 },
    { 5, 3, 1 } };
    double real_res = 0.0;

    MatrixCalculator matrix1;
    matrix1.SetMatrix(vect);

    EXPECT_EQ(matrix1.determinant(), real_res);
}

TEST(MatrixCalculatorTest, determinant_error_with_not_square_matrix) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 1, 3 },
    { 3, 4 } };

    MatrixCalculator matrix1;
    matrix1.SetMatrix(vect);

    EXPECT_ANY_THROW(matrix1.determinant());
}

TEST(MatrixCalculatorTest, inverse_error_with_not_square_matrix) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 1, 3 },
    { 3, 4 } };

    MatrixCalculator matrix1;
    matrix1.SetMatrix(vect);

    EXPECT_ANY_THROW(matrix1.InverseMatrix());
}

TEST(MatrixCalculatorTest, inverse_error_with_zero_determinant) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 1, 2 } };

    MatrixCalculator matrix1;
    matrix1.SetMatrix(vect);

    EXPECT_ANY_THROW(matrix1.InverseMatrix());
}

TEST(MatrixCalculatorTest, correct_inverse) {
    std::vector<std::vector<double>> vect1 = {
    { 1, 2 },
    { 1, 3 } };
    std::vector<std::vector<double>> vect2 = {
    { 3, -2 },
    { -1, 1 } };

    MatrixCalculator matrix1, real_res;
    matrix1.SetMatrix(vect1);
    real_res.SetMatrix(vect2);

    EXPECT_EQ(matrix1.InverseMatrix(), real_res);
}
