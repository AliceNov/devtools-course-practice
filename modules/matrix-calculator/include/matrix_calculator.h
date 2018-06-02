// Copyright 2018 Fedorova Olga

#ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
#define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_

#include <vector>
using matrix_type = std::vector<std::vector<double>>;

class MatrixCalculator {
 public:
    MatrixCalculator();
    MatrixCalculator(const int rows, const int columns);
    MatrixCalculator(const MatrixCalculator&);

    void SetMatrix(matrix_type&);

    MatrixCalculator operator+(const MatrixCalculator&) const;
    MatrixCalculator operator-(const MatrixCalculator&) const;
    MatrixCalculator operator*(const MatrixCalculator&) const;
    MatrixCalculator& operator=(const MatrixCalculator&);

    double determinant() const;
    MatrixCalculator InverseMatrix() const;

    bool operator==(const MatrixCalculator&) const;
    bool AreSizesEqual(const MatrixCalculator&) const;
    matrix_type matrix;
    MatrixCalculator Prepare_for_minores(int, matrix_type, int, int) const;
    MatrixCalculator Transpon(int a) const;
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
