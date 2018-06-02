// Copyright 2018 Fedorova Olga

#include "include/matrix_calculator.h"
#include <iostream>
#include <cmath>
#include <cstddef>
#include <vector>
using matrix_type = std::vector<std::vector<double>>;

MatrixCalculator::MatrixCalculator() {
    matrix = std::vector<std::vector<double > >
        (1, std::vector<double>(1, 0.0));
}

MatrixCalculator::MatrixCalculator(const int rows, const int columns) {
    if (rows < 0 || columns < 0) {
        throw "Enter positive integer numbers";
    }

    matrix = std::vector<std::vector<double > >(rows,
        std::vector<double>(columns, 0.0));
}

MatrixCalculator::MatrixCalculator(const MatrixCalculator& _matrix) {
    matrix = _matrix.matrix;
}

void MatrixCalculator::SetMatrix(matrix_type &_vector) {
    for (size_t i = 1; i < _vector.size(); i++) {
        if (_vector[i - 1].size() != _vector[i].size()) {
            throw "Size of columns should be the same";
        }
    }

    matrix = _vector;
}

bool MatrixCalculator::operator==(const MatrixCalculator& _matrix) const {
    return matrix == _matrix.matrix;
}

bool MatrixCalculator::AreSizesEqual(const MatrixCalculator& _matrix) const {
    bool result = false;

    if ((matrix.size() == _matrix.matrix.size()) &&
        (matrix[0].size() == _matrix.matrix[0].size())) {
        result = true;
    }

    return result;
}

MatrixCalculator& MatrixCalculator::operator=
    (const MatrixCalculator& _matrix) {
    matrix = _matrix.matrix;

    return *this;
}

MatrixCalculator MatrixCalculator::operator+
    (const MatrixCalculator& _matrix) const {
    MatrixCalculator result(*this);

    if (!AreSizesEqual(_matrix)) {
        throw "Sizes are not equal";
    } else {
         for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                result.matrix[i][j] = matrix[i][j] + _matrix.matrix[i][j];
            }
         }
    }
    return result;
}

MatrixCalculator MatrixCalculator::operator-
    (const MatrixCalculator& _matrix) const {
    MatrixCalculator result(*this);

    if (!AreSizesEqual(_matrix)) {
        throw "Sizes are not equal";
    } else {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                result.matrix[i][j] = matrix[i][j] - _matrix.matrix[i][j];
            }
        }
    }

    return result;
}

MatrixCalculator MatrixCalculator::operator*
           (const MatrixCalculator& _matrix) const {
    if (matrix[0].size() != _matrix.matrix.size()) {
        throw "Size of rows should be equal to size of columns";
    } else {
        MatrixCalculator result(matrix.size(), _matrix.matrix[0].size());

        for (size_t i = 0; i < result.matrix.size(); i++) {
            for (size_t j = 0; j < result.matrix[i].size(); j++) {
                for (size_t k = 0; k < _matrix.matrix.size(); k++) {
                    result.matrix[i][j] += this->matrix[i][k]
                        * _matrix.matrix[k][j];
                }
            }
        }
        return result;
    }
}

double MatrixCalculator::determinant() const {
    if (matrix.size() != matrix[0].size()) {
        throw "Matrix should be squard";
    }

    double tmp, det = 1;
    MatrixCalculator temp(*this);
    int matrixsize = temp.matrix.size();

    for (size_t i = 0; i < (size_t)matrixsize; i++) {
        int t = i + 1;
        while ((temp.matrix[i][i] == 0) && (t < matrixsize)) {
            if (temp.matrix[t][i] != 0) {
                temp.matrix[i].swap(temp.matrix[t]);
                det *= -1;
            }
            ++t;
        }
        if (temp.matrix[i][i] == 0) {
            det = 0;
            break;
        }
        for (size_t j = i + 1; j < (size_t)matrixsize; ++j) {
            tmp = temp.matrix[j][i] / temp.matrix[i][i];
            for (size_t k = i; k < temp.matrix.size(); k++) {
                temp.matrix[j][k] -= temp.matrix[i][k] * tmp;
            }
        }
        det *= temp.matrix[i][i];
    }
    return det;
}

MatrixCalculator MatrixCalculator::InverseMatrix() const {
    if (this->determinant() == 0) {
        throw "Determinant must not be equal to zero";
    }

    MatrixCalculator inverse_matrix(*this);
    double det = this->determinant();

    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix.size(); j++) {
            int m = matrix.size() - 1;
            MatrixCalculator temp(m, m);
            temp = temp.Prepare_for_minores(m, matrix, i, j);
            inverse_matrix.matrix[i][j] = pow(-1.0, i + j + 2)
                  * temp.determinant() / det;
        }
    }

    inverse_matrix = inverse_matrix.Transpon(matrix.size());

    return inverse_matrix;
}

MatrixCalculator MatrixCalculator::Prepare_for_minores(int n,
    matrix_type _matr, int indRow, int indCol) const {
    MatrixCalculator temp(n, n);
    int ki = 0;
    for (size_t i = 0; i < (size_t)n+1; i++) {
        if (i != (size_t)indRow) {
            for (size_t j = 0, kj = 0; j < (size_t)n+1; j++) {
                if (j != (size_t)indCol) {
                    temp.matrix[ki][kj] = _matr[i][j];
                    kj++;
                }
            }
            ki++;
        }
    }
    return temp;
}

MatrixCalculator MatrixCalculator::Transpon(int n) const {
    MatrixCalculator temp(*this);;

    for (size_t i = 0; i < (size_t)n; i++)
        for (size_t j = 0; j < (size_t)n; j++)
            temp.matrix[j][i] = matrix[i][j];

    return temp;
}
