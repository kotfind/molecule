#include "Matrix.h"

Matrix Matrix::unit(const size_t& n) {
    Matrix ans(n);
    for (size_t i = 0; i < n; ++i) {
        ans[i][i] = 1;
    }
    return ans;
}
