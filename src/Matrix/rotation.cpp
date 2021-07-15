#include "Matrix.h"

Matrix Matrix::xrotation(const double& angle) {
    return Matrix(
        {{1,    0,            0     },
         {0, cos(angle), -sin(angle)},
         {0, sin(angle),  cos(angle)}});
}

Matrix Matrix::yrotation(const double& angle) {
    return Matrix(
        {{ cos(angle), 0, sin(angle)},
         {      0,     1,      0    },
         {-sin(angle), 0, cos(angle)}});
}

Matrix Matrix::zrotation(const double& angle) {
    return Matrix(
        {{cos(angle), -sin(angle), 0},
         {sin(angle),  cos(angle), 0},
         {    0,           0,      1}});
}
