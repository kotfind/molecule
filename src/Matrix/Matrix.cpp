#include "Matrix.h"

#include <cassert>

Matrix::Matrix(const vec& v)
    : Matrix(std::vector<std::vector<double>>{{v.x}, {v.y}, {v.z}}) {}

Matrix::Matrix(const size_t& n)
    : Matrix(n, n) {}

Matrix::Matrix(const size_t& n, const size_t& m)
    : Matrix(std::vector<std::vector<double>>(n, vector<double>(m))) {}

Matrix::Matrix(const std::vector<std::vector<double>>& m) {
    resize(m.size());
    for (size_t i = 0; i < m.size(); ++i) {
        assert(m[i].size() == m[0].size());
        (*this)[i].resize(m[0].size());
        for (size_t j = 0; j < m[0].size(); ++j) {
            (*this)[i][j] = m[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& m) 
    : std::vector<std::vector<double>>() {
    *this = m;
}

Matrix& Matrix::operator=(const Matrix& m) {
    resize(m.size());
    for (size_t i = 0; i < m.size(); ++i) {
        (*this)[i].resize(m[0].size());
        for (size_t j = 0; j < m[0].size(); ++j) {
            (*this)[i][j] = m[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs) {
    *this = *this * rhs;
    return *this;
}

Matrix::operator vec() {
    assert(size() == 3 && (*this)[0].size() == 1);
    return {(*this)[0][0], (*this)[1][0], (*this)[2][0]};
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    assert(lhs.size() == rhs.size() && lhs[0].size() == rhs[0].size());
    for (size_t i = 0; i < lhs.size(); ++i) {
        for (size_t j = 0; j < lhs[0].size(); ++j) {
            if (lhs[i][j] != rhs[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[0].size(); ++j) {
            out << m[i][j] << ' ';
        }
        if (i + 1 != m.size()) {
            out << '\n';
        }
    }
    return out;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    assert(lhs[0].size() == rhs.size());
    const size_t n = lhs.size();
    const size_t m = rhs[0].size();
    const size_t l = rhs.size();
    std::vector<std::vector<double>> ans(n, std::vector<double>(m, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            for (size_t k = 0; k < l; ++k) {
                ans[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return ans;
}
