#ifndef MATRIX_H
#define MATRIX_H

#include "../vec/vec.h"

#include <vector>
#include <cassert>

class Matrix : public std::vector<std::vector<double>> {
    public:
        Matrix(const vec& v);
        Matrix(const size_t& n, const size_t& m);
        Matrix(const size_t& n);
        Matrix(const std::vector<std::vector<double>>& m);

        static Matrix unit(const size_t& n);
        static Matrix xrotation(const double& angle);
        static Matrix yrotation(const double& angle);
        static Matrix zrotation(const double& angle);

        Matrix& operator=(const Matrix& rhs);
        Matrix& operator*=(const Matrix& rhs);

        operator vec();
};

Matrix operator*(const Matrix& lhs, const Matrix& rhs);

#endif
